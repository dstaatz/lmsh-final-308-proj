//
// types.c
// 308 Final Project
//
// Created by Dylan Staatz and Trey Schmidt
//

#include <stdlib.h>

#include "types.h"

// Method to see if two locations are equal
int lociseq(Location * loc1, Location * loc2) {
    return (loc1->posX == loc2->posX) && (loc1->posY == loc2->posY);
}

// Method to add a location to the path the robot has taken
Path * add(Path * p, Location * loc) {
    Path * newPath = malloc(sizeof(Path));
    Location * newLocation = malloc(sizeof(Location));
    newLocation->posX = loc->posX;
    newLocation->posY = loc->posY;

    newPath->current = newLocation;
    newPath->next = p;
    return newPath;
}


// Method to append a location to the path the robot has taken
Path * append(Path * head, Location * loc) {
    Path * new = malloc(sizeof(Path));

    Location * newLocation = malloc(sizeof(Location));
    newLocation->posX = loc->posX;
    newLocation->posY = loc->posY;

    new->current = newLocation;
    new->next = NULL;

    if (head == NULL) {
        return new;
    }

    Path * current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = new;

    return head;
}

