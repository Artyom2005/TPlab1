#include "Ship.h"
#include <iostream>
#include "utils/String.h"

using namespace std;

Ship::Ship()
{
    cout << "Вызван базовый конструктор кораблей\n";
}

Ship::Ship(const Ship &obj)
{
    cout << "Вызван базовый конструктор копирования\n";
}

Ship::~Ship()
{
    cout << "Вызван базовый деструктор\n";
}

Ship &Ship::operator=(const Ship &obj)
{
    return *this;
}

bool Ship::operator==(const Ship &obj) const
{
    return getType() == obj.getType() && equals(obj);
}

bool Ship::operator!=(const Ship &obj) const
{
    return !(*this == obj);
}

ostream &operator<<(std::ostream &os, const Ship &obj)
{
    obj.print(os);
    return os;
}

istream &operator>>(std::istream &is, Ship &obj)
{
    obj.input();
    return is;
}
