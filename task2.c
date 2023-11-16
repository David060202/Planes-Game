#include "./utils.h"

void SolveTask2(void *info, int nr_avioane, int N, char **mat) {
    for (int i = 0; i < nr_avioane; i++) {
        short linia = *(short *)(info + 0 + i * 13);
        short coloana = *(short *)(info + 2 + i * 13);
        char directia = ((char *)info)[4 + i * 13];
        char tip = ((char *)info)[5 + i * 13];
        mat[linia][coloana] = '*';
        if (tip == '1') {
            if (directia == 'N') {
                for (int j = coloana - 2; j <= coloana + 2; j++)
                    mat[linia + 1][j] = '*';
                mat[linia + 2][coloana] = '*';
                for (int j = coloana - 1; j <= coloana + 1; j++)
                    mat[linia + 3][j] = '*';
            } else if (directia == 'E') {
                for (int j = linia - 2; j <= linia + 2; j++)
                    mat[j][coloana - 1] = '*';
                mat[linia][coloana - 2] = '*';
                for (int j = linia - 1; j <= linia + 1; j++)
                    mat[j][coloana - 3] = '*';
            } else if (directia == 'W') {
                for (int j = linia - 2; j <= linia + 2; j++)
                    mat[j][coloana + 1] = '*';
                mat[linia][coloana + 2] = '*';
                for (int j = linia - 1; j <= linia + 1; j++)
                    mat[j][coloana + 3] = '*';
            } else {
                for (int j = coloana - 2; j <= coloana + 2; j++)
                    mat[linia - 1][j] = '*';
                mat[linia - 2][coloana] = '*';
                for (int j = coloana - 1; j <= coloana + 1; j++)
                    mat[linia - 3][j] = '*';
            }
        } else {
            if (directia == 'N') {
                for (int j = coloana - 1; j <= coloana + 1; j++)
                    mat[linia + 1][j] = '*';
                for (int j = coloana - 3; j <= coloana + 3; j++)
                    mat[linia + 2][j] = '*';
                mat[linia + 3][coloana] = '*';
                for (int j = coloana - 2; j <= coloana + 2; j++)
                    mat[linia + 4][j] = '*';
            } else if (directia == 'W') {
                for (int j = linia - 1; j <= linia + 1; j++)
                    mat[j][coloana + 1] = '*';
                for (int j = linia - 3; j <= linia + 3; j++)
                    mat[j][coloana + 2] = '*';
                mat[linia][coloana + 3] = '*';
                for (int j = linia - 2; j <= linia + 2; j++)
                    mat[j][coloana + 4] = '*';
            } else if (directia == 'E') {
                for (int j = linia - 1; j <= linia + 1; j++)
                    mat[j][coloana - 1] = '*';
                for (int j = linia - 3; j <= linia + 3; j++)
                    mat[j][coloana - 2] = '*';
                mat[linia][coloana - 3] = '*';
                for (int j = linia - 2; j <= linia + 2; j++)
                    mat[j][coloana - 4] = '*';
            } else {
                for (int j = coloana - 1; j <= coloana + 1; j++)
                    mat[linia - 1][j] = '*';
                for (int j = coloana - 3; j <= coloana + 3; j++)
                    mat[linia - 2][j] = '*';
                mat[linia - 3][coloana] = '*';
                for (int j = coloana - 2; j <= coloana + 2; j++)
                    mat[linia - 4][j] = '*';
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%c", mat[i][j]);
        printf("\n");
    }
}
