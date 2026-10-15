#pragma once
#include "Ship.h"
#include "String.h"

// Парусник
class Sailboat : public Ship
{
    String sailType;
    String name;
    bool military;
    double hullLength;
    double speed;
    int crew;

public:
    Sailboat();
    Sailboat(const String &sailType, const String &name, bool military,
             double hullLength, double speed, int crew);
    Sailboat(const Sailboat &other);
    virtual ~Sailboat();
    Sailboat &operator=(const Sailboat &other);

    // get
    const String &getSailType() const;
    const String &getName() const;
    bool isMilitary() const;
    double getHullLength() const;
    double getSpeed() const;
    int getCrew() const;
    // set
    void setSailType(const String &v);
    void setName(const String &v);
    void setMilitary(bool v);
    void setHullLength(double v);
    void setSpeed(double v);
    void setCrew(int v);

    int getType() const override;
    String getTypeName() const override;
    void print(std::ostream &os) const override;
    void input() override;
    void edit() override;
    void save(std::ostream &os) const override;
    void load(std::istream &is) override;
    Ship *clone() const override;
    bool equals(const Ship &other) const override;
};
