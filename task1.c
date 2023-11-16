#include "./utils.h"

void SolveTask1(void *info, int nr_avioane) {
    for (int i = 0; i < nr_avioane; i++) {
        short linia = *(short *)(info + 0 + i * 13);
        printf("(%hu, ", linia);
        short coloana = *(short *)(info + 2 + i * 13);
        printf("%hu)\n", coloana);
        char directia = ((char *)info)[4 + i * 13];
        printf("%c\n", directia);
        char tip = ((char *)info)[5 + i * 13];
        char cod1 = ((char *)info)[6 + i * 13];
        char cod2 = ((char *)info)[7 + i * 13];
        char cod3 = ((char *)info)[8 + i * 13];
        printf("%c%c%c%c\n", tip, cod1, cod2, cod3);
        int viteza = *(int *)(info + 9 + i * 13);
        printf("%d\n", viteza);
        printf("\n");
    }
}
