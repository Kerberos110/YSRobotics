/* 
 * File:   Map.h
 * Author: Kerberos
 *
 * Created on June 13, 2015, 7:03 AM
 */

#ifndef MAP_H
#define	MAP_H

#include "Globals.h"

// TODO : Update mapsize and res from yotam
#define MAP_SIZE 200



class Map
{
public:
    Map();
    Map(Map* mapToCopy);
    void setMapValue(double x, double y, char value);
    void printMap();
    char getMapValueFromRealLocation(double x, double y);
    ~Map();
private:
    template <size_t size_x, size_t size_y>
    void CreateGridFromMap(double (&arr)[size_x][size_y]);
    
    int getColFromXPos(double x);
    int getRowFromYPos(double y);
    char _mapMatrix[MAP_SIZE][MAP_SIZE];
    
    
};

void LoadMap(const char* filename);





#endif	/* MAP_H */

