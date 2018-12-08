// This is a place where Trey is testing his code to open a maze file and print it to the console

#include "maze.h"
#include "types.h"
#include "maze.c"


int main(int argc, const char * argv[])
{
  const char * fn = argv[1];
  Maze * ActualMaze = InitializeMaze(fn);
  PrintMaze(ActualMaze);
  return 0;
}

