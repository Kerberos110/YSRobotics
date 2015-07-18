#ifndef MOVEFORWARD_H_
#define MOVEFORWARD_H_
#define SAMPLES_COUNT 666

#include "Movement.h"
#include "TurnRight.h"
#include "TurnLeft.h"

class MoveForward: public Movement {
private:
public:
	virtual bool startCond();
	virtual bool stopCond();
	virtual void action();
	MoveForward(Robot *robot);
	virtual ~MoveForward();
};

#endif /* MOVEFORWARD_H_ */
