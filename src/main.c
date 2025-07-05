#include "..\src\simulation.h"


int main() {
    char forest[SIZE][SIZE];
    char new_forest[SIZE][SIZE];

    init_forest(forest, 0.6f); // Densité d'arbres à 60%

    printf("Forêt initiale :\n");
    print_forest(forest);

    for (int step = 0; step < 10; step++) {
        printf("Étape %d\n", step + 1);
        propagate_fire(forest, new_forest);

        // Échange des grilles : copier new_forest dans forest
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                forest[i][j] = new_forest[i][j];
            }
        }

        print_forest(forest);
    }

    return 0;
}
