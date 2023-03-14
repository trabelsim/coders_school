#include <iostream>
#include "Ship.h"

void printShipStats(Ship shipObj);

int main()
{
    std::cout << "Welcome" << std::endl;

    Ship shipObj;
    shipObj.setName("Pierwszy statek");
    printShipStats(shipObj);

    Ship shipObj2 = Ship(1, 100, 150);
    printShipStats(shipObj2);

    Ship shipObj3 = Ship(2, "ShipThree", 100, 150, 2000);
    printShipStats(shipObj3);

    return 0;
}

void printShipStats(Ship shipObj)
{
    std::cout << "Ship ID:" << shipObj.getId() << std::endl;
    std::cout << "Ship name:" << shipObj.getName() << std::endl;
    std::cout << "Ship speed:" << shipObj.getSpeed() << std::endl;
    std::cout << "Ship crew:" << shipObj.getMaxCrew() << std::endl;
    std::cout << "Ship capacity:" << shipObj.getCapacity() << std::endl;
    std::cout << std::endl;

}