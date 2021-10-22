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
    time_t m_start_time;
    time_t m_end_time;
    Vehicle *m_vehicle;

public:
    VehicleLog(time_t start_time, Vehicle *&v) : m_start_time{start_time}, m_end_time{-1}, m_vehicle{v}
    {
    }

    void setStart()
    {
        m_start_time = time(0);
    }

    void setEnd()
    {
        m_end_time = time(NULL);
    }

    string getPlate() const
    {
        return m_vehicle->getPlate();
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