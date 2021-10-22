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
    p.showParkingLot();
    int type;
    string number_plate;
    vector<VehicleLog> myLog;
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
        time_t now = time(0);
        switch (x)
        {
        case 1:
        {
            cout << "Enter the type and the number plate : \n";
            cin >> type;
            cin.ignore(32767, '\n');
            cin >> number_plate;
            Vehicle *input_vehicle = new Vehicle(type, number_plate);
            bool check = p.Park(input_vehicle);
            if (check)
            {
                myLog.push_back(VehicleLog(now, input_vehicle));
            }
            else
            {
                cout << "Currently there is no space available for your vehicle. Please try again later!\n";
            }
            break;
        }

        case 2:
        {
            cin >> number_plate;
            p.dePark(number_plate);
            for (VehicleLog &log : myLog)
            {
                if (log.getPlate() == number_plate)
                {
                    log.setEnd(now);
                    break;
                }
            }
            break;
        }
        case 3:
        {
            cout << "Following is the log of the vehicles:\n";
            for (VehicleLog &log : myLog)
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
        }
        }
    }
}