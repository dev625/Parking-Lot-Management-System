#include <iostream>
#include <Vehicle.h>
class ParkingLot
{
private:
    int **p;
    int m_floors;
    int m_spots;
    static int occupancy;

public:
    ParkingLot(int floors = 6, int spots = 9)
    {
        occupancy = 0;
        // Parking Lot has dimensions (floors,spots);
        m_floors = floors;
        m_spots = spots;
        p = new int *[floors]; // p is an array of pointers
        for (int i = 0; i < floors; i++)
        {
            p[i] = new int[spots]; // each of those pointers point to a 1-D array
        }

        // Init the Parking Lot Spots Size
        for (int i = 0; i < floors; i++)
        {
            for (int j = 0; j < spots; j++)
            {
                if (j < 3)
                    p[i][j] = 1;
                else if (j < 6)
                    p[i][j] = 2;
                else
                    p[i][j] = 3;
            }
        }
    }

    ~ParkingLot()
    {
        for (int i = 0; i < m_floors; i++)
            delete[] p[i]; //   Delete each of the rows first
        delete[] p;        //   Delete the 2-D Array
    }

    void showParkingLot()
    {
        for (int i = 0; i < m_floors; i++)
        {
            for (int j = 0; j < m_spots; j++)
            {
                std::cout << p[i][j] << " ";
            }
            std::cout << "\n";
        }
    }

    void Park(int type, std::string plate)
    {
        occupancy++;
        lotSummary(*this);
    }

    friend void lotSummary(ParkingLot &lot);
};

void lotSummary(ParkingLot &p)
{
    std::cout << p.occupancy << "\n";
}