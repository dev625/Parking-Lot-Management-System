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
    Vehicle *temp;

public:
    VehicleLog(time_t start_time, Vehicle *&v)
    {
        m_start_time = start_time;
        m_end_time = -1;
        temp = v;
    }

    VehicleLog(time_t start_time, time_t end_time, Vehicle *&v)
    {
        m_start_time = start_time;
        m_end_time = end_time;
        temp = v;
    }

    void setStart(time_t start_time)
    {
        m_start_time = start_time;
    }

    void setEnd(time_t end_time)
    {
        m_end_time = end_time;
    }

    void describe()
    {
        char *formatted_start = ctime(&m_start_time);
        if (m_end_time == -1)
        {
            cout << temp->getPlate() << " " << formatted_start << "\n";
        }
        else
        {
            char *formatted_end = ctime(&m_end_time);
            cout << temp->getPlate() << " " << formatted_start << " " << formatted_end << "\n";
        }
    }
};

#endif