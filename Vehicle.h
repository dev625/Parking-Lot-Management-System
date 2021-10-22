#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include <iostream>
using namespace std;

class Vehicle
{
protected:
    int m_size;
    string m_numberPlate;

public:
    // Parameterized Constructor
    Vehicle(int size, string numberPlate)
    {
        m_size = size;
        m_numberPlate = numberPlate;
    }

    void describe() const
    {
        cout << "My size is " << m_size << " and my license plate is " << m_numberPlate << "\n";
    }

    int getSize() const
    {
        return m_size;
    }

    string getPlate() const
    {
        return m_numberPlate;
    }
};

#endif