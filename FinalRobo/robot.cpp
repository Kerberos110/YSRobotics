#include "robot.h"
#include "Globals.h"

Robot::Robot(char* ip, int port){
	_pc = new PlayerCc::PlayerClient(ip,port);
	_pp = new PlayerCc::Position2dProxy(_pc);
	_lp = new LaserProxy(_pc);

	_pp->SetMotorEnable(true);
	_pp->SetOdometry(0,0,0);

		// Init the old position in the middle of the map
		_oldX = startX / RESOLUTION;
		_oldY = startY / RESOLUTION;
		_oldYaw = startYaw;

		// the first time is from configuration file
		_x = _oldX;
		_y = _oldY;
		_yaw = _oldYaw;

		int i;

		for(i=0;i<15;i++)
		{
			_pc->Read();
		}

		_laserCount = _lp->GetCount();

}

// Methods
void Robot::read()
{
	_pc->Read();
	_x = _pp->GetXPos();
	_y =_pp->GetYPos();
	_yaw = _pp->GetYaw();
}
double Robot::getOldYawPosition()
{
 return _oldYaw;
}
double Robot::getOldYPosition()
{
	return _oldY;
}
double Robot::getOldXPosition()
{
 return _oldX;
}
LaserProxy* Robot::getLaser()
{
	return _lp;
}
double Robot::getYawPosition()
{
	return _yaw ;
}
double Robot::getXPosition()
{
	return _x ;
}

double Robot::getYPosition()
{
	return _y ;
}

double Robot::getGoalXPosition()
{
	return goalX / RESOLUTION;
}
double Robot::getGoalYPosition()
{
	return goalY / RESOLUTION;
}
int Robot::getLaserCount()
{
	return _laserCount;
}


void Robot::setSpeed(float speed, float angularSpeed)
{
	_pp->SetSpeed(speed,angularSpeed);
}

float Robot::getLaserDistance(int index)
{
	return _lp->GetRange(index);
}

void Robot::updatePosition(double x, double y, double yaw)
{
	_oldX = x;
	_oldY = y;
	_oldYaw = yaw;
}

void Robot::updateCurrPosition(double x, double y, double yaw)
{
	_x = x;
	_y = y;
	_yaw = yaw;
}
