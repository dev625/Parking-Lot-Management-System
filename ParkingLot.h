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
    int **p;                                          // double pointer of type int
    int m_floors;                                     // the number of floors
    int m_spots;                                      // the number of parking spots per floor
    int m_occupancy;                                  // current occupancy of the parking lot
    map<string, vector<pair<int, int>>> m_coords_map; // map to keep track of co-ordinates

public:
    // Parameterized Constructor with Member Initializer List
    ParkingLot(int floors = 6, int spots = 9) : m_floors{floors}, m_spots{spots}, m_occupancy{0}
    {
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
    // Destructor for manually deallocating the 2-D Dynamic Array
    ~ParkingLot()
    {
        for (int i = 0; i < m_floors; i++)
            delete[] p[i]; //   Delete each of the rows first
        delete[] p;        //   Delete the 2-D Array
    }

    // Function to Display the Current Layout of the Parking Lot
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

    bool Park(Vehicle *&v)
    {
        // Parking logic
        bool is_space_available = false;
        int type = v->getSize();
        string num_plate = v->getPlate();
        for (int i = 0; i < m_floors; i++)
        {
            if (is_space_available == true)
            {
                break;
            }

            for (int j = 0; j < m_spots; j++)
            {
                // Input Vehicle is a Bike
                if (type == 1)
                {
                    if (p[i][j] == 1 || p[i][j] == 2 || p[i][j] == 3)
                    {
                        p[i][j] = -1;
                        m_coords_map[num_plate] = {{i, j}};
                        is_space_available = true;
                        break;
                    }
                }
                // Input Vehicle is a Car
                else if (type == 2)
                {
                    if (j + 1 < m_spots && p[i][j] == 1 && p[i][j + 1] == 1)
                    {

                        p[i][j] = -1;
                        p[i][j + 1] = -1;
                        m_coords_map[num_plate] = {{i, j}, {i, j + 1}};
                        is_space_available = true;
                        break;
                    }
                    else if (p[i][j] == 2 || p[i][j] == 3)
                    {
                        p[i][j] = -1;
                        m_coords_map[num_plate] = {{i, j}};
                        is_space_available = true;
                        break;
                    }
                }
                // Input Vehicle is a Bus
                else if (type == 3)
                {
                    if (j + 1 < m_spots && j + 2 < m_spots)
                    {
                        if (p[i][j] == 1 && p[i][j + 1] == 1 && p[i][j + 2] == 1)
                        {
                            p[i][j] = -1;
                            p[i][j + 1] = -1;
                            p[i][j + 2] = -1;
                            m_coords_map[num_plate] = {{i, j}, {i, j + 1}, {i, j + 2}};
                            is_space_available = true;
                            break;
                        }
                    }
                    if (j + 1 < m_spots)
                    {
                        if (p[i][j] == 1 && p[i][j + 1] == 2)
                        {
                            p[i][j] = -1;
                            p[i][j + 1] = -1;
                            m_coords_map[num_plate] = {{i, j}, {i, j + 1}};
                            is_space_available = true;
                            break;
                        }
                    }

                    if (p[i][j] == 3)
                    {
                        p[i][j] = -1;
                        m_coords_map[num_plate] = {{i, j}};
                        is_space_available = true;
                        break;
                    }
                }
            }
        }
        if (is_space_available)
            m_occupancy++;
        lotSummary(*this);
        return is_space_available;
    }

    bool dePark(const string &plate)
    {
        // Check if a key = plate exists in the map
        if (m_coords_map.find(plate) == m_coords_map.end())
        {
            return false;
        }
        m_occupancy--;
        vector<pair<int, int>> co_ords = m_coords_map[plate]; // Vector for the coordinates of the vehicle
        for (auto &x : co_ords)
        {
            if (x.second < 3)
                p[x.first][x.second] = 1;
            else if (x.second < 6)
                p[x.first][x.second] = 2;
            else
                p[x.first][x.second] = 3;
        }
        m_coords_map.erase(plate);
        cout << "Your vehicle is succesfully deparked.\n";
        lotSummary(*this);
        return true;
    }

    friend void lotSummary(ParkingLot &lot);
};

// Friend function which prints the current occupancy of the parking lot
void lotSummary(ParkingLot &p)
{
    cout << "The current occupancy of the Parking Lot is " << p.m_occupancy << ".\n";
}

#endif