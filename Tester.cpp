#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <Logger.h>
#include <Vehicle.h>
#include <ParkingLot.h>
#include <CostCalculator.h>

using namespace std;

int main()
{
    ParkingLot PL(6, 9); // Create a Parking Lot Object
    PL.showParkingLot(); // Display the initial layout
    int type;            // Vehicle Type (Take user input)
    string number_plate;
    vector<VehicleLog> myLog; // Dynamic Array for Storing the Log of Vehicles
    // Start the User I/O
    while (1)
    {
        cout << "What action do you want to perform?\n";
        cout << "Press 1 to park a vehicle.\n";
        cout << "Press 2 to remove a vehicle from the parking lot.\n";
        cout << "Press 3 to get a log of the parking details.\n";
        cout << "Press 4 to get the current layout of the parking lot.\n";
        cout << "Press 5 to describe all the vehicles that have been in the parking lot.\n";
        cout << "Press 6 to calculate cost incurred for a particular vehicle.\n";
        cout << "Press 7 to generate a csv file with the log of vehicles\n";
        cout << "Press 8 to terminate the program.\n";
        int action;
        cin >> action;
        switch (action)
        {
        case 1:
        {
            cout << "Enter the type and the number plate : \n";
            cin >> type;
            cin.ignore(32767, '\n'); // Ignore Input Buffer Stream till a new line is encountered
            cin >> number_plate;
            Vehicle *input_vehicle = new Vehicle(type, number_plate); // Create a Vehicle Object in Dynamic Memory
            bool check = PL.Park(input_vehicle);                      // Check whether if it is possible to park
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
            cout << "Enter the number plate : \n";
            cin >> number_plate; // Get the Number Plate from the user and try to park it
            bool check = PL.dePark(number_plate);
            if (!check) // If no vehicle found with input license plate then raise error
            {
                cout << "No vehicle with plate number " << number_plate << " found, Please Enter a Valid Number Plate.\n";
            }
            else
            {
                /*
                Loop through the myLog array to find the vehicle with the input license plate
                and when found set its end time.
                 */
                for (int i = 0; i < myLog.size(); i++)
                {
                    if (myLog[i].getPlate() == number_plate)
                    {
                        myLog[i].setEnd();
                        break;
                    }
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
            PL.showParkingLot();
            break;
        }
        case 5:
        {
            for (VehicleLog &log : myLog)
            {
                Vehicle *my_vec_obj;        // Create a Base Class Pointer
                int v_size = log.getSize(); // Get the Size of the Vehicle
                /*
                This portion shows the use of virtual functions. We assign the base class pointer temp to the address of
                the derived class objects.

                Since describe() was defined as a virtual function in the base class then dynamic binding is performed at
                runtime and the method of the appropriate class is linked.
                */

                // Create apt derived class objects whose address is assigned to the base class pointer
                if (v_size == 1)
                {
                    Bike *temp_bike = new Bike(log.getPlate());
                    my_vec_obj = temp_bike;
                    my_vec_obj->describe();
                }
                else if (v_size == 2)
                {
                    Car *temp_car = new Car(log.getPlate());
                    my_vec_obj = temp_car;
                    my_vec_obj->describe();
                }
                else if (v_size == 3)
                {
                    Bus *temp_bus = new Bus(log.getPlate());
                    my_vec_obj = temp_bus;
                    my_vec_obj->describe();
                }
            }
            break;
        }
        case 6:
        {
            cout << "Please Enter the Number Plate : \n";
            cin >> number_plate;
            bool vehicleFound = false;
            for (VehicleLog &log : myLog)
            {
                if (log.getPlate() == number_plate)
                {
                    vehicleFound = true;
                    int v_type = log.getSize();
                    cout << "The total cost incurred by this vehicle is ";
                    if (v_type == 1)
                        cout << Bike_Cost_Calculator::getCost(log) << " Rupees Only.\n";
                    else if (v_type == 2)
                        cout << Car_Cost_Calculator::getCost(log) << " Rupees Only. \n";
                    else if (v_type == 3)
                        cout << Bus_Cost_Calculator::getCost(log) << " Rupees Only. \n";
                    break;
                }
            }
            if (!vehicleFound)
            {
                cout << "There exists no such vehicle in the Parking Lot. Please try again!\n";
            }
            break;
        }
        case 7:
        {
            ofstream out_file("log.csv");
            out_file << "License_Plate,Start_Time,End_Time\n";
            for (VehicleLog &log : myLog) // Iterate throught the myLog Array and call describe for each object
                out_file << log.getPlate() << "," << log.getStart() << "," << log.getEnd() << "\n";
            cout << "log.csv is ready with the log of vehicles!\n";
            out_file.close();
            break;
        }
        case 8:
        {
            cout << "Thank you!";
            exit(0);
            break;
        }
        }
    }
}