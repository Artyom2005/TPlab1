#include "Sailboat.h"
#include "utils/Utils.h"
#include "Exceptions.h"
#include "utils/String.h"
#include <iostream>

using namespace std;

Sailboat::Sailboat()
    : sailType(""), name(""), military(false),
      hullLength(0), speed(0), crew(0)
{
    cout << "Конструктор парусника без параметров\n";
}

Sailboat::Sailboat(const String &sailType, const String &name, bool military,
                   double hullLength, double speed, int crew)
    : military(military), hullLength(0), speed(0), crew(0)
{
    cout << "Конструктор парусника с параметрами\n";
    setSailType(sailType);
    setName(name);
    setHullLength(hullLength);
    setSpeed(speed);
    setCrew(crew);
}

Sailboat::Sailboat(const Sailboat &o)
    : Ship(o), sailType(o.sailType), name(o.name), military(o.military),
      hullLength(o.hullLength), speed(o.speed), crew(o.crew)
{
    cout << "Конструктор копирования парусника\n";
}

Sailboat::~Sailboat()
{
    cout << "Деструктор парусника\n";
}

Sailboat &Sailboat::operator=(const Sailboat &o)
{
    if (this != &o)
    {
        sailType = o.sailType;
        name = o.name;
        military = o.military;
        hullLength = o.hullLength;
        speed = o.speed;
        crew = o.crew;
    }
    return *this;
}

const String &Sailboat::getSailType() const { return sailType; }
const String &Sailboat::getName() const { return name; }
bool Sailboat::isMilitary() const { return military; }
double Sailboat::getHullLength() const { return hullLength; }
double Sailboat::getSpeed() const { return speed; }
int Sailboat::getCrew() const { return crew; }

void Sailboat::setSailType(const String &v)
{
    if (Utils::trim(v).empty())
        throw ValidationException("тип парусника не может быть пустым");
    sailType = Utils::trim(v);
}
void Sailboat::setName(const String &v)
{
    if (Utils::trim(v).empty())
        throw ValidationException("название парусника не может быть пустым");
    name = Utils::trim(v);
}
void Sailboat::setMilitary(bool v) { military = v; }
void Sailboat::setHullLength(double v)
{
    if (v <= 0)
        throw ValidationException("длина корпуса должна быть больше нуля");
    hullLength = v;
}
void Sailboat::setSpeed(double v)
{
    if (v <= 0)
        throw ValidationException("скорость парусника должна быть больше нуля");
    speed = v;
}
void Sailboat::setCrew(int v)
{
    if (v <= 0)
        throw ValidationException("экипаж парусника должен быть больше нуля");
    crew = v;
}

int Sailboat::getType() const { return SAILBOAT; }
String Sailboat::getTypeName() const { return "Парусник"; }

void Sailboat::print(ostream &os) const
{
    os << "Парусник:\n"
       << "  Тип: " << sailType << "\n"
       << "  Название: " << name << "\n"
       << "  Назначение: " << (military ? "военный" : "мирный") << "\n"
       << "  Длина корпуса: " << hullLength << " м\n"
       << "  Скорость: " << speed << " уз\n"
       << "  Экипаж: " << crew << " чел.\n";
}

void Sailboat::input()
{
    setSailType(Utils::readNonEmpty("Тип парусника: "));
    setName(Utils::readNonEmpty("Название: "));
    setMilitary((Utils::readInt("Военный? (1 - да, 0 - нет): ", 0, 1) == 1));
    setHullLength(Utils::readPositiveDouble("Длина корпуса, м: "));
    setSpeed(Utils::readPositiveDouble("Скорость, уз: "));
    setCrew(Utils::readInt("Экипаж, чел.: ", 1, 1000000));
}

void Sailboat::edit()
{
    for (;;)
    {
        cout << "\nИзменение парусника:\n"
             << " 1 - тип\n 2 - название\n 3 - военный/мирный\n"
             << " 4 - длина корпуса\n 5 - скорость\n 6 - экипаж\n 0 - назад\n";
        int c = Utils::readInt("Поле: ", 0, 6);
        if (c == 0)
            return;
        try
        {
            switch (c)
            {
            case 1:
                setSailType(Utils::readNonEmpty("Новый тип: "));
                break;
            case 2:
                setName(Utils::readNonEmpty("Новое название: "));
                break;
            case 3:
                setMilitary((Utils::readInt("Военный? (1 - да, 0 - нет): ", 0, 1) == 1));
                break;
            case 4:
                setHullLength(Utils::readPositiveDouble("Новая длина корпуса, м: "));
                break;
            case 5:
                setSpeed(Utils::readPositiveDouble("Новая скорость, уз: "));
                break;
            case 6:
                setCrew(Utils::readInt("Новый экипаж, чел.: ", 1, 1000000));
                break;
            }
            cout << "Значение изменено.\n";
        }
        catch (const ValidationException &e)
        {
            cout << e.what() << "\n";
        }
    }
}

void Sailboat::save(ostream &os) const
{
    Utils::writeField(os, sailType);
    Utils::writeField(os, name);
    Utils::writeField(os, military ? 1 : 0);
    Utils::writeField(os, hullLength);
    Utils::writeField(os, speed);
    Utils::writeField(os, crew);
}

void Sailboat::load(istream &is)
{
    String st = Utils::readFileLine(is);
    String nm = Utils::readFileLine(is);
    int mil = Utils::readFileInt(is);
    double hl = Utils::readFileDouble(is);
    double sp = Utils::readFileDouble(is);
    int cr = Utils::readFileInt(is);
    if (mil != 0 && mil != 1)
        throw FileException("признак 'военный' должен быть 0 или 1");
    setSailType(st);
    setName(nm);
    setMilitary(mil == 1);
    setHullLength(hl);
    setSpeed(sp);
    setCrew(cr);
}

Ship *Sailboat::clone() const
{
    return new Sailboat(*this);
}

bool Sailboat::equals(const Ship &other) const
{
    const Sailboat &o = static_cast<const Sailboat &>(other);
    return sailType == o.sailType && name == o.name && military == o.military &&
           hullLength == o.hullLength && speed == o.speed && crew == o.crew;
}
