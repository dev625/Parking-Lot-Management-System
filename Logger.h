#include <Vehicle.h>
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

    void setStart(int start_time)
    {
        m_start_time = start_time;
    }

    void setEnd(int end_time)
    {
        m_end_time = end_time;
    }
};