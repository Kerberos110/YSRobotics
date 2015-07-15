/* 
 * File:   PathPlanner.h
 * Author: Kerberos
 *
 * Created on June 13, 2015, 7:06 AM
 */

#ifndef PATHPLANNER_H
#define	PATHPLANNER_H

using namespace std;


class PathPlanner
{
    public:
     PathPlanner();
    ~PathPlanner();
    string pathFind( const int & xStart, const int & yStart,
            const int & xFinish, const int & yFinish );
private:
    
};

int pathmain();

#endif	/* PATHPLANNER_H */

