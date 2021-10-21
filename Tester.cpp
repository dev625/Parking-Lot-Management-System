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
        cout << "Press 1 for parking a vehicle\n";
        cout << "Press 2 for removing the vehicle from the parking lot\n";
        cout << "Press 3 for getting a log of parking\n";
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
            myLog.push_back(VehicleLog(0, -1, temp));
            break;
        }

        case 2:
        {
            break;
        }
        case 3:
        {
            cout << "Following is the log of the vehicles:\n";
            for (auto &x : myLog)
            {
                x.describe();
            }
            break;
        }
        }
    }
}