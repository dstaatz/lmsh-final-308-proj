//
// maze.h
// 308 Final Project
//
// Created by Dylan Staatz and Trey Schmidt
//


#ifndef maze_h
#define maze_h

#include "types.h"

#define MAX_WIDTH 101
#define MAX_HEIGHT 101

typedef struct Maze {
  int height;
  int width;
  int cells[MAX_HEIGHT][MAX_WIDTH];
  Location * start;
  Location * end;
} Maze;

Maze * InitializeMaze(const char * fn);

Maze * InitializeMazeEmpty(int width, int height, Location * start, Location * end);

ScanResults * Scan(Maze * m, Location * l);

void PrintMaze(Maze * m);


#endif /* maze_h */
