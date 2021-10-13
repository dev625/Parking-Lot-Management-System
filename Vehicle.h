#include <string>
#include <iostream>
class Vehicle
{
private:
    int m_size;
    std::string m_numberPlate;

public:
    Vehicle(int size, std::string numberPlate)
    {
        m_size = size;
        m_numberPlate = numberPlate;
    }

    void describe()
    {
        std::cout << "My size is " << m_size << " and my license plate is " << m_numberPlate << "\n";
    }
};