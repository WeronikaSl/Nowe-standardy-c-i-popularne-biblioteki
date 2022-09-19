#include <iostream>

template <typename T>
void printMe(T value)
{
    std::cout << value << std::endl; // ten szablon sluzy zatrzymaniu rozwijania parameter pack
}

template <typename T, typename ... Args> // deklaracja szablonu ktory moze przyjac 1 + 0 + argumentów
void printMe(T first, Args ... args) // dla c++ 11 musi byc z tym T first, w pozniejszych moze dzialac bez
{
    std::cout << first << std::endl;//wypisujemy zmienna first, która jest znanego typu T

    printMe(args ...);//nastepnie rozwijamy ten pack poprzez rekurencyjne wywolanie tego szablonu
}



int main()
{
    int a = 10;
    bool b = true;
    float c = 1.14f;
    std::string d = "HI";
    printMe(a, b, c, d, "jeszcze jeden string");
}