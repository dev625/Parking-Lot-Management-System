#include <iostream>
#include <string>
#include <vector>
#include <ParkingLot.h>
#include <Logger.h>
#include <Vehicle.h>
using namespace std;

int main()
{
    ParkingLot p(6, 9);
    p.showParkingLot();
    int type;
    string number_plate;
    vector<VehicleLog> myLog;
    while (1)
    {
        cout << "What action do you want to perform?\n";
        cout << "Press 1 to park a vehicle\n";
        cout << "Press 2 to remove a vehicle from the parking lot\n";
        cout << "Press 3 to get a log of the parking details\n";
        cout << "Press 4 to get the current layout of the parking lot\n";
        cout << "Press 5 to terminate the program\n";
        int x;
        cin >> x;
        switch (x)
        {
        case 1:
        {
            cout << "Enter the type and the number plate\n";
            cin >> type;
            cin.ignore(32767, '\n');
            cin >> number_plate;
            Vehicle *temp = new Vehicle(type, number_plate);
            p.Park(temp);
            time_t now = time(0);
            myLog.push_back(VehicleLog(now, temp));
            break;
        }

        case 2:
        {
            break;
        }
        case 3:
        {
            cout << "Following is the log of the vehicles:\n";
            for (VehicleLog &x : myLog)
            {
                x.describe();
            }
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