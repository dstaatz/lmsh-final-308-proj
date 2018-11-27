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


typedef struct ScanResults {
	int N;
	int E;
	int S;
	int W;
	Location * location;
} ScanResults;


typedef struct Path {
	Location current;
	struct Path * next;
} Path;


#endif /* types_h */
