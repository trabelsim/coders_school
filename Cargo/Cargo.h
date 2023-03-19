#pragma once

#include <string>

class Cargo
{
public:
    Cargo();
    Cargo(std::string name, unsigned amount, float basePrice);
    ~Cargo();

    std::string getName() const;
    unsigned getAmount() const;
    float getBasePrice() const;

    Cargo& operator+=(const size_t amount);
    Cargo& operator-=(const size_t amount);

    friend bool operator==(const Cargo &cargo1, const Cargo &cargo2);

private:
    std::string name_ = "";
    unsigned amount_ = 0;
    float basePrice_ = 0;
};