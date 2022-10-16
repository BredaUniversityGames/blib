
#include <iostream>
#include "blib_ec.h"
#include "blib_fileio.h"

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

    /*------------------*/
    /*      File IO     */
    /*------------------*/
    std::string filename = "binary_testFile.txt";
    uint32_t a = 25000;

    // Binary writing
    {
        // Write to file
        std::vector<char> data{};
        for (size_t i = 0; i < 4; i++)
            data.push_back(*(reinterpret_cast<char*>(&a) + i));

        blib::io::write_binary_file(data, filename);

        // Read from file
        if (blib::io::exists(filename))
        {
            std::vector<char> data = blib::io::read_binary_file(filename);
            if (data.size() > 0)
            {
                uint32_t reconstructed_value = 0;
                for (size_t i = 0; i < 4; i++)
                    *(reinterpret_cast<char*>(&reconstructed_value) + i) = data[i];

                printf("\nRead value from file: %u\n", reconstructed_value);
            }
        }
    }

    // Text writing
    {
        filename = "text_TestFile.txt";

        std::string text = "Blib file io write_text_file() test";
        blib::io::write_text_file(text, filename);

        if (blib::io::exists(filename))
        {
            std::string read_text = blib::io::read_text_file(filename);
            printf("Read Text: \"%s\"\n", read_text.c_str());
        }
    }
}
