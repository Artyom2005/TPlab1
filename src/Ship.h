#pragma once
#include <iostream>
#include "utils/String.h"

enum ShipType
{
    SUBMARINE = 1,
    SAILBOAT = 2,
    MOTORBOAT = 3
};

class Ship
{
public:
    Ship();
    Ship(const Ship &obj);
    Ship &operator=(const Ship &obj);

    virtual ~Ship();

    virtual int getType() const = 0;
    virtual String getTypeName() const = 0;
    virtual void print(std::ostream &os) const = 0;
    virtual void input() = 0;
    virtual void edit() = 0;
    virtual void save(std::ostream &os) const = 0;
    virtual void load(std::istream &is) const = 0;
    virtual Ship *clone() const = 0;
    virtual bool equals(const Ship &obj) const = 0;

    bool operator==(const Ship &obj) const;
    bool operator!=(const Ship &obj) const;

    friend std::ostream &operator<<(std::ostream &os, const Ship &obj);
    friend std::istream &operator>>(std::istream &is, Ship &obj);
};