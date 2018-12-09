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

  int iterations = 0;

  // Initialization
  const char * fileName = argv[1];
  Maze * ActualMaze = InitializeMaze(fileName);
  Maze * RobotMaze = InitializeMazeEmpty(ActualMaze->height, ActualMaze->width, ActualMaze->start, ActualMaze->end);
  PrintMaze(ActualMaze);
  Robot * BillyEugene = InitalizeRobot(RobotMaze);
  printf("Made robot\n");
  // Run the loop
  while(!lociseq(BillyEugene->l, ActualMaze->end))
  {
    printf("Next iteration:\n");
    // Scan
    ScanResults * s = Scan(ActualMaze, BillyEugene->l);
    printf("Scanned surroundings\n");
    // Update Robot knowledge of walls
    UpdateRobotMaze(BillyEugene, s);
    printf("Updated the robot's maze\n");
    // FloodFill to update Robot
    FloodFill(BillyEugene);
    printf("Floodfill\n");
    // Move Robot
    MoveRobot(BillyEugene);
    printf("Moved robot\n");
    printf("Robot new location: (%d, %d)", BillyEugene->l->posX, BillyEugene->l->posY);
    iterations++;
  }
  printf("Robot is at the end\n");
  printf("Iterations: %d\n", iterations);
  // PrintRobotPath
  PrintRobotPath(BillyEugene);
  printf("Printed robot path\n");
  return 0;
}
