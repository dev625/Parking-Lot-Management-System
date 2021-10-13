# Parking Lot Management System 


The Parking Lot designed here is supposed to have 6 floors with 9 spots each.

Layout : 

1 1 1 2 2 2 3 3 3 
1 1 1 2 2 2 3 3 3 
1 1 1 2 2 2 3 3 3 
1 1 1 2 2 2 3 3 3 
1 1 1 2 2 2 3 3 3 
1 1 1 2 2 2 3 3 3 

Sizes of Vehicles : 
Bike : Size 1 
Car  : Size 2
Bus  : Size 3


Parking Logic : 

Greedily allot using the following rules : 

A Bike can park in any of the spots.
A Car can park in either two consecutive spots of size 1 or a single spot of size 2/3.
A Bus can park in 3 spots of size 1, or 2 consecutive 1 and 2 spots or a single spot of size 3.