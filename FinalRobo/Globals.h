/*
 * Globals.h
 *
 *  Created on: Jun 9, 2015
 *      Author: colman
 */

#ifndef GLOBALS_H_
#define GLOBALS_H_

// ----------------Add By Shahaf-------------------------------------------
#include <iostream>
using namespace std;


// TODO : Update these values with yotam
#define FREE_CELL ' '
#define OCCUPIED_CELL '*'
#define UNKNOWN_CELL '?'
#define MAX_LASER_INDEX 665

struct Point {
	unsigned int x_; // Rows = Heights
	unsigned int y_; // Cols = Width

	bool operator==(const Point& rhs) const {
		return ((this->x_ == rhs.x_) && (this->y_ == rhs.y_));
	}

	bool operator!=(const Point& rhs) const {
		return (!(this->operator ==(rhs)));
	}


	bool operator<(const Point& rhs) const {
		return ((this->x_ < rhs.x_) || ((this->x_ == rhs.x_) && (this->y_ < rhs.y_)));
	}

  void Print()
  {
      cout << "X:" << this->x_ << " Y:" << this->y_ << endl;
  }
};

struct Location {
	float x_;
        float y_;
        float yaw_;

         void Print()
        {
            cout << "X:" << this->x_ << " Y:" << this->y_ << " YAW:" << this->yaw_ << endl;
        }


    inline Location operator+(Location a) {
        return {a.x_+x_,a.y_+y_, a.yaw_ + yaw_};
    }

    inline Location operator-(Location a) {
            return {a.x_ - x_,a.y_ - y_, a.yaw_ - yaw_};
        }


    inline Location operator/(float a) {
        return {x_/a,y_/a,yaw_/a};
    }

    inline bool operator!=(Location a) {
           return (!((x_ == a.x_)&&(y_ == a.y_)&&(yaw_ == a.yaw_)));
       }

    inline void operator=(Location a) {
               x_ = a.x_;
               y_ = a.y_;
               yaw_ = a.yaw_;
           }

};

namespace GridCellState {
enum CellState {
	FREE,
	OBSTACLE,
	A_STAR_PATH,
	WAY_POINT,
	BLOWED
};
}

struct GridCell {
	GridCellState::CellState cell_state : 3;
	unsigned int cell_cost : 5;
};
// -------------------Add By Shahaf--------------------------------------
// waypoints
typedef enum
{
	none,
	Up,
	Down,
	Left,
	Right,
	DownRight,
	DownLeft,
	UpRight,
	UpLeft
} PositionState;

// calc const
#define PAI 3.1415
#define NORMAL 1.8
#define RESOLUTION 4

// laser
#define LASER_COUNT 666
#define LASER_SCOPE 240
#define OBSTACLE_DISTANCE 4

// Distance consts for missing aim in a bit
#define SAFETY_DIS_FROM_OBSTACLE 0.8
#define DIS_FROM_OBSTACLE 4

//particle
//todo: check this value on simulator
#define DELTA_FROM_SON 1
#define DELTA_YAW 0.1
#define DIRECTIONS 3
#define MAX_PARTICLES 100


// movment
#define RANGE_TO_CHECK 110
#define FORWARD_SPEED 0.55
#define TURN_SPEED 0.05
#define TURN_ANGLE 0.3
#define TURN_IN_PLACE_ANGLE 0.8

// turn in place
#define TOP_RIGHT 0.7853
#define TOP_LEFT 2.3561
#define DOWN_RIGHT -0.7853
#define DOWN_LEFT -2.3561
#define RIGHT_ANGLE 0
#define LEFT_ANGLE 3.1415



#endif /* GLOBALS_H_ */
