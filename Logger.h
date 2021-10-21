#include <Vehicle.h>
#include <iostream>
class VehicleLog
{
private:
    int m_start_time;
    int m_end_time;
    Vehicle *temp;

public:
    VehicleLog()
    {
        m_start_time = -1;
        m_end_time = -1;
        temp = new Vehicle(-1, "TEMP_PLATE");
    }

    VehicleLog(int start_time, int end_time, Vehicle *&v)
    {
        m_start_time = start_time;
        m_end_time = end_time;
        temp = v;
    }

    void setStart(int start_time)
    {
        m_start_time = start_time;
    }

    void setEnd(int end_time)
    {
        m_end_time = end_time;
    }

    void describe()
    {
        std::cout << temp->getPlate() << " " << m_start_time << " " << m_end_time << "\n";
    }
};