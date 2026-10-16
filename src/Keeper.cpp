#include "Keeper.h"
#include "Submarine.h"
#include "Sailboat.h"
#include "Motorboat.h"
#include "utils/Utils.h"
#include "utils/String.h"
#include "Exceptions.h"
#include <fstream>
#include <iostream>

Keeper::Keeper() : items(nullptr), count(0)
{
    std::cout << "Конструктор кипер без параметров\n";
}

Keeper::Keeper(const Keeper &obj) : items(nullptr), count(0)
{
    std::cout << "Конструктор копирования кипер\n";
    for (int i = 0; i < obj.count; i++)
    {
        add(obj.items[i]->clone());
    }
}

Keeper::~Keeper()
{
    std::cout << "Деструктор кипера\n";
    clear();
}

Keeper &Keeper::operator=(const Keeper &obj)
{
    if (this != &obj)
    {
        clear();

        for (int i = 0; i < obj.count; i++)
        {
            add(obj.items[i]->clone());
        }
    }
}

int Keeper::size() const
{
    return count;
}

void Keeper::add(Ship *obj)
{
    Ship **temp = new Ship *[count + 1];
    for (int i = 0; i < count; i++)
    {
        temp[i] = items[i];
    }
    temp[count] = obj;
    delete[] items;
    items = temp;
    ++count;
}

void Keeper::check(int index) const
{
    if (index < 0 || index >= count)
    {
        throw ValidationException("нет объекта с таким номером\n");
    }
}

void Keeper::remove(int index)
{
    check(index);
    delete items[index];

    for (int i = index; i < count - 1; i++)
    {
        items[i] = items[i + 1];
    }

    items[count - 1] = nullptr;
    count--;
}

void Keeper::clear()
{
    for (int i = 0; i < count; i++)
    {
        delete items[i];
    }

    delete[] items;
    items = nullptr;
    count = 0;
}

Ship &Keeper::operator[](int index)
{
    check(index);
    return *items[index];
}

std::ostream &operator<<(std::ostream &os, const Keeper &obj)
{
    if (obj.count == 0)
    {
        os << "все пусто.\n";
    }
    for (int i = 0; i < obj.count; i++)
    {
        os << "\nобъект " << (i + 1) << "\n"
           << *obj.items[i] << "----------------------------------\n";
    }

    return os;
}

Ship *Keeper::createByType(int type)
{
    switch (type)
    {
    case SUBMARINE:
    {
        return new Submarine();
        break;
    }
    case SAILBOAT:
    {
        return new Sailboat();
        break;
    }
    case MOTORBOAT:
    {
        return new Motorboat();
        break;
    }
    default:
    {
        throw ValidationException("неизвестный тип объекта");
    }
    }
}

void Keeper::saveToFile(const String &fileName) const
{
    std::ofstream out(fileName.c_str());
    if (!out)
    {
        throw FileException("невозможно открыть файл для записи\n");
    }

    Utils::writeField(out, count);

    for (int i = 0; i < count; i++)
    {
        Utils::writeField(out, items[i]->getType());
        items[i]->save(out);
    }

    if (!out)
    {
        throw FileException("данные не записались в файл\n");
    }
}

void Keeper::loadFromFile(const String &fileName)
{
    std::ifstream in(fileName.c_str());
    if (!in)
    {
        throw FileException("не удалось открыть файл для чтения\n");
    }

    int cnt = Utils::readFileInt(in);
    clear();
    for (int i = 0; i < cnt; i++)
    {
        Ship *pointer = createByType(Utils::readFileInt(in));
        add(pointer);
        pointer->load(in);
    }
}