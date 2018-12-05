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

Path * add(Path * p, Location * loc) {
    Path * new = malloc(sizeof(Path));
    new->current = loc;
    new->next = p;
    return new;
}

/*
Path * append(Path * head, Location * loc) {
    Path * new = malloc(sizeof(Path));
    new->current = loc;
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
*/
