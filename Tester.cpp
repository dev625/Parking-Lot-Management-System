#include <bits/stdc++.h>
#include <ParkingLot.h>
#include <Vehicle.h>
using namespace std;

int main()
{
    ParkingLot p(6, 9);
    p.showParkingLot();
    Vehicle Toyota(2, "RJ14AX1234");
    Toyota.describe();
}