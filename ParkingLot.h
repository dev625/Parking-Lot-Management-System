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
    int **m_parking_lot;                              // Double Pointer of type int
    int m_floors;                                     // Number of Floors
    int m_spots;                                      // Number of Parking Spots per Floor
    int m_occupancy;                                  // Current Occupancy of the Parking Lot
    map<string, vector<pair<int, int>>> m_coords_map; // Hash Map to keep track of Vehicle co-ordinates

public:
    // Parameterized Constructor with Member Initializer List
    ParkingLot(int floors = 6, int spots = 9) : m_floors{floors}, m_spots{spots}, m_occupancy{0}
    {
        m_parking_lot = new int *[floors]; // m_parking_lot is an Array of Pointers
        for (int i = 0; i < floors; i++)
        {
            m_parking_lot[i] = new int[spots]; // each of those pointers point to a 1-D array
        }
        // Init the Parking Lot Spots Size
        int per_floor_spots = m_spots / 3;
        for (int i = 0; i < floors; i++)
        {
            for (int j = 0; j < spots; j++)
            {
                if (j < per_floor_spots)
                    m_parking_lot[i][j] = 1;
                else if (j < 2 * per_floor_spots)
                    m_parking_lot[i][j] = 2;
                else
                    m_parking_lot[i][j] = 3;
            }
        }
    }
    // Destructor for manually deallocating the 2-D Dynamic Array
    ~ParkingLot()
    {
        for (int i = 0; i < m_floors; i++)
            delete[] m_parking_lot[i]; //   Delete each of the rows first
        delete[] m_parking_lot;        //   Delete the 2-D Array
    }

    // Function to Display the Current Layout of the Parking Lot
    void showParkingLot()
    {
        cout << "\n";
        for (int i = 0; i < m_floors; i++)
        {
            for (int j = 0; j < m_spots; j++)
            {
                cout << m_parking_lot[i][j] << " ";
            }
            cout << "\n";
        }
    }

    bool Park(Vehicle *&vec)
    {
        // Parking logic
        bool is_space_available = false;
        int type = vec->getSize();
        string num_plate = vec->getPlate();
        for (int i = 0; i < m_floors; i++)
        {
            // Break out of the outer loop if space was allocated in the previous row
            if (is_space_available == true)
            {
                break;
            }

            for (int j = 0; j < m_spots; j++)
            {
                // Input Vehicle is a Bike
                if (type == 1)
                {
                    // Check if any of the spots is empty
                    if (m_parking_lot[i][j] == 1 || m_parking_lot[i][j] == 2 || m_parking_lot[i][j] == 3)
                    {
                        m_parking_lot[i][j] = -1;
                        m_coords_map[num_plate] = {{i, j}};
                        is_space_available = true;
                        break;
                    }
                }
                // Input Vehicle is a Car
                else if (type == 2)
                {
                    // Check for two consecutive size 1 spots
                    if (j + 1 < m_spots && m_parking_lot[i][j] == 1 && m_parking_lot[i][j + 1] == 1)
                    {

                        m_parking_lot[i][j] = -1;
                        m_parking_lot[i][j + 1] = -1;
                        m_coords_map[num_plate] = {{i, j}, {i, j + 1}};
                        is_space_available = true;
                        break;
                    }
                    // Check for a single size 2 or size 3 spot
                    else if (m_parking_lot[i][j] == 2 || m_parking_lot[i][j] == 3)
                    {
                        m_parking_lot[i][j] = -1;
                        m_coords_map[num_plate] = {{i, j}};
                        is_space_available = true;
                        break;
                    }
                }
                // Input Vehicle is a Bus
                else if (type == 3)
                {
                    // Check for three consecutive spots of size 1 each
                    if (j + 1 < m_spots && j + 2 < m_spots)
                    {
                        if (m_parking_lot[i][j] == 1 && m_parking_lot[i][j + 1] == 1 && m_parking_lot[i][j + 2] == 1)
                        {
                            m_parking_lot[i][j] = -1;
                            m_parking_lot[i][j + 1] = -1;
                            m_parking_lot[i][j + 2] = -1;
                            m_coords_map[num_plate] = {{i, j}, {i, j + 1}, {i, j + 2}};
                            is_space_available = true;
                            break;
                        }
                    }
                    // Check for two consecutive spots of size 1 and size 2
                    if (j + 1 < m_spots)
                    {
                        if (m_parking_lot[i][j] == 1 && m_parking_lot[i][j + 1] == 2)
                        {
                            m_parking_lot[i][j] = -1;
                            m_parking_lot[i][j + 1] = -1;
                            m_coords_map[num_plate] = {{i, j}, {i, j + 1}};
                            is_space_available = true;
                            break;
                        }
                    }
                    // Check for a single spot of size 3
                    if (m_parking_lot[i][j] == 3)
                    {
                        m_parking_lot[i][j] = -1;
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
        int per_floor_spots = m_spots / 3;
        for (auto &x : co_ords)
        {
            if (x.second < per_floor_spots)
                m_parking_lot[x.first][x.second] = 1;
            else if (x.second < 2 * per_floor_spots)
                m_parking_lot[x.first][x.second] = 2;
            else
                m_parking_lot[x.first][x.second] = 3;
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