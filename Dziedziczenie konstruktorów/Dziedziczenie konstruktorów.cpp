#include <iostream>

class Dog
{
protected:
    unsigned short _paws = 0;
    unsigned short _tail = 0;
    std::string _name = {};
    Dog(unsigned short paws, unsigned short tail, std::string name) : _paws(paws), _tail(tail), _name(name)
    {}
public:
    Dog(std::string name) : Dog(4, 1, name)
    {}
    unsigned short getPaws() const
    {
        return _paws;
    }
    unsigned short getTail() const
    {
        return _tail;
    }
    std::string getName() const
    {
        return _name;
    }

};

class LittleDog : public Dog
{
    using Dog::Dog;
};

int main()
{
    LittleDog ld("Rex");
    std::cout << ld.getPaws() << std::endl;
}
