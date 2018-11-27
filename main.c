//
// main.c
// CIS 308 Final Project
//
// Created by Dylan Staatz and Trey Schmidt
//

#include <stdio.h>

void print_usage() {
  printf("Error: Incorrect input.\n\n");
  printf("Usage:\n");
  printf("./main \"FileNameOfMaze.txt\" \n");
}

int main(int argc, const char * argv[]) {
  if (argc != 2)
  {
    print_usage();
    return 0;
  }
  else
  {
    const char * fileName = argv[1];
    FILE * fp_read = fopen(fileName, "r");
    char buffer[101];
    // Do stuff with the file
    fclose(fp_read);
    return 0;
  }
}
