#ifndef PARKINGLOT_H
#define PARKINGLOT_H
#include <map>
#include <string>
#include <vector>
#include <Vehicle.h>
using namespace std;
class ParkingLot
{
private:
    int **p;
    int m_floors;
    int m_spots;
    int occupancy;
    map<string, vector<pair<int, int>>> mp;

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
        cout << "\n";
        for (int i = 0; i < m_floors; i++)
        {
            for (int j = 0; j < m_spots; j++)
            {
                cout << p[i][j] << " ";
            }
            cout << "\n";
        }
    }

    void Park(Vehicle *&temp)
    {
        occupancy++;
        // parking logic
        lotSummary(*this);
    }

    friend void lotSummary(ParkingLot &lot);
};

void lotSummary(ParkingLot &p)
{
    cout << "The current occupancy of the Parking Lot is " << p.occupancy << ".\n";
}

#endif