#include "../inc/main.hpp"

Base* generate( void )
{
    std::srand(std::time(0));
    int r = std::rand() % 3;

    if (r == 0)
        return new A;
    else if (r == 1)
        return new B;
    else
        return new C;
}

void identify( Base* p )
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}

void identify( Base& p )
{
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    } catch (...) {}

    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    } catch (...) {}

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    } catch (...) {}
}

int main()
{
    Base* ptr = generate();

    std::cout << "Identification with pointer:" << std::endl;
    identify(ptr);

    std::cout << "Identification with reference:" << std::endl;
    identify(*ptr);

    delete ptr;
    return 0;
}