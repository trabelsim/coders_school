#include "Cargo.h"
#include <iostream>

Cargo::Cargo()
{
    Cargo("Undefined", 1, 1);
}

Cargo::Cargo(std::string name, unsigned amount, float basePrice) :
    name_(name),
    amount_(amount),
    basePrice_(basePrice)
{
}

Cargo::~Cargo()
{
}

std::string Cargo::getName() const
{
    return name_;
}

unsigned Cargo::getAmount() const
{
    return amount_;
}

float Cargo::getBasePrice() const
{
    return basePrice_;
}

Cargo &Cargo::operator+=(const size_t amount)
{
    amount_ += amount;
    return *this;
}

Cargo &Cargo::operator-=(const size_t amount)
{
    amount_ -= amount;
    return *this;
}


bool operator==(const Cargo &cargo1, const Cargo &cargo2)
{
    if(cargo1.getName() == cargo2.getName())
    {
        if(cargo1.getAmount() == cargo2.getAmount())
        {
            if(cargo1.getBasePrice() == cargo2.getBasePrice())
            {
                return true;
            }
        }
    }

    return false;
}
