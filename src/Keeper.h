#pragma once
#include "Ship.h"
#include "utils/String.h"
#include <iostream>

class Keeper
{
private:
    Ship **items;
    int count;

    void check(int index) const;

public:
    Keeper();
    Keeper(const Keeper *obj);
    ~Keeper();
    Keeper &operator=(const Keeper &obj);

    int size() const;
    void add(Ship *obj);
    void remove(int index);
    void clear();

    Ship &operator[](int index);

    friend std::ostream &operator<<(std::ostream &os, const Keeper &obj);

    void saveToFile(const String &fileName) const;
    void loadFromFile(const String &fileName);

    static Ship *createByType(int type); // Фабрика
};