#include <iostream>

class K
{
private:
    int _a = 0;
public:
    K()
    {
        std::cout << "Konstruktor bezparametrowy" << std::endl;
    }

    K (int a) : _a(a)
    {
        std::cout << "Konstruktor parametrowy" << std::endl;

    }

    K(const K& other) //konstruktor kopiujacy
    {
        std::cout << "Konstruktor kopiujacy" << std::endl;
        this->_a = other._a;
    }

    K(K&& other) noexcept //konstruktor przenoszacy
    {
        std::cout << "Konstruktor przenoszacy" << std::endl;
        this->_a = std::move(other._a);
    }

    int getA() const
    {
        return _a;
    }
};

int main()
{
    K x(5);
    K y(std::move(x));

    std::cout
        << "a od x: " << x.getA() << std::endl //tu nic nie ma, zostalo przeniesione do b, nie powinno się nic na tym obiekcie robic
        << "a od y: " << y.getA() << std::endl;

}
