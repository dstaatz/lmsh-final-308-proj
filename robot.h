//
// robot.h
// 308 Final Project
//
// Created by Dylan Staatz and Trey Schmidt
//

#ifndef robot_h
#define robot_h

#include "types.h"
#include "maze.h"

typedef struct Robot {
        Maze * m;
        Location * l;
	int[][] values;
        Path * p;
} Manager;

void UpdateValues(Robot * r, ScanResults * s);

void FloodFill(Robot * r, Location * end);

void MoveRobot(Robot * r);

#endif /* robot_h */
