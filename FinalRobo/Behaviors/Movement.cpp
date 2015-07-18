#include "Movement.h"

#define ANGULAR_RESOLUTION 240
#define MEASURING_AREA 0.36

bool Movement::startCond() {
	return true;
}

bool Movement::stopCond() {
	return false;
}

void Movement::action() {
}

double Movement::Get0DegreeDistance()
{
	return GetDistanceByDegree(0);
}

double Movement::Get315DegreeDistance()
{
	return GetDistanceByDegree(-45);
}

double Movement::Get45DegreeDistance()
{
	return GetDistanceByDegree(45);
}

double Movement::GetDistanceByDegree(int degree)
{
	// Caculate laser index by degree
	int scanIndex = (360 - ANGULAR_RESOLUTION + degree) / MEASURING_AREA;
	return _robot->getLaserDistance(scanIndex);
}

Movement::Movement(Robot *robot) :
	Behavior(robot) {
}

Movement::~Movement() {
}
