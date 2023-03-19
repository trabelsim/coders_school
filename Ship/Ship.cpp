#include "Ship.h"
#include <iostream>
#include <algorithm>


Ship::Ship()
{
    // default wrong value
    id_ = -1;
}

Ship::Ship(int id, std::string name, int speed, unsigned maxCrew, unsigned capacity)
: id_(id),
name_(name),
speed_(speed),
maxCrew_(maxCrew),
capacity_(capacity)
{

}

Ship::Ship(int id, int speed, unsigned maxCrew) : Ship(id, "Default", speed, maxCrew, 0)
{
}

Ship::~Ship()
{
}

int Ship::getId()
{
    return id_;
}

std::string Ship::getName()
{
    return name_;
}

int Ship::getSpeed()
{
    return speed_;
}

size_t Ship::getCrew()
{
    return crew_;
}

unsigned Ship::getMaxCrew()
{
    return maxCrew_;
}

unsigned Ship::getCapacity()
{
    return capacity_;
}

void Ship::setName(const std::string & name)
{
    if(name.length() > 0)
    {
        name_ = name;
    }
}

Ship &Ship::operator+=(const int amount)
{
    if(amount + crew_ <= maxCrew_)
    {
        crew_ += amount;
    }
    else
    {
        std::cout << "Cannot add " << amount << " to crew. Used crew "<< crew_ <<". MaxCrew size: " << maxCrew_ << std::endl;
    }
    
    return *this;
}

Ship &Ship::operator-=(const int amount)
{
    if(crew_ - amount >= 0)
    {
        crew_ -= amount;
    }
    else
    {
        std::cout << "Cannot remove " << amount << " from crew (too big value). Used crew "<< crew_ << std::endl;
    }
    
    return *this;
}

Ship &Ship::addCargo(const Cargo &cargo)
{
    if(cargo.getAmount() >= getCapacity())
    {
        std::cout << "Cargo " << cargo.getName() << " is too big: " << cargo.getAmount() << " for the ship capacity " << getCapacity() << std::endl;
    }
    else
    {
        capacity_ -= cargo.getAmount();
        cargoLoad.push_back(cargo);
    }
    
    return *this;
}

Ship &Ship::removeCargo(const Cargo &cargo)
{
    if(!cargoLoad.empty())
    {
        for(auto && cargoObj : cargoLoad)
        {
            auto it = std::find(cargoLoad.begin(), cargoLoad.end(), cargo);
            if(it != cargoLoad.end())
            {
                std::cout << "Removed cargo " << cargoObj.getName() << "from " << getName() << std::endl;
                capacity_ += cargoObj.getAmount();
                cargoLoad.erase(it);
            }
        }
    }

    return *this;
}


void Ship::printCargosStats()
{
    std::cout << "CARGO LOAD for ship " << getName() << "|Capacity left: " << getCapacity() << std::endl;
    if(cargoLoad.empty())
    {
        std::cout << "EMPTY" << std::endl;
        return;
    }

    for(auto && cargoObj: cargoLoad)
    {
        std::cout << cargoObj.getName() << " |Amount: " << cargoObj.getAmount() << " |BasePrice:" << cargoObj.getBasePrice() << std::endl;
    }
}

void Ship::printShipStats()
{
    std::cout << "Ship ID:" << getId() << std::endl;
    std::cout << "Ship name:" << getName() << std::endl;
    std::cout << "Ship speed:" << getSpeed() << std::endl;
    std::cout << "Ship crew:" << getCrew() << std::endl;
    std::cout << "Ship max crew:" << getMaxCrew() << std::endl;
    std::cout << "Ship capacity:" << getCapacity() << std::endl;
    std::cout << std::endl;

}