#pragma once
#include "Ship.h"
#include "utils/String.h"

class Motorboat : public Ship
{
private:
    String purpose;
    String material;
    String hodovKach;
    double speed;
    int capacity;

public:
    Motorboat();
    Motorboat(const String &purpose, const String &material, const String &hodovKach,
              const double speed, const int capacity);
    Motorboat(const Motorboat &obj);

    virtual ~Motorboat();

    Motorboat &operator=(const Motorboat &obj);

    const String &getPurpose() const;
    const String &getMaterial() const;
    const String &getHodovKach() const;
    double getSpeed() const;
    int getCapacity() const;

    void setPurpose(const String &v);
    void setMaterial(const String &v);
    void setHodovKach(const String &v);
    void setSpeed(double v);
    void setCapacity(int v);

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