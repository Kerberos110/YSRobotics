/* 
 * File:   CfgMgr.h
 * Author: Kerberos
 *
 * Created on June 13, 2015, 7:10 AM
 */

#ifndef CFGMGR_H
#define	CFGMGR_H

using namespace std;

class CfgMgr
{
public:
    CfgMgr();
    ~CfgMgr();
   
    string CFG_MAPFILE_LOCATION;
    int CFG_ROBOINIT_LOCATIONX,CFG_ROBOINIT_LOCATIONY,CFG_ROBOINIT_LOCATIONYAW;
    int CFG_DEST_X, CFG_DEST_Y;
    int CFG_BOTSIZE_X,CFG_BOTSIZE_Y;
    double CFG_MAP_RES, CFG_GRID_RES;
};
void LoadConfigurationFile(const char* filename);
#endif	/* CFGMGR_H */

