
#include <iostream>
#include "blib_ec.h"
#include "blib_math.h"

class transform : public blib::component
{
public:
    transform(int x, int y) : x(x), y(y) {}
    int x;
    int y;
};

class timer : public blib::component
{
public:
    timer() : t(0.0f) {}
    void update(float dt) override { t += dt; }
    float get_t() const { return t; }

private:
    float t;
};

class random_spawner : public blib::component
{
public:
    random_spawner() {}
    void update(float dt) override;
private:
};

int main()
{    
    blib::entity_container ec;
    auto& e = ec.create();    
    e.set_name("de entity");
    std::cout << "e.valid = " << e.valid() << std::endl;
    
    auto& t = e.create_component<transform>(41, 41);
    std::cout << "t = [" << t.x << ", " << t.y << "]" << std::endl;

    t.x = 63;
    t.y = 89;
    std::cout << "t = [" << t.x << ", " << t.y << "]" << std::endl;

    blib::entity invalid_entity;
    std::cout << "invalid_entity.valid = " << invalid_entity.valid() << std::endl;

    blib::entity_id invalid_id;
    // auto& error_entity = ec.get(invalid_id);    // This will result in a run time error! 
    // std::cout << "e0.valid = " << error_entity.valid() << std::endl;

    auto* error_entity_ptr = ec.try_get(invalid_id);
    if(error_entity_ptr)
        std::cout << "error_entity_ptr->valid = " << error_entity_ptr->valid() << std::endl;

    auto e_id = e.id();
    auto& e_again = ec.get(e_id);
    std::cout << "e_again.name() = " << e_again.name() << std::endl;

    auto& tm = e_again.create_component<timer>();
    e_again.update(1.0f);
    ec.update(1.0f);
    std::cout << "tm.get_t() = " << tm.get_t() << std::endl;

    auto& t_again = e_again.get_component<transform>();
    std::cout << "t_again = [" << t_again.x << ", " << t_again.y << "]" << std::endl;

    e_again.destroy_component<transform>();
    auto* t_again_ptr = e_again.try_get_component<transform>();
    if (t_again_ptr)
        std::cout << "t_again_ptr = [" << t_again_ptr->x << ", " << t_again_ptr->y << "]" << std::endl;

    ec.destroy(e_again.id());
    ec.update(0.0f);

    auto* not_here_entity_ptr = ec.try_get(e_id);
    if (t_again_ptr)
        std::cout << "not_here_entity_ptr.valid = " << not_here_entity_ptr->valid() << std::endl;

    // Dot product
    blib::vec3 vec0(15.0f, 89.4961230f, 0.7129837f);
    blib::vec3 vec1(-7.81234f, 0.12f, 19.879f);
    float dot0 = blib::dot(vec0, vec1);

    // Length
    float length0 = blib::length(vec0);
    float length1 = blib::length(vec1);

    // Normalize
    blib::vec3 norm0 = blib::normalize(vec0);
    blib::vec3 norm1 = blib::normalize(vec1);

    // Cross product
    vec0 = blib::vec3(0.0f, 1.0f, 0.0f);
    vec1 = blib::vec3(1.0f, 0.0f, 0.0f);
    blib::vec3 cross0 = blib::cross(vec0, vec1);
    blib::vec3 cross1 = blib::cross(norm0, norm1);

    blib::mat4 identity = blib::mat4();
    blib::mat4 perspectiveOpenGL = blib::perspective(blib::radians(60.0f), 1.0f, 0.1f, 1000.0f);
    blib::mat4 perspectiveDirectX = blib::perspectiveLH_ZO(blib::radians(60.0f), 1.0f, 0.1f, 1000.0f);

    std::cin.get();
}
