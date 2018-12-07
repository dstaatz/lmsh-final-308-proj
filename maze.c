//
// maze.c
// CIS 308 Final Project
//
// Created by Dylan Staatz and Trey Schmidt
//

#include <stdio.h>

#include "maze.h"
#include "types.h"

// Method for initalizing the "master" maze from the name of a file
Maze * InitializeMaze(const char * fn)
{
  // Open file to read and allocate memory for the maze
  FILE * fp_read = fopen(fn ,"r");
  Maze * mazeResult = malloc(sizeof(Maze));
  // Variables to hold info
  char line[101];
  int width;
  int height;
  int i = 0;
  int j = 0;
  // Scan the width and height, start making our mazeResult and cells
  fscanf(fp_read, "%d %d", &width, &height);
  mazeResult->width = width;
  mazeResult->height = height;

  Location * startLoc = malloc(sizeof(Location));
  Location * endLoc = malloc(sizeof(Location));

  int mazeCells[height][width];
  // Throw away line
  fgets(line, 101, fp_read);

  // Do stuff with the file
  while (fgets(line, 101, fp_read) != NULL)
  {
    for (j = 0; j < width; j++)
     {
      if (line[j] == 'X') mazeCells[i][j] = 1;
      else if (line[j] == ' ') mazeCells[i][j] = 0;
      else if (line[j] == 'S')
      {
        startLoc->posX = j;
        startLoc->posY = i;
        mazeCells[i][j] = 0;
      }
      else if (line[j] == 'E')
      {
        endLoc->posX = j;
	endLoc->posY = i;
	mazeCells[i][j] = 0;
      }
      // Increment the row
      i = i + 1;
    }
  }

  mazeResult->cells = mazeCells;
  mazeResult->start = startLoc;
  mazeResult->end = endLoc;

  fclose(fp_read);

  return mazeResult;

  }

// Method for initalizing an empty maze by taking in 4 parameters
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

// Method the robot will use to scan the four walls around it
ScanResults * Scan(Maze * m, Location * l)
{
  ScanResults * result = malloc(sizeof(ScanResults))
}

// Method to print a maze
void PrintMaze(Maze * m)
{
  int i = 0;
  int j = 0;
  int startI;
  int startJ;
  int endI;
  int endJ;
  startI = m->start->posY;
  startJ = m->start->posX;
  endI = m->end->posY;
  endJ = m->end->posX;
  for (i = 0; i < m->height; i++)
  {
    for (j = 0; j < m->width; j++)
    {
      if (i == startI && j == startJ) printf('S');
      else if (i == endI && j == endJ) printf('E');
      else if (m->cells[i][j] == '1') printf("X");
      else if (m->cells[i][j] == '0') printf(" ");
    }
  }
}


