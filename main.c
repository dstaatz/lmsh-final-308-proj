//
// main.c
// CIS 308 Final Project
//
// Created by Dylan Staatz and Trey Schmidt
//

// Include I/O capability and our header files
#include <stdio.h>

#include "types.h"
#include "maze.h"
#include "robot.h"

void print_usage()
{
  printf("Error: Incorrect input.\n\n");
  printf("Usage:\n");
  printf("./main \"FileNameOfMaze.txt\" \n");
}

int main(int argc, const char * argv[])
{
  if (argc != 2)
  {
    print_usage();
    return 0;
  }

  // Initialization
  const char * fileName = argv[1];
  Maze * ActualMaze = InitializeMaze(fileName);
  Maze * RobotMaze = InitializeEmptyMaze(ActualMaze->height, ActualMaze->width, ActualMaze->start, ActualMaze->end)
  Robot * BillyEugene = InitalizeRobot(RobotMaze);

  // Run the loop
  while(BillyEugene->location != ActualMaze->end)
  {
    // Scan
    ScanResults * s = Scan(ActualMaze, BillyEugene->location);
    // Update Robot knowledge of walls
    UpdateRobotMaze(BillyEugene, s);
    // FloodFill to update Robot
    FloodFill(BillyEugene);
    // Move Robot
    MoveRobot(BillyEugene);
  }

  // PrintRobotPath
  PrintRobotPath(BillyEugene);
  return 0;
}
