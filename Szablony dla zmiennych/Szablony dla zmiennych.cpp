#include <iostream>

template <typename T>
T var = 55;

template <>
std::string var<std::string> = "Liczba 55 jako napis";

int main()
{
    std::cout << var<int> << std::endl;
    std::cout << var<double> << std::endl;
    std::cout << var<std::string> << std::endl;
}
