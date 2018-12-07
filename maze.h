//
// maze.h
// 308 Final Project
//
// Created by Dylan Staatz and Trey Schmidt
//


#ifndef maze_h
#define maze_h

#include "types.h"

#define MAX_WIDTH 100
#define MAX_HEIGHT 100

typedef struct Maze {
  int height;
  int width;
  int[MAX_HEIGHT][MAX_WIDTH] cells;
  Location * start;
  Location * end;
} Maze;

Maze * InitializeMaze(char * fn);

Maze * InitializeMazeEmpty(int width, int height, Location * start, Location * end);

ScanResults * Scan(Maze * m, Location * l);

void PrintMaze(Maze * m);


#endif /* maze_h */
