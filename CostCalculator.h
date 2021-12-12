#ifndef COST_CALC_H
#define COST_CALC_H

#include <Logger.h>

// Abstract Base Class
class CostCalculator
{
public:
    // Pure Virtual Function
    virtual double getCost(VehicleLog log) = 0;
};

// Using Hierarchial Inheritance since a single base class is used to derive all the other child classes

class Bike_Cost_Calculator : public CostCalculator
{
public:
    // getCost is made static so that we dont have to create Calculator objects
    static double getCost(VehicleLog &log)
    {
        if (log.time_spent() == -1)
            return 0;
        return 10 + (3 * log.time_spent());
    }
};

class Car_Cost_Calculator : public CostCalculator
{
public:
    // getCost is made static so that we dont have to create Calculator objects
    static double getCost(VehicleLog &log)
    {
        if (log.time_spent() == -1)
            return 0;
        return 20 + (4 * log.time_spent());
    }
};

class Bus_Cost_Calculator : public CostCalculator
{
public:
    // getCost is made static so that we dont have to create Calculator objects
    static double getCost(VehicleLog &log)
    {
        if (log.time_spent() == -1)
            return 0;
        return 30 + (5 * log.time_spent());
    }
};

#endif
