#include "..\include\simulation.h"

void init_forest(char grid[SIZE][SIZE], float density) {
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if ((rand() % 100) < density * 100)
                grid[i][j] = TREE;
            else
                grid[i][j] = EMPTY;
        }
    }
    // Allumer le feu au centre
    grid[SIZE/2][SIZE/2] = BURNING;
}

void print_forest(char grid[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void propagate_fire(char grid[SIZE][SIZE], char new_grid[SIZE][SIZE]) {
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (grid[i][j] == BURNING) {
                new_grid[i][j] = ASH;

                // Propagation aux voisins
                int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
                int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

                for (int k = 0; k < 8; k++) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];

                    if (ni >= 0 && ni < SIZE && nj >= 0 && nj < SIZE) {
                        if (grid[ni][nj] == TREE)
                            new_grid[ni][nj] = BURNING;
                    }
                }
            } else if (grid[i][j] == TREE || grid[i][j] == EMPTY || grid[i][j] == ASH) {
                new_grid[i][j] = grid[i][j];
            }
        }
    }
}
