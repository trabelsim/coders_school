#pragma once

#include <string>
#include <vector>
#include "../Cargo/Cargo.h"

class Ship
{
public:
    Ship();
    Ship(int id, std::string name, int speed, unsigned maxCrew, unsigned capacity);
    Ship(int id, int speed, unsigned maxCrew);
    ~Ship();

    //getters
    int getId();
    std::string getName();
    int getSpeed();
    size_t getCrew();
    unsigned getMaxCrew();
    unsigned getCapacity();

    void setName(const std::string&);

    // operatory
    Ship& operator +=(const int);
    Ship& operator -=(const int);

    Ship& addCargo(const Cargo &cargo);
    Ship& removeCargo(const Cargo &cargo);
    void printCargosStats();


    void printShipStats();

private:
    int id_ = 0;
    std::string name_ = "";
    int speed_ = 0;
    size_t crew_ = 0;
    unsigned maxCrew_ = 0;
    unsigned capacity_ = 0;

    std::vector<Cargo> cargoLoad {};
};