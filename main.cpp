#include <iostream>
#include "Ship/Ship.h"
#include "Cargo/Cargo.h"


int main()
{
    std::cout << "Welcome" << std::endl;

    Ship shipObj;
    shipObj.setName("Pierwszy statek");
    shipObj.printShipStats();

    Ship shipObj2 = Ship(1, 100, 150);
    shipObj2.printShipStats();

    Ship shipObj3 = Ship(2, "ShipThree", 100, 150, 2000);
    shipObj3.printShipStats();

    shipObj3 += 150;
    shipObj3 -= 8;
    shipObj3 += 100;

    shipObj3.printShipStats();

    Cargo gold = Cargo("Gold",130, 11.500);
    Cargo silver = Cargo("Silver", 200, 8.500);
    Cargo chickens = Cargo("Chickens", 1850, 10);

    gold += 20;

    chickens -= 1000;

    shipObj3.addCargo(gold);
    shipObj3.addCargo(silver);
    shipObj3.addCargo(chickens);


    shipObj3.printCargosStats();

    return 0;
}