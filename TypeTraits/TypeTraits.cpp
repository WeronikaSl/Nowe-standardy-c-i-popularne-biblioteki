#include <iostream>
#include <type_traits>

class A
{

};

void fun()
{
    std::cout << "Hi :)" << std::endl;
}

int main()
{
    std::cout << std::is_class<A>::value << std::endl;
    std::cout << std::is_function<decltype(fun)>::value << std::endl;
}
