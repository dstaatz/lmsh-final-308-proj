//
// robot.c
// 308 Final Project
//
// Created by Dylan Staatz and Trey Schmidt
//

#include <stdlib.h>
#include <stdio.h>

#include "maze.h"
#include "types.h"
#include "robot.h"


int delta[][2] = {
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
    j = s->l->posX + delta[0][0];
    i = s->l->posY + delta[0][1];
    r->m->cells[i][j] = s->N;

    // West, left, (-1, 0)
    j = s->l->posX + delta[1][0];
    i = s->l->posY + delta[1][1];
    r->m->cells[i][j] = s->W;

    // South, down, (0, 1)
    j = s->l->posX + delta[2][0];
    i = s->l->posY + delta[2][1];
    r->m->cells[i][j] = s->S;

    // East right, (1, 0)
    j = s->l->posX + delta[3][0];
    i = s->l->posY + delta[3][1];
    r->m->cells[i][j] = s->E;
}


void FloodFill(Robot * r) {
    int x; int y;
    int newValue;

    Location * goal = r->m->end;

    for (int i = 0; i < r->m->height; i++) {
        for (int j = 0; j < r->m->width; j++) {
            r->values[i][j] = 99;
        }
    }

    int change = TRUE;

    while(change) {
        change = FALSE;

        for (int i = 0; i < r->m->height; i++) {
            for (int j = 0; j < r->m->width; j++) {
                if(goal->posX == j && goal->posY == i) {
                    if (r->values[i][j] > 0) {
                        r->values[i][j] = 0;
                        change = TRUE;
                    }
                }
                else if (r->m->cells[i][j] == 0) {
                    for (int a = 0; a < 4; a++) {
                        y = i + delta[a][1]; // The next y value to update
                        x = j + delta[a][0]; // The next x value to update

                        if (x >= 0 && x < r->m->width && y >=0 && y < r->m->height) {
                            if (r->m->cells[y][x] == 0) {
                                newValue = r->values[y][x] + 1;

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

/*    for (int i = 0; i < r->m->height; i++) {
        for (int j = 0; j < r->m->width; j++) {
            printf("%d%d ", r->values[i][j] / 10, r->values[i][j] % 10);
        }
        printf("\n");
    }*/
}


// Check all directions and move
// to the one with the lowest value
void MoveRobot(Robot * r) {
    int minDir = 0;
    int min = 99;
    int i; int j;
    int val;

    j = r->l->posX + delta[minDir][0];
    i = r->l->posY + delta[minDir][1];

    val = r->values[i][j];
    if (val < min) {
        minDir = 0;
        min = val;
    }
    for (int a = 1; a < 4; a++) {
        j = r->l->posX + delta[a][0];
        i = r->l->posY + delta[a][1];

        val = r->values[i][j];
        if (val < min) {
            minDir = a;
            min = val;
        }
    }

    // Move in the minimum direction
    r->l->posX += delta[minDir][0];
    r->l->posY += delta[minDir][1];

    r->p = append(r->p, r->l);
}


void PrintRobotPath(Robot * r) {

    char printableMaze[r->m->height][r->m->width];

    int i = 0;
    int j = 0;
    for (i = 0; i < r->m->height; i++)
    {
      for (j = 0; j < r->m->width; j++)
      {
        if (r->m->cells[i][j] == 1) printableMaze[i][j] = 'X';
        else if (r->m->cells[i][j] == 0) printableMaze[i][j] = ' ';
      }
    }

    Path * current = r->p;

    while(current != NULL) {
        printableMaze[current->current->posY][current->current->posX] = '#';
        // printf("(%d, %d)\n", current->current->posX, current->current->posY);
        current = current->next;
    }

    for (i = 0; i < r->m->height; i++)
    {
      for (j = 0; j < r->m->width; j++)
      {
          printf("%c", printableMaze[i][j]);
      }
      printf("\n");
    }

}

