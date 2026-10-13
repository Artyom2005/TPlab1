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
              double maxUnderwaterSpeed, double maxSurfaceSpeed, String armanent);
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
    String &getArmanent() const;

    // сеттеры
    void setLength(double val);
    void setWidth(double val);
    void setCrew(int val);
    void setUnderwaterTime(double val);
    void setMaxUnderwaterSpeed(double val);
    void setMaxSurfaceSpeed(double val);
    void setArmanent(const String &str);
};