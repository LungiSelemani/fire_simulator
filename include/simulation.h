#ifndef SIMULATION_H
#define SIMULATION_H

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

// Taille par défaut de la grille
#define SIZE 30
#define TREE 'T'
#define BURNING 'F'
#define ASH 'C'
#define EMPTY '.'


// Déclaration des fonctions
void init_forest(char grid[SIZE][SIZE], float density);
void print_forest(char grid[SIZE][SIZE]);
void propagate_fire(char grid[SIZE][SIZE], char new_grid[SIZE][SIZE]);

#endif