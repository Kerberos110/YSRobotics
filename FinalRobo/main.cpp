/* 
 * File:   main.cpp
 * Author: colman
 *
 * Created on June 7, 2015, 12:49 AM
 */

#include <iostream>
#include <math.h>
#include <libplayerc++/playerc++.h>

using namespace std;
using namespace PlayerCc;

// Position Proxy Constants
#define MINIMUM_DISTANCE_AVOIDANCE  0.8
#define YAW_MOVEMENT_SPEED          0.3
#define FORWARD_MOVEMENT_SPEED      0.3

// Laser Proxy Constants & Macros
#define LASER_MESURING_AREA         120
#define LASER_RESOLUTION            0.36
#define DEGTOINDEX(DEGREE) (int)((DEGREE + LASER_MESURING_AREA) / LASER_RESOLUTION)
/* sample project - change check by shahaf */
int main(int argc, char** argv) {
    
    PlayerClient pc("localhost", 6665);
    LaserProxy lp(&pc);
    Position2dProxy pp(&pc);
    
    pp.SetMotorEnable(true);
    
    // First few reads in player are bad so we heat the engine (literally)
    for (int i = 0; i < 15; i++)
        pc.Read();
    
    while (true) {
        pc.Read();
        
        if (lp[DEGTOINDEX(0)] < MINIMUM_DISTANCE_AVOIDANCE)
            pp.SetSpeed(0, YAW_MOVEMENT_SPEED);
        else
            pp.SetSpeed(FORWARD_MOVEMENT_SPEED, 0);
    }
    
    return 0;
}