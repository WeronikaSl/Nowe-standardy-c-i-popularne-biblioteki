#include <iostream>

class A
{
private:
    std::string _str = {};
public:
    A(std::string str) : _str(str)
    {
    }
    A(A&& other) noexcept
    {
        this->_str = std::move(other._str);
    }
    A operator=(A&& other) noexcept
    {
        this->_str = std::move(other._str);
    }

};

void swapOld(int& a, int& b)
{
    int temp(a); // tutaj wolamy konstruktor kopiujacy, mamy teraz 2 kopie a 
    a = b;
    b = temp;
}

void swapMove(int& a, int& b)
{
    int temp(std::move(a)); //jawnie zadamy zamiany obiektu na rvalue ref, nie robi sie kopia, 
    //od teraz nie wolno odwoływac się do wartości a
    a = std::move(b);
    b = std::move(temp);
}

int main()
{
    A a("Hi");
    A& a_ref = a;
    A&& ref = A("Hello");
}