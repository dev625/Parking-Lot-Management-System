#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include <iostream>
using namespace std;

class Vehicle
{
protected:
    int m_size;           // Type of the Vehicle
    string m_numberPlate; // License Plate of the Vehicle

public:
    // Parameterized Constructor
    Vehicle(int size, string numberPlate)
    {
        m_size = size;
        m_numberPlate = numberPlate;
    }

    // Copy Constructor
    Vehicle(const Vehicle &p)
    {
        m_size = p.m_size;
        m_numberPlate = p.m_numberPlate;
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