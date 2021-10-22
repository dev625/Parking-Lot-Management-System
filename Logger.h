#ifndef LOGGER_H
#define LOGGER_H

#include <Vehicle.h>
#include <iostream>
#include <ctime>
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

    void setStart(time_t start_time)
    {
        m_start_time = start_time;
    }

    void setEnd(time_t end_time)
    {
        m_end_time = end_time;
    }

    string getPlate() const
    {
        return m_vehicle->getPlate();
    }

    void describe()
    {
        if (m_end_time == -1)
        {
            cout << m_vehicle->getPlate() << " " << ctime(&m_start_time) << "\n";
        }
        else
        {
            cout << m_vehicle->getPlate() << " " << ctime(&m_start_time) << " " << ctime(&m_end_time) << "\n";
        }
    }
};

#endif