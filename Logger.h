#ifndef LOGGER_H
#define LOGGER_H

#include <Vehicle.h>
#include <iostream>
#include <ctime>
#include <chrono>
using namespace std;
class VehicleLog
{
private:
    time_t m_start_time; // Entry time of the Vehicle
    time_t m_end_time;   // Exit time of the Vehicle
    Vehicle *m_vehicle;  // Pointer to Vehicle Object

public:
    // Parameterized Constructor 1
    VehicleLog(time_t start_time, Vehicle *&v) : m_start_time{start_time}, m_end_time{-1}, m_vehicle{v}
    {
    }

    // Parameterized Constructor 2
    VehicleLog(time_t start_time, time_t end_time, Vehicle *&v) : m_start_time{start_time}, m_end_time{end_time}, m_vehicle{v}
    {
    }

    void setStart()
    {
        m_start_time = time(NULL);
    }

    void setEnd()
    {
        m_end_time = time(NULL);
    }

    string getPlate() const
    {
        return m_vehicle->getPlate();
    }

    int getSize() const
    {
        return m_vehicle->getSize();
    }

    time_t getStart() const
    {
        return m_start_time;
    }
    time_t getEnd() const
    {
        return m_end_time;
    }

    time_t time_spent() const
    {
        if (m_end_time == -1)
        {
            return -1;
        }
        else
        {
            return m_end_time - m_start_time;
        }
    }

    void describe()
    {
        if (m_end_time == -1)
        {
            cout << "Vehicle License Plate : " << m_vehicle->getPlate() << "\n";
            cout << "Vehicle Entry Time : " << ctime(&m_start_time) << endl;
        }
        else
        {
            cout << "Vehicle License Plate : " << m_vehicle->getPlate() << "\n";
            cout << "Vehicle Entry Time : " << ctime(&m_start_time) << endl;
            cout << "Vehicle Exit Time : " << ctime(&m_end_time) << endl;
        }
    }
};

#endif