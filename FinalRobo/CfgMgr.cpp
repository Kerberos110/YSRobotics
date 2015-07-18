#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include "CfgMgr.h"
#include "robot.h"

using namespace std;

string CFG_MAPFILE_LOCATION;
int CFG_ROBOINIT_LOCATIONX,CFG_ROBOINIT_LOCATIONY,CFG_ROBOINIT_LOCATIONYAW;
int CFG_DEST_X, CFG_DEST_Y;
int CFG_BOTSIZE_X,CFG_BOTSIZE_Y;
double CFG_MAP_RES, CFG_GRID_RES;

// Default Constructor
CfgMgr::CfgMgr(){
    
}

void LoadConfigurationFile(const char* filename)
{
    ifstream cfgfile;
    cfgfile.open(filename);
    string a,b;
        
    cfgfile >> a >> CFG_MAPFILE_LOCATION;
    cfgfile >> a >> CFG_ROBOINIT_LOCATIONX >> CFG_ROBOINIT_LOCATIONY >> CFG_ROBOINIT_LOCATIONYAW;
    cfgfile >> a >> CFG_DEST_X >> CFG_DEST_Y;
    cfgfile >> a >> CFG_BOTSIZE_X >> CFG_BOTSIZE_Y;
    cfgfile >> a >> CFG_MAP_RES;
    cfgfile >> a >> CFG_GRID_RES;
    
    while (cfgfile >> a)
    {
        cout <<a<<"\n";
    }
}

void LoadConfigurationFile(const char* filename, Robot* robo)
{
    ifstream cfgfile;
    cfgfile.open(filename);
    string a,b;
        
    cfgfile >> a >> CFG_MAPFILE_LOCATION;
    cfgfile >> a >> CFG_ROBOINIT_LOCATIONX >> CFG_ROBOINIT_LOCATIONY >> CFG_ROBOINIT_LOCATIONYAW;
    cfgfile >> a >> CFG_DEST_X >> CFG_DEST_Y;
    cfgfile >> a >> CFG_BOTSIZE_X >> CFG_BOTSIZE_Y;
    cfgfile >> a >> CFG_MAP_RES;
    cfgfile >> a >> CFG_GRID_RES;
    
    
    // Init the robot with the parms
    robo->startX = CFG_ROBOINIT_LOCATIONX;
    robo->startY = CFG_ROBOINIT_LOCATIONY;
    robo->startYaw = CFG_ROBOINIT_LOCATIONYAW;
    robo->robotLength = CFG_BOTSIZE_X;
    robo->robotWidth = CFG_BOTSIZE_Y;
    
    robo->goalX = CFG_DEST_X;
    robo->goalY = CFG_DEST_Y;
    
}

