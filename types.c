//
// types.c
// 308 Final Project
//
// Created by Dylan Staatz and Trey Schmidt
//

#include "types.h"

int lociseq(Location * loc1, Location * loc2) {
    return (loc1->posX == loc2->posX) && (loc1->posY == loc2->posY)
}
