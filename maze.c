//
// maze.c
// CIS 308 Final Project
//
// Created by Dylan Staatz and Trey Schmidt
//

#include <stdio.h>

#include "maze.h"

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


Maze * InitializeMazeEmpty(int width, int height);

void PrintMaze(Maze * m);


