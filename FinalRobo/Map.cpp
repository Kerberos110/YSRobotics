#include "lodepng.h"
#include "Map.h"
#include <iostream>
#include "CfgMgr.h"
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
      
      
  }
  
  //BLOWMAPHERE
  
  
  //double DIVFACTOR = (double((double)CFG_GRID_RES/CFG_MAP_RES));
  int DIVFACTOR = 4;
  int DIVIFACTOR = 4;
  int grid[width/DIVIFACTOR][height/DIVIFACTOR];
 
  for (int iwidth = 0; iwidth < width; iwidth=iwidth+DIVFACTOR) {
    for (int iheight = 0; iheight < height; iheight+DIVFACTOR) {
        
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

template <size_t size_x, size_t size_y>
void CreateGridFromMap(int (&arr)[size_x][size_y])
{
    
}