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
  
}