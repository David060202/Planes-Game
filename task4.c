#include "./utils.h"

void SolveTask4(void *info, int nr_avioane, int nr_obstacole, int *x, int *y, int N) {
    // malloc
    char **mat = (char **)malloc(2 * N * sizeof(char *));
    for (int i = 0; i < N; i++)
        mat[i] = (char *)malloc(2 * N * sizeof(char));
    // body

    // initializare matrice
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            mat[i][j] = '.';
    // punere obstacole in matrice
    for (int i = 0; i < nr_obstacole; i++) {
        int x1 = x[i];
        int y1 = y[i];
        mat[x1][y1] = '@';
    }
    // incepe numerotarea
    int count = 0;
    for (int i = 0; i < nr_avioane; i++) {
        short linia = *(short *)(info + 0 + i * 13);
        short coloana = *(short *)(info + 2 + i * 13);
        char directia = ((char *)info)[4 + i * 13];
        char tip = ((char *)info)[5 + i * 13];
        mat[linia][coloana] = '*';
        if (tip == '1') {
            if (directia == 'N') {
                count++;
                int ok = 1;
                for (int j = coloana - 2; j <= coloana + 2 && mat[linia][j] != '@'; j++)
                    mat[linia + 1][j] = '*';
                mat[linia + 2][coloana] = '*';
                for (int j = coloana - 1; j <= coloana + 1 && mat[linia][j] != '@'; j++)
                    mat[linia + 3][j] = '*';
                for (int j = 0; j <= linia + 3 && ok; j++)
                    for (int h = coloana - 1; h <= coloana + 1 && ok; h++)
                        if (mat[j][h] == '@') {
                            count--;
                            ok = 0;
                        }
                for (int j = 0; j <= linia + 1 && ok; j++)
                    for (int h = coloana - 2; h <= coloana + 2 && ok; h++)
                        if (mat[j][h] == '@') {
                            count--;
                            ok = 0;
                        }
            } else if (directia == 'E') {
                count++;
                int ok = 1;
                for (int j = linia - 2; j <= linia + 2 && mat[j][coloana] != '@'; j++)
                    mat[j][coloana - 1] = '*';
                mat[linia][coloana - 2] = '*';
                for (int j = linia - 1; j <= linia + 1 && mat[j][coloana] != '@'; j++)
                    mat[j][coloana - 3] = '*';
                for (int j = linia - 1; j <= linia + 1 && ok; j++)
                    for (int h = coloana - 3; h <= N && ok; h++)
                        if (mat[j][h] == '@') {
                            count--;
                            ok = 0;
                        }
                for (int j = linia - 2; j <= linia + 2 && ok; j++)
                    for (int h = coloana - 1; h <= N && ok; h++)
                        if (mat[j][h] == '@') {
                            count--;
                            ok = 0;
                        }
            } else if (directia == 'W') {
                count++;
                int ok = 1;
                for (int j = linia - 2; j <= linia + 2; j++)
                    mat[j][coloana + 1] = '*';
                mat[linia][coloana + 2] = '*';
                for (int j = linia - 1; j <= linia + 1; j++)
                    mat[j][coloana + 3] = '*';
                for (int i = 0; i < nr_obstacole; i++) {
                    int x1 = x[i];
                    int y1 = y[i];
                    mat[x1][y1] = '@';
                }
                for (int j = linia - 1; j <= linia + 1 && ok; j++)
                    for (int h = 0; h <= coloana + 3 && ok; h++)
                        if (mat[j][h] == '@') {
                            count--;
                            ok = 0;
                        }
                for (int j = linia - 2; j <= linia + 2 && ok; j++)
                    for (int h = 0; h <= coloana + 1 && ok; h++)
                        if (mat[j][h] == '@') {
                            count--;
                            ok = 0;
                        }
            } else if (directia == 'S') {
                count++;
                int ok = 1;
                for (int j = coloana - 2; j <= coloana + 2; j++)
                    mat[linia - 1][j] = '*';
                mat[linia - 2][coloana] = '*';
                for (int j = coloana - 1; j <= coloana + 1; j++)
                    mat[linia - 3][j] = '*';
                for (int j = linia - 3; j < N && ok; j++)
                    for (int h = coloana - 1; h <= coloana + 1 && ok; h++)
                        if (mat[j][h] == '@') {
                            count--;
                            ok = 0;
                        }
                for (int j = linia - 1; j < N && ok; j++)
                    for (int h = coloana - 2; h <= coloana + 2 && ok; h++)
                        if (mat[j][h] == '@') {
                            count--;
                            ok = 0;
                        }
            }
        } else if (tip == '2') {
            if (directia == 'N') {
                count++;
                int ok = 1;
                for (int j = coloana - 1; j <= coloana + 1; j++)
                    mat[linia + 1][j] = '*';
                for (int j = coloana - 3; j <= coloana + 3; j++)
                    mat[linia + 2][j] = '*';
                mat[linia + 3][coloana] = '*';
                for (int j = coloana - 2; j <= coloana + 2; j++)
                    mat[linia + 4][j] = '*';
                for (int j = 0; j <= linia + 4 && ok; j++)
                    for (int h = coloana - 2; h <= coloana + 2 && ok; h++)
                        if (mat[j][h] == '@') {
                            count--;
                            ok = 0;
                        }
                for (int j = 0; j <= linia + 2 && ok; j++)
                    for (int h = coloana - 3; h <= coloana + 3 && ok; h++)
                        if (mat[j][h] == '@') {
                            count--;
                            ok = 0;
                        }
            } else if (directia == 'W') {
                count++;
                int ok = 1;
                for (int j = linia - 1; j <= linia + 1; j++)
                    mat[j][coloana + 1] = '*';
                for (int j = linia - 3; j <= linia + 3; j++)
                    mat[j][coloana + 2] = '*';
                mat[linia][coloana + 3] = '*';
                for (int j = linia - 2; j <= linia + 2; j++)
                    mat[j][coloana + 4] = '*';
                for (int j = linia - 2; j <= linia + 2 && ok; j++)
                    for (int h = 0; h <= coloana + 4 && ok; h++)
                        if (mat[j][h] == '@') {
                            count--;
                            ok = 0;
                        }
                for (int j = linia - 3; j <= linia + 3 && ok; j++)
                    for (int h = 0; h <= coloana + 2 && ok; h++)
                        if (mat[j][h] == '@') {
                            count--;
                            ok = 0;
                        }
            } else if (directia == 'E') {
                count++;
                int ok = 1;
                for (int j = linia - 1; j <= linia + 1; j++)
                    mat[j][coloana - 1] = '*';
                for (int j = linia - 3; j <= linia + 3; j++)
                    mat[j][coloana - 2] = '*';
                mat[linia][coloana - 3] = '*';
                for (int j = linia - 2; j <= linia + 2; j++)
                    mat[j][coloana - 4] = '*';
                for (int j = linia - 2; j <= linia + 2 && ok; j++)
                    for (int h = coloana - 4; h < N && ok; h++)
                        if (mat[j][h] == '@') {
                            count--;
                            ok = 0;
                        }
                for (int j = linia - 3; j <= linia + 3 && ok; j++)
                    for (int h = coloana - 2; h < N && ok; h++)
                        if (mat[j][h] == '@') {
                            count--;
                            ok = 0;
                        }
            } else if (directia == 'S') {
                count++;
                int ok = 1;
                for (int j = coloana - 1; j <= coloana + 1; j++)
                    mat[linia - 1][j] = '*';
                for (int j = coloana - 3; j <= coloana + 3; j++)
                    mat[linia - 2][j] = '*';
                mat[linia - 3][coloana] = '*';
                for (int j = coloana - 2; j <= coloana + 2; j++)
                    mat[linia - 4][j] = '*';
                for (int j = linia - 4; j < N && ok; j++)
                    for (int h = coloana - 2; h <= coloana + 2 && ok; h++)
                        if (mat[j][h] == '@') {
                            count--;
                            ok = 0;
                        }
                for (int j = linia - 2; j < N && ok; j++)
                    for (int h = coloana - 3; h <= coloana + 3 && ok; h++)
                        if (mat[j][h] == '@') {
                            count--;
                            ok = 0;
                        }
            }
        }
    }

    printf("%d\n", count);

    // free
    for (int i = 0; i < N; i++)
        free(mat[i]);
    free(mat);
}
