#include "Submarine.h"
#include "utils/Utils.h"
#include "Exceptions.h"
#include "utils/String.h"
#include <iostream>

Submarine::Submarine() : length(0), width(0), crew(0), underwaterTime(0),
                         maxUnderwaterSpeed(0), maxSurfaceSpeed(0), armanent("0")
{
    std::cout << "Создана субмарина без параметров\n";
}

Submarine::Submarine(double lengh, double width, int crew, double underwatertime,
                     double maxUnderwaterSpeed, double maxSurfaceSpeed, const String &armanent)
{
    std::cout << "Создана субмарина с параметрами\n";
    setLength(lengh);
    setWidth(width);
    setCrew(crew);
    setUnderwaterTime(underwaterTime);
    setMaxUnderwaterSpeed(maxUnderwaterSpeed);
    setMaxSurfaceSpeed(maxSurfaceSpeed);
    setArmanent(armanent);
}

Submarine::Submarine(const Submarine &obj) : length(obj.length), width(obj.width), crew(obj.crew),
                                             underwaterTime(obj.underwaterTime), maxUnderwaterSpeed(obj.maxUnderwaterSpeed),
                                             maxSurfaceSpeed(obj.maxSurfaceSpeed), armanent(obj.armanent)
{
    std::cout << "Создана субмарина конструктором копирования\n";
}

Submarine::~Submarine()
{
    std::cout << "Деструктор субмарины\n";
}

Submarine &Submarine::operator=(const Submarine &obj)
{
    if (this != &obj)
    {
        length = obj.length;
        width = obj.length;
        crew = obj.crew;
        underwaterTime = obj.underwaterTime;
        maxUnderwaterSpeed = obj.maxUnderwaterSpeed;
        maxSurfaceSpeed = obj.maxSurfaceSpeed;
        armanent = obj.armanent;
    }
    return *this;
}

double Submarine::getLength() const { return length; }
double Submarine::getWidth() const { return width; }
int Submarine::getCrew() const { return crew; }
double Submarine::getUnderwaterTime() const { return underwaterTime; }
double Submarine::getMaxUnderwaterSpeed() const { return maxUnderwaterSpeed; }
double Submarine::getMaxSurfaceSpeed() const { return maxSurfaceSpeed; }
const String &Submarine::getArmanent() const { return armanent; }

void Submarine::setLength(double val)
{
    if (val < 0)
        throw ValidationException("длина должна быть положительной\n");
    length = val;
}
void Submarine::setWidth(double val)
{
    if (val < 0)
        throw ValidationException("ширина должна быть положительной\n");
    width = val;
}
void Submarine::setCrew(int val)
{
    if (val < 0)
        throw ValidationException("экипаж должна быть положительной\n");
    crew = val;
}
void Submarine::setUnderwaterTime(double val)
{
    if (val < 0)
        throw ValidationException("время пребывания под водой должна быть положительной\n");
    underwaterTime = val;
}
void Submarine::setMaxUnderwaterSpeed(double val)
{
    if (val < 0)
        throw ValidationException("подводная скорость должна быть положительной\n");
    maxUnderwaterSpeed = val;
}
void Submarine::setMaxSurfaceSpeed(double val)
{
    if (val < 0)
        throw ValidationException("надводная скорость должна быть положительной\n");
    maxSurfaceSpeed = val;
}
void Submarine::setArmanent(const String &str)
{
    if (Utils::trim(str).empty())
        throw ValidationException("вооружение не должно быть пустым\n");
}

int Submarine::getType() const { return SUBMARINE; }
String Submarine::getTypeName() const { return "Подводная лодка\n"; }

void Submarine::print(std::ostream &os) const
{
    os << "это подводная лодка. \n"
       << "она длинная: " << length << "м. \n"
       << "она широкая: " << width << "м. \n"
       << "у нее большие лёгкие: " << underwaterTime << "ч. под водой\n"
       << "она быстро плавает под водой: " << maxUnderwaterSpeed << "узлов\n"
       << "и над водой: " << maxSurfaceSpeed << "узлов\n"
       << "она вооружена и опасна: " << armanent << "\n";
}

void Submarine::input()
{
    setLength(Utils::readPositiveDouble("Длина: "));
    setWidth(Utils::readPositiveDouble("Ширина: "));
    setCrew(Utils::readInt("Экипаж: ", 1, 5000));
    setUnderwaterTime(Utils::readPositiveDouble("Время пребывания под водой: "));
    setMaxUnderwaterSpeed(Utils::readPositiveDouble("Максимальная подводная скорость: "));
    setMaxSurfaceSpeed(Utils::readPositiveDouble("Максимальная надводная скорость: "));
    setArmanent(Utils::readNonEmpty("Вооружение: "));
}

void Submarine::edit()
{
    while (true)
    {
        std::cout << "\nизменение подводной лодки:\n"
                  << " 1 - длина\n 2 - ширина\n 3 - экипаж\n"
                  << " 4 - время под водой\n 5 - подводная скорость\n"
                  << " 6 - надводная скорость\n 7 - вооружение\n 0 - назад\n";

        int choice = Utils::readInt("выбор: ", 0, 7);
        if (choice == 0)
        {
            return;
        }

        try
        {
            switch (choice)
            {
            case 1:
            {
                setLength(Utils::readPositiveDouble("Длина: "));
                break;
            }
            case 2:
            {
                setWidth(Utils::readPositiveDouble("Ширина: "));
                break;
            }
            case 3:
            {
                setCrew(Utils::readInt("Экипаж: ", 1, 5000));
                break;
            }
            case 4:
            {
                setUnderwaterTime(Utils::readPositiveDouble("Время под водой: "));
                break;
            }
            case 5:
            {
                setMaxUnderwaterSpeed(Utils::readPositiveDouble("Скорость под водой: "));
                break;
            }
            case 6:
            {
                setMaxSurfaceSpeed(Utils::readPositiveDouble("Скорость над водой: "));
                break;
            }
            case 7:
            {
                setArmanent(Utils::readNonEmpty("Вооружение: "));
                break;
            }
            default:
            {
                std::cout << "Введите адекватное значение";
                break;
            }
                std::cout << "подводная лодка обновилась.";
            }
        }
        catch (const ValidationException &error)
        {
            std::cout << error.what() << "\n";
        }
    }
}

void Submarine::save(std::ostream &os) const
{
    Utils::writeField(os, length);
    Utils::writeField(os, width);
    Utils::writeField(os, crew);
    Utils::writeField(os, underwaterTime);
    Utils::writeField(os, maxUnderwaterSpeed);
    Utils::writeField(os, maxSurfaceSpeed);
    Utils::writeField(os, armanent);
}

void Submarine::load(std::istream &is)
{
    setLength(Utils::readFileDouble(is));
    setWidth(Utils::readFileDouble(is));
    setCrew(Utils::readFileInt(is));
    setUnderwaterTime(Utils::readFileDouble(is));
    setMaxUnderwaterSpeed(Utils::readFileDouble(is));
    setMaxSurfaceSpeed(Utils::readFileDouble(is));
    setArmanent(Utils::readFileLine(is));
}

Ship *Submarine::clone() const
{
    return new Submarine(*this);
}

bool Submarine::equals(const Ship &obj) const
{
    const Submarine &o = static_cast<const Submarine &>(obj);
    return length == o.length && width == o.width && crew == o.crew &&
           underwaterTime == o.underwaterTime && maxUnderwaterSpeed == o.maxUnderwaterSpeed &&
           maxSurfaceSpeed == o.maxSurfaceSpeed && armanent == o.armanent;
}
