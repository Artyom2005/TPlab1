#pragma once
#include "Ship.h"
#include "utils/String.h"

class Submarine : public Ship
{
private:
    double length;
    double width;
    int crew;
    double underwaterTime;
    double maxUnderwaterSpeed;
    double maxSurfaceSpeed;
    String armanent;

public:
    Submarine();
    Submarine(double lengh, double width, int crew, double underwatertime,
              double maxUnderwaterSpeed, double maxSurfaceSpeed, const String &armanent);
    Submarine(const Submarine &obj);

    virtual ~Submarine();
    Submarine &operator=(const Submarine &obj);

    // геттеры
    double getLength() const;
    double getWidth() const;
    int getCrew() const;
    double getUnderwaterTime() const;
    double getMaxUnderwaterSpeed() const;
    double getMaxSurfaceSpeed() const;
    const String &getArmanent() const;

    // сеттеры
    void setLength(double val);
    void setWidth(double val);
    void setCrew(int val);
    void setUnderwaterTime(double val);
    void setMaxUnderwaterSpeed(double val);
    void setMaxSurfaceSpeed(double val);
    void setArmanent(const String &str);

    // переопределяем методы базового класса
    int getType() const override;
    String getTypeName() const override;
    void print(std::ostream &os) const override;
    void input() override;
    void edit() override;
    void save(std::ostream &os) const override;
    void load(std::istream &is) override;
    Ship *clone() const override;
    bool equals(const Ship &obj) const override;
};