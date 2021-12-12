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

    // Function to Describe the Vehicle Object
    // Virtual Function Concept
    virtual void describe() const
    {
        cout << "My size is " << m_size << " and my license plate is " << m_numberPlate << ".\n";
    }

    // Function to Return the Vehicle Size
    int getSize() const
    {
        return m_size;
    }

    // Function to Return the License Plate of the User
    string getPlate() const
    {
        return m_numberPlate;
    }
};

class Bike : public Vehicle
{
public:
    // Constructor for Bike Class and Calling the Base Class Constructor
    Bike(string number_plate) : Vehicle(1, number_plate)
    {
    }
    virtual void describe() const
    {
        cout << "This vehicle is a Bike with size 1 and license plate " << m_numberPlate << ".\n";
    }
};

class Car : public Vehicle
{
    // Constructor for Car Class and Calling the Base Class Constructor
public:
    Car(string number_plate) : Vehicle(2, number_plate)
    {
    }
    virtual void describe() const
    {
        cout << "This vehicle is a Car with size 2 and license plate " << m_numberPlate << ".\n";
    }
};

class Bus : public Vehicle
{
    // Constructor for Bus Class and Calling the Base Class Constructor
public:
    Bus(string number_plate) : Vehicle(3, number_plate)
    {
    }
    virtual void describe() const
    {
        cout << "This vehicle is a Bus with size 3 and license plate " << m_numberPlate << ".\n";
    }
};

#endif