//
// robot.c
// 308 Final Project
//
// Created by Dylan Staatz and Trey Schmidt
//


#include "maze.h"
#include "types.h"
#include "robot.h"


int delta[][] = {
    { 0, -1 }, // up
    { -1, 0 }, // left
    { 0, 1 }, // down
    { 1, 0 } // right
};


Robot * InitalizeRobot(Maze * m) {
    Robot * newRobot = malloc(sizeof(Robot));
    newRobot->m = m;
    newRobot->l = m->start;
    newRobot->p = add(NULL, newRobot->l);
    return newRobot;
}


void UpdateRobotMaze(Robot * r, ScanResults * s){
    int i; int j;

    // North, up, (0, -1)
    j = s->l->posx + delta[0][0];
    i = s->l->posy + delta[0][1];
    r->m->cells[i][j] = s->N;

    // West, left, (-1, 0)
    j = s->l->posx + delta[1][0];
    i = s->l->posy + delta[1][1];
    r->m->cells[i][j] = s->W;

    // South, down, (0, 1)
    j = s->l->posx + delta[2][0];
    i = s->l->posy + delta[2][1];
    r->m->cells[i][j] = s->S;

    // East right, (1, 0)
    j = s->l->posx + delta[3][0];
    i = s->l->posy + delta[3][1];
    r->m->cells[i][j] = s->E;
}


void FloodFill(Robot * r) {

    int newValue;

    Location * goal = r->m->start;

    for (int i = 0; i < r->m->height; i++) {
        for (int j = 0; i < r->m->width; j++) {
            r->values[i][j] = 99;
        }
    }

    int change = TRUE;

    while(change) {
        change = FALSE;

        for (int i = 0; i < r->m->height; i++) {
            for (int j = 0; i < r->m->width; j++) {
                if(lociseq(goal, r->l)) {
                    if (r->values[i][j] > 0) {
                        r->values[i][j] = 0;
                        change = TRUE;
                    }
                }
                else if (r->m->cells[i][j] == 0) {
                    for (int a = 0; a < 4; a++) {
                        y = i + delta[a][1]; // The next y value to update
                        x = j + delta[a][0]; // The next x value to update

                        if (x >= 0 && x < r->m->height && y >=0 && y < r->m->width) {
                            if (r->m->cells[x][y] == 0) {
                                newValue = r->values[x][y] + 1;

                                if (newValue < r->values[i][j]) {
                                    r->values[i][j] = newValue;
                                    change = TRUE;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

// Check all directions and move
// to the one with the lowest value
void MoveRobot(Robot * r) {
    int minDir = 0;
    int min = 99;
    int i; int j;
    int val;

    j = s->l->posx + delta[minDir][0];
    i = s->l->posy + delta[minDir][1];

    val = r->values[i][j];
    if (val < min) {
        
    }
    for (int a = 1; a < 4; a++) {
        
    }


}

void PrintRobotPath(Robot * r);

