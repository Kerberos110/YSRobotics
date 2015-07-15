/* 
 * File:   Map.h
 * Author: Kerberos
 *
 * Created on June 13, 2015, 7:03 AM
 */

#ifndef MAP_H
#define	MAP_H


class Map
{
public:
     Map();
    ~Map();
private:
    template <size_t size_x, size_t size_y>
    void CreateGridFromMap(double (&arr)[size_x][size_y]);
    void LoadMap(const char* filename);
};





#endif	/* MAP_H */

