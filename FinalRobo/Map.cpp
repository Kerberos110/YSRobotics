<<<<<<< HEAD
#include "lodepng.h"
#include "Map.h"
#include <iostream>
#include "CfgMgr.h"
using namespace std;

const int COLOR_WHITE=0;
const int COLOR_BLACK=1;

// Ctor and Init map from scratch
Map::Map()
{
	for (int i = 0; i < MAP_SIZE; i++)
	{
		for (int j = 0; j < MAP_SIZE; j++)
		{
			_mapMatrix[i][j] = UNKNOWN_CELL;
		}
	}
}

// Ctor to init map with a map as parameter
Map::Map(Map* mapToCopy)
{
	for (int i = 0; i < MAP_SIZE; i++)
	{
		for (int j = 0; j < MAP_SIZE; j++)
		{
			_mapMatrix[i][j] = mapToCopy->_mapMatrix[i][j];
		}
	}
}

void CreateMap(char* filePath)
{

}

void Map::setMapValue(double x, double y, char value)
{
	int col = getColFromXPos(x);
	int row = getRowFromYPos(y);

	if (_mapMatrix[row][col] != OCCUPIED_CELL)
	{
		_mapMatrix[row][col] = value;
	}
}

void Map::printMap()
{
	// Print to console
	for (int i=MAP_SIZE - 1; i >= 0 ; i--)
	{
		for (int j=MAP_SIZE - 1; j >= 0; j--)
		{
			cout << _mapMatrix[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

char Map::getMapValueFromRealLocation(double x, double y)
{
	int col = getColFromXPos(x);
	int row = getRowFromYPos(y);
	return _mapMatrix[row][col];
}

int Map::getColFromXPos(double x)
{
	return (x / RESOLUTION) + (MAP_SIZE / 2);
}

int Map::getRowFromYPos(double y)
{
	return (MAP_SIZE / 2) - (y / RESOLUTION);
}


void LoadMap(const char* filename)
{
  std::vector<unsigned char> png;
  std::vector<unsigned char> image; //the raw pixels
  
  unsigned width, height;

  //load and decode
  lodepng::load_file(png, filename);
  unsigned error = lodepng::decode(image, width, height, png);  
  if(error) std::cout << "decoder error " << error << ": " << lodepng_error_text(error) << std::endl;
  
  int map[width][height];
  int bytesIndex=0;
  while(bytesIndex<image.size()-3)
  {      
      int R = image[bytesIndex];
      int G = image[bytesIndex+1];
      int B = image[bytesIndex+2];
      int A = image[bytesIndex+3];
      
      int color = A+R+G+B;
      map[(bytesIndex/4)%width][(bytesIndex/4)/width] = color;
      /*if(color==255)
      {
        map[(bytesIndex/4)%width][(bytesIndex/4)/width] = COLOR_BLACK;
        cout << "[" << (bytesIndex/4)%width << "," << (bytesIndex/4)/width<< "]\n";
      }*/
      bytesIndex=bytesIndex+4;
      
      //double DIVFACTOR = (double((double)CFG_GRID_RES/CFG_MAP_RES));
    int DIVFACTOR = 4;
    int DIVIFACTOR = 4;
    int grid[width/DIVIFACTOR][height/DIVIFACTOR];

    for (int iwidth = 0; iwidth < width; iwidth=iwidth+DIVFACTOR) {
      for (int iheight = 0; iheight < height; iheight=iheight+DIVFACTOR) {

          bool bIsDIrty = false;   
          for (int xrunner = 0; xrunner < DIVFACTOR; xrunner++) {
                 for (int yrunner = 0; yrunner < DIVFACTOR; yrunner++) {
                     if(map[iwidth+xrunner][iheight+yrunner]==COLOR_BLACK)
                     {
                         bIsDIrty=true;
                     }
                 }
             }
          if(!bIsDIrty)
          {
              grid[iwidth/DIVIFACTOR][iheight/DIVIFACTOR] = COLOR_WHITE;
          }
          else
          {
              grid[iwidth/DIVIFACTOR][iheight/DIVIFACTOR] = COLOR_BLACK;
          }
          iheight +=DIVIFACTOR;
      }
      iwidth +=DIVIFACTOR;
      
    }
  }
      for(int y=0;y<height/4;y++)
        {
            for(int x=0;x<width/4;x++)
                if(map[x][y]==0)
                    cout<<".";
                else if(map[x][y]==1)
                    cout<<"1";
               
            cout<<endl;
        }

  
  
  
}

template <size_t size_x, size_t size_y>

//BLOWMAPHERE
void CreateGridFromMap(int (&arr)[size_x][size_y])
{
  
=======
#include "lodepng.h"
#include "Map.h"
#include <iostream>
#include "CfgMgr.h"
#include <stdio.h>
using namespace std;

const int COLOR_WHITE=0;
const int COLOR_BLACK=1;

void LoadMap(const char* filename)
{
  std::vector<unsigned char> png;
  std::vector<unsigned char> image; //the raw pixels
  
  unsigned width, height;

  //load and decode
  lodepng::load_file(png, filename);
  unsigned error = lodepng::decode(image, width, height, png);  
  if(error) std::cout << "decoder error " << error << ": " << lodepng_error_text(error) << std::endl;
  
  
  std::vector< std::vector<int> > map_Array(height,std::vector<int>(width));
  int map[width][height];
  int bytesIndex=0;
  while(bytesIndex<image.size()-3)
  {      
      int R = image[bytesIndex];
      int G = image[bytesIndex+1];
      int B = image[bytesIndex+2];
      int A = image[bytesIndex+3];
      
      int color = A+R+G+B;
      //map[(bytesIndex/4)%width][(bytesIndex/4)/width] = color;
      //map_Array[(bytesIndex/4)%width][(bytesIndex/4)/width] = color;
      if(color==255)
      {
        map[(bytesIndex/4)%width][(bytesIndex/4)/width] = COLOR_BLACK;
      }
      else if(color=1020)
      {
        map[(bytesIndex/4)%width][(bytesIndex/4)/width] = COLOR_WHITE;
      } 
      bytesIndex=bytesIndex+4;
  }   
      
      //double DIVFACTOR = (double((double)CFG_GRID_RES/CFG_MAP_RES));
    int DIVFACTOR = 4;
    int grid[width/DIVFACTOR][height/DIVFACTOR];
    int iwidth;
    int iheight;
    
    for (iwidth = 0; iwidth < width; iwidth=iwidth+DIVFACTOR) {
      for (iheight = 0; iheight < height; iheight=iheight+DIVFACTOR) {

          bool bIsDIrty = false;   
          for (int xrunner = 0; xrunner < DIVFACTOR; xrunner++) {
                 for (int yrunner = 0; yrunner < DIVFACTOR; yrunner++) {
                     if(map[iwidth+xrunner][iheight+yrunner]==COLOR_BLACK)
                     {
                         bIsDIrty=true;
                     }
                 }
             }
          if(!bIsDIrty)
          {
              grid[iwidth/DIVFACTOR][iheight/DIVFACTOR] = COLOR_WHITE;
          }
          else
          {
              grid[iwidth/DIVFACTOR][iheight/DIVFACTOR] = COLOR_BLACK;
          }
          iheight +=DIVFACTOR;
      }
      iwidth +=DIVFACTOR;
  }
    
    CfgMgr cmg= CfgMgr();
    
    grid[cmg.CFG_ROBOINIT_LOCATIONX][cmg.CFG_ROBOINIT_LOCATIONY]=2;

    
        for(int y=0;y<iheight/4;y++)
        {
            for(int x=0;x<iwidth/4;x++)
                if(grid[x][y]==COLOR_WHITE)
                    cout<<".";
                else if(grid[x][y]==COLOR_BLACK)
                    cout<<"O"; //obstacle
                else if(grid[x][y]==2)
                    cout<<"S"; //start
                else if(grid[x][y]==3)
                    cout<<"R"; //route
                else if(grid[x][y]==4)
                    cout<<"F"; //finish
            cout<<endl;
        }
  
}

template <size_t size_x, size_t size_y>

//BLOWMAPHERE
void CreateGridFromMap(int (&arr)[size_x][size_y])
{
  
>>>>>>> 91ab714079fd773238968bbe9e6ab847a1322fca
}