//
// maze.c
// CIS 308 Final Project
//
// Created by Dylan Staatz and Trey Schmidt
//

#include <stdio.h>

#include "maze.h"
#include "types.h"

Maze * InitializeMaze(char * fn)
{
    FILE * fp_read = fopen(fn ,"r");
    char buffer[101];
    // Do stuff with the file
    while (fgets(buffer, 101, fn) != NULL)
    {

    }
    fclose(fp_read);
  }


Maze * InitializeMazeEmpty(int width, int height, Location * start, Location * end)
{
  int[][] arrayOfCells = new int[width][height];
  Maze * emptyMaze = malloc(sizeof(Maze));
  emptyMaze->height = height;
  emptyMaze->width = width;
  emptyMaze->cells = arrayOfCells;
  emptyMaze->start = start;
  emptyMaze->end = end;
  return emptyMaze;
}

ScanResults * Scan(Maze * m, Location * l)
{
  ScanResults * result = malloc(sizeof(ScanResults))
}

void PrintMaze(Maze * m);


