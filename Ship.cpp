#include "Ship.h"
#include <iostream>


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
