
#include <iostream>
#include "blib_ec.h"

class transform : public blib::component
{
public:
    transform(int x, int y) : x(x), y(y) {}
    int x;
    int y;
};

int main()
{
    std::cout << "Hello World!\n";

    blib::entity_container ec;
    auto& e = ec.create();
    auto& t = e.create_component<transform>(1, 4);
    t.x = 1;
    t.y = 2;
}