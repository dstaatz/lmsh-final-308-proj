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
} Robot;

Robot * InitalizeRobot(Maze * m);

void UpdateRobotMaze(Robot * r, ScanResults * s);

void FloodFill(Robot * r);

void MoveRobot(Robot * r);

void PrintRobotPath(Robot * r);

#endif /* robot_h */
