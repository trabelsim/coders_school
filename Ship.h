#include <string>

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
    unsigned getMaxCrew();
    unsigned getCapacity();

    void setName(const std::string&);

private:
    int id_ = 0;
    std::string name_ = "";
    int speed_ = 0;
    unsigned maxCrew_ = 0;
    unsigned capacity_ = 0;
};
