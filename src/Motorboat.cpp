#include "Motorboat.h"
#include "utils/Utils.h"
#include "utils/String.h"
#include "Exceptions.h"
#include <iostream>

Motorboat::Motorboat()
    : purpose(""), material(""), hodovKach(""),
      speed(0), capacity(0)
{
    std::cout << "Конструктор катера без параметров\n";
}

Motorboat::Motorboat(const String &purpose, const String &material,
                     const String &hodovKach, double speed, int capacity)
    : speed(0), capacity(0)
{
    std::cout << "Конструктор катера с параметрами\n";
    setPurpose(purpose);
    setMaterial(material);
    setHodovKach(hodovKach);
    setSpeed(speed);
    setCapacity(capacity);
}

Motorboat::Motorboat(const Motorboat &o)
    : Ship(o), purpose(o.purpose), material(o.material),
      hodovKach(o.hodovKach), speed(o.speed), capacity(o.capacity)
{
    std::cout << "Конструктор копирования катера\n";
}

Motorboat::~Motorboat()
{
    std::cout << "Деструктор катера\n";
}

Motorboat &Motorboat::operator=(const Motorboat &o)
{
    if (this != &o)
    {
        purpose = o.purpose;
        material = o.material;
        hodovKach = o.hodovKach;
        speed = o.speed;
        capacity = o.capacity;
    }
    return *this;
}

const String &Motorboat::getPurpose() const { return purpose; }
const String &Motorboat::getMaterial() const { return material; }
const String &Motorboat::getHodovKach() const { return hodovKach; }
double Motorboat::getSpeed() const { return speed; }
int Motorboat::getCapacity() const { return capacity; }

void Motorboat::setPurpose(const String &v)
{
    if (Utils::trim(v).empty())
        throw ValidationException("назначение катера не может быть пустым");
    purpose = Utils::trim(v);
}

void Motorboat::setMaterial(const String &v)
{
    if (Utils::trim(v).empty())
        throw ValidationException("материал корпуса не может быть пустым");
    material = Utils::trim(v);
}

void Motorboat::setHodovKach(const String &v)
{
    if (Utils::trim(v).empty())
        throw ValidationException("ходовые качества не могут быть пустыми");
    hodovKach = Utils::trim(v);
}

void Motorboat::setSpeed(double v)
{
    if (v <= 0)
        throw ValidationException("скорость катера должна быть больше нуля");
    speed = v;
}

void Motorboat::setCapacity(int v)
{
    if (v <= 0)
        throw ValidationException("вместимость катера должна быть больше нуля");
    capacity = v;
}

int Motorboat::getType() const { return MOTORBOAT; }
String Motorboat::getTypeName() const { return "Катер"; }

void Motorboat::print(std::ostream &os) const
{
    os << "Катер:\n"
       << "  Назначение: " << purpose << "\n"
       << "  Материал корпуса: " << material << "\n"
       << "  Ходовые качества: " << hodovKach << "\n"
       << "  Скорость: " << speed << " уз\n"
       << "  Вместимость: " << capacity << " чел.\n";
}

void Motorboat::input()
{
    setPurpose(Utils::readNonEmpty("Назначение: "));
    setMaterial(Utils::readNonEmpty("Материал корпуса: "));
    setHodovKach(Utils::readNonEmpty("Ходовые качества: "));
    setSpeed(Utils::readPositiveDouble("Скорость, уз: "));
    setCapacity(Utils::readInt("Количество людей на борту: ", 1, 1000000));
}

void Motorboat::edit()
{
    for (;;)
    {
        std::cout << "\nИзменение катера:\n"
                  << " 1 - назначение\n 2 - материал корпуса\n 3 - ходовые качества\n"
                  << " 4 - скорость\n 5 - вместимость\n 0 - назад\n";
        int c = Utils::readInt("Поле: ", 0, 5);
        if (c == 0)
            return;
        try
        {
            switch (c)
            {
            case 1:
                setPurpose(Utils::readNonEmpty("Новое назначение: "));
                break;
            case 2:
                setMaterial(Utils::readNonEmpty("Новый материал корпуса: "));
                break;
            case 3:
                setHodovKach(Utils::readNonEmpty("Новые ходовые качества: "));
                break;
            case 4:
                setSpeed(Utils::readPositiveDouble("Новая скорость, уз: "));
                break;
            case 5:
                setCapacity(Utils::readInt("Новая вместимость, чел.: ", 1, 1000000));
                break;
            }
            std::cout << "Значение изменено.\n";
        }
        catch (const ValidationException &e)
        {
            std::cout << e.what() << "\n";
        }
    }
}

void Motorboat::save(std::ostream &os) const
{
    Utils::writeField(os, purpose);
    Utils::writeField(os, material);
    Utils::writeField(os, hodovKach);
    Utils::writeField(os, speed);
    Utils::writeField(os, capacity);
}

void Motorboat::load(std::istream &is)
{
    setPurpose(Utils::readFileLine(is));
    setMaterial(Utils::readFileLine(is));
    setHodovKach(Utils::readFileLine(is));
    setSpeed(Utils::readFileDouble(is));
    setCapacity(Utils::readFileInt(is));
}

Ship *Motorboat::clone() const
{
    return new Motorboat(*this);
}

bool Motorboat::equals(const Ship &other) const
{
    const Motorboat &o = static_cast<const Motorboat &>(other);
    return purpose == o.purpose && material == o.material &&
           hodovKach == o.hodovKach && speed == o.speed && capacity == o.capacity;
}