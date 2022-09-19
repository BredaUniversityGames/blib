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

private:
	entity* m_parent = nullptr;
};

class entity
{
	friend class entity_container;

public:
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

private:
	entity() {}
	entity_id m_id = {};
	std::string m_name = {};
	uint64_t m_tag = {};
	std::vector<std::unique_ptr<component>> m_components;
};

class entity_container
{
public:
	entity& create();
	const entity& get(entity_id id) const;
	entity* try_get(entity_id id);
	entity& get(entity_id id);
	void destroy(entity_id id);
	void update(float dt);
private:
	std::unordered_map<uint64_t, entity> m_entities;
	uint64_t m_next_id = 0;
};


// Implementation



template<class C, typename... Args >
inline C& entity::create_component(Args&&... args)
{
	auto c = std::make_unique<C>(std::forward<Args>(args)...);
	c->m_parent = this;
	auto& ref = m_components.emplace_back(move(c));
	return *(static_cast<C*>(ref.get()));
	//return *static_cast<C*>(m_components.back().get());
}

inline entity& blib::entity_container::create()
{
	entity e;
	e.m_id.id = ++m_next_id;
	m_entities.emplace(++m_next_id, entity());
	return m_entities[e.m_id.id];
}

inline const entity& entity_container::get(entity_id id) const
{
	auto itr = m_entities.find(id.id);
	assert(itr != m_entities.end());
	return itr->second;
}

inline entity* blib::entity_container::try_get(entity_id id)
{
	auto itr = m_entities.find(id.id);
	if(itr != m_entities.end())
		return &itr->second;
	return nullptr;
}


}