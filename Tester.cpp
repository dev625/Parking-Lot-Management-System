#include <iostream>
#include <string>
#include <vector>
#include <ParkingLot.h>
#include <Logger.h>
#include <Vehicle.h>
using namespace std;

int main()
{
    ParkingLot p(6, 9); // Create a Parking Lot Object
    p.showParkingLot(); // Display the initial layout
    int type;
    string number_plate;
    vector<VehicleLog> myLog; // Dynamic Array for Log of Vehicles
    // Start the User I/O
    while (1)
    {
        cout << "What action do you want to perform?\n";
        cout << "Press 1 to park a vehicle.\n";
        cout << "Press 2 to remove a vehicle from the parking lot.\n";
        cout << "Press 3 to get a log of the parking details.\n";
        cout << "Press 4 to get the current layout of the parking lot.\n";
        cout << "Press 5 to terminate the program.\n";
        int x;
        cin >> x;
        switch (x)
        {
        case 1:
        {
            cout << "Enter the type and the number plate : \n";
            cin >> type;
            cin.ignore(32767, '\n');
            cin >> number_plate;
            Vehicle *input_vehicle = new Vehicle(type, number_plate); // Create a Vehicle Object in Dynamic Memory
            bool check = p.Park(input_vehicle);                       // Check whether if it is possible to park
            if (check)
            {
                time_t now = time(NULL);                         // Get the current system time
                myLog.push_back(VehicleLog(now, input_vehicle)); // Create a VehicleLog Object and add it to myLog Array
            }
            else
            {
                cout << "Currently there is no space available for your vehicle. Please try again later!\n";
            }
            break;
        }

        case 2:
        {
            cin >> number_plate; // Get the Number Plate from the user and try to park it
            bool check = p.dePark(number_plate);
            if (!check) // If no vehicle with number_plate found then print error message
            {
                cout << "No vehicle with plate number " << number_plate << " found, Please Enter a Valid Number Plate.\n";
            }
            for (VehicleLog &log : myLog)
            {
                if (log.getPlate() == number_plate)
                {
                    log.setEnd();
                    break;
                }
            }
            break;
        }
        case 3:
        {
            cout << "Following is the log of the vehicles:\n";
            for (VehicleLog &log : myLog) // Iterate throught the myLog Array and call describe for each object
                log.describe();
            break;
        }
        case 4:
        {
            p.showParkingLot();
            break;
        }
        case 5:
        {
            cout << "Thank you!";
            exit(0);
            break;
        }
        }
    }
}