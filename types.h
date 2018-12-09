//
// types.h
// 308 Final Project
//
// Created by Dylan Staatz and Trey Schmidt
//


#ifndef types_h
#define types_h

#define TRUE 1
#define FALSE 0

typedef struct Location {
  int posX;
  int posY;
} Location;

int lociseq(Location * loc1, Location * loc2);

typedef struct ScanResults {
  int N;
  int E;
  int S;
  int W;
  Location * l;
} ScanResults;


typedef struct Path {
  Location * current;
  struct Path * next;
} Path;

Path * add(Path * p, Location * loc);

Path * append(Path * head, Location * loc);

#endif /* types_h */
