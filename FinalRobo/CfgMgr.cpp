#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include "CfgMgr.h"

using namespace std;



string CFG_MAPFILE_LOCATION;
int CFG_ROBOINIT_LOCATIONX,CFG_ROBOINIT_LOCATIONY,CFG_ROBOINIT_LOCATIONYAW;
int CFG_DEST_X, CFG_DEST_Y;
int CFG_BOTSIZE_X,CFG_BOTSIZE_Y;
double CFG_MAP_RES, CFG_GRID_RES;

void CfgMgr::LoadConfigurationFile(const char* filename)
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
