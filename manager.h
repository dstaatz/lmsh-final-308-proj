//
// manager.h
// 308 Final Project
//
// Created by Dylan Staatz and Trey Schmidt
//

#ifndef manager_h
#define manager_h

#include "types.h"
#include "maze.h"

typedef struct Manager {
	Maze * m;
	Location * start;
	Location * end;
} Manager;


Manager * InitializeManager(Maze *m, Location * start, Location * end);

ScanResults * Scan(Maze * m, Location * l);

#endif /* manager_h */
