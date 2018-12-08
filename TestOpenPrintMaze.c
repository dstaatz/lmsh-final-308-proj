// This is a place where Trey is testing his code to open a maze file and print it to the console

#include "maze.h"
#include "types.h"


int main(int argc, const char * argv[])
{
  const char * fn = argv[1];
  Maze * ActualMaze = InitializeMaze(fn);
  Maze * emptyMaze = InitializeMazeEmpty(ActualMaze->width, ActualMaze->height, ActualMaze->start, ActualMaze->end);
  PrintMaze(ActualMaze);
  printf("\n");
  PrintMaze(emptyMaze);
  return 0;
}

