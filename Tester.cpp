#include <bits/stdc++.h>
#include <ParkingLot.h>
using namespace std;

int main()
{
    ParkingLot p(6, 9);
    p.showParkingLot();
    int type;
    string number_plate;
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
            cout << "Enter the type and the number plate\n";
            cin >> type;
            cin.ignore(32767, '\n');
            cin >> number_plate;
            cout << number_plate;
            p.Park(type, number_plate);
            break;
        case 2:
            break;
        case 3:
            break;
        }
    }
}