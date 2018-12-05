//
// robot.c
// 308 Final Project
//
// Created by Dylan Staatz and Trey Schmidt
//


#include "maze.h"
#include "types.h"
#include "robot.h"

Robot * InitalizeRobot(Maze * m) {
    Robot * newRobot = malloc(sizeof(Robot));
    newRobot->m = m;
    newRobot->l = m->start;
    newRobot->p = add(NULL, newRobot->l);
    return newRobot;
}
