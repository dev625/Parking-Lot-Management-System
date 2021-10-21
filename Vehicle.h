#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include <iostream>

class Vehicle
{
protected:
    int m_size;
    std::string m_numberPlate;

public:
    // Parameterized Constructor
    Vehicle(int size, std::string numberPlate)
    {
        m_size = size;
        m_numberPlate = numberPlate;
    }

    void describe() const
    {
        std::cout << "My size is " << m_size << " and my license plate is " << m_numberPlate << "\n";
    }

    int getSize() const
    {
        return m_size;
    }

    std::string getPlate() const
    {
        return m_numberPlate;
    }
};

#endif