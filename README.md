# Parking Lot Management System 


As the title suggests, this project is an implementation of a parking lot management system in C++.  
The main aim of this project is to put Object Oriented Programming Principles to use in real life.

## Layout 
Parking Spots have different sizes as described below. This orientation can be changed by the end user. However, For the sake of brevity, on a single floor for any type of vehicle the number of spots is limited to being a factor of 3.
```
    1 1 1 | 2 2 2 | 3 3 3  

    1 1 1 | 2 2 2 | 3 3 3  

    1 1 1 | 2 2 2 | 3 3 3  

    1 1 1 | 2 2 2 | 3 3 3  

    1 1 1 | 2 2 2 | 3 3 3  

    1 1 1 | 2 2 2 | 3 3 3  
  
```

## Sizes of Vehicles 
```
Bike : Size 1  

Car  : Size 2  

Bus  : Size 3  
```


## Parking Logic 
```
We greedily allot vehicles to spots using the following rules : 

1. A Bike can park in any of the spots.  

2. A Car can park in either two consecutive spots of size 1 or a single spot of size 2 or 3.  

3. A Bus can park in 3 spots of size 1, or 2 consecutive 1 and 2 spots or a single spot of size 3.
```