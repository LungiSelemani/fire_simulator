int main() {
    char forest[SIZE][SIZE];
    char new_forest[SIZE][SIZE];

    init_forest(forest, 0.6f);
    print_forest(forest);

    for (int step = 0; step < 10; step++) {
        propagate_fire(forest, new_forest);

        // Copie new_forest dans forest
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                forest[i][j] = new_forest[i][j];
            }
        }

        printf("Step %d\n", step + 1);
        print_forest(forest);
    }

    return 0;
}