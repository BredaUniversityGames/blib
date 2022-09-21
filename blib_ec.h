// Comment - lic + other info

#pragma once

#include <vector>
#include <string>
#include <memory>
#include <unordered_map>
#include <cassert>

namespace blib
{

class component;
class entity_container;

struct entity_id { uint64_t id = 0; };

class component
{
	friend class entity;

public:	
	virtual void update(float dt) {}

protected:
	entity* m_parent = nullptr;
};

class entity
{
	friend class entity_container;	
	explicit entity(entity_id id) : m_id(id) { }

public:	
	entity() {}
	entity(const entity&) = delete;
	entity(entity&&) = default;
	entity& operator=(const entity&) = delete;
	entity& operator=(entity&&) = default;

	entity_id id() { return m_id; }
	const std::string& name() { return m_name; }
	void set_name(const std::string& name) { m_name = name; }
	uint64_t tag() { return m_tag; }
	void set_tag(uint64_t tag) { m_tag = tag; }

	template<class T, typename... Args>
	T& create_component(Args&&... args);

	template<class T>
	T& get_component();

	template<class T>
	T* try_get_component();

	template<class T>
	void destroy_component();

	bool valid() const { return m_id.id != 0; }
	void update(float dt);

private:	
	entity_id m_id = {};
	std::string m_name = {};
	uint64_t m_tag = {};
	std::vector<std::unique_ptr<component>> m_components;
};

class entity_container
{
public:
	entity& create();
	entity* try_get(entity_id id);
	entity& get(entity_id id);
	void destroy(entity_id id);
	void update(float dt);

private:
	void clean();
	std::unordered_map<uint64_t, entity> m_entities;
	uint64_t m_next_id = 0;
};

////////////////////////////////////////////////////////////////////////////////
//// 
////						Implementation
////
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
////							Entity
////////////////////////////////////////////////////////////////////////////////

template<class C, typename... Args >
inline C& blib::entity::create_component(Args&&... args)
{
	auto c = std::make_unique<C>(std::forward<Args>(args)...);
	c->m_parent = this;
	auto& ref = m_components.emplace_back(move(c));
	return *(static_cast<C*>(ref.get()));
}

template<class T>
inline T& blib::entity::get_component()
{
	T* found = try_get_component<T>();
	assert(found != nullptr);
	return *found;
}

template<class T>
inline T* entity::try_get_component()
{
	for (auto& c : m_components)
	{
		T* found = dynamic_cast<T*>(c.get());
		if (found)
			return found;
	}
	return nullptr;
}

template<class T>
inline void entity::destroy_component()
{
	for (auto it = m_components.begin();  it != m_components.end(); ++it)
	{
		T* found = dynamic_cast<T*>(it->get());
		if (found) {
			m_components.erase(it);
			break;
		}
	}
}

void blib::entity::update(float dt)
{
	for (auto& c : m_components)
		c.get()->update(dt);
}


////////////////////////////////////////////////////////////////////////////////
////						Entity Container
////////////////////////////////////////////////////////////////////////////////

inline entity& blib::entity_container::create()
{
	m_next_id++;
	m_entities.emplace(m_next_id, entity({ m_next_id }));
	return m_entities[m_next_id];
}

inline entity& blib::entity_container::get(entity_id id)
{
	auto itr = m_entities.find(id.id);
	assert(itr != m_entities.end());
	return itr->second;
}

inline void blib::entity_container::update(float dt)
{
	for (auto& e : m_entities)
		if(e.second.valid())
			e.second.update(dt);

	clean();
}

inline void blib::entity_container::clean()
{
	for (auto it = m_entities.begin(); it != m_entities.end();)
		if (!it->second.valid())
			it = m_entities.erase(it);
		else
			++it;
}


inline entity* blib::entity_container::try_get(entity_id id)
{
	auto itr = m_entities.find(id.id);
	if(itr != m_entities.end())
		return &itr->second;
	return nullptr;
}

inline void entity_container::destroy(entity_id id)
{
	auto itr = m_entities.find(id.id);
	if (itr != m_entities.end())
		itr->second.m_id = {};
}

}