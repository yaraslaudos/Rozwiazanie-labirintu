#include "bibl.h"

void readfile(Lab *dane, FILE *in) {
    char c;
    dane->x = 0;
    dane->y = 0;
    while((c = fgetc(in)) != EOF) { //zczytuje każdy symbol i zapisuje do macierzy w postaci odpowiednich liczb
        switch (c)
        {
        case 'X':
            dane->lab[dane->y][dane->x] = 1; // 1 - ściana
            dane->x++;
            break;
        case ' ':
            dane->lab[dane->y][dane->x] = 0; //0 - puste pole
            dane->x++;
            break;
        case 'P':
            dane->lab[dane->y][dane->x] = 2;// 2 - początek
            dane->x++;
            break;
        case 'K':
            dane->lab[dane->y][dane->x] = 4;//4 - koniec
            dane->x++;
            printf("Koniec znaj");
            break;
        case '\n': //przechodzimy na nowy wiersz w macierze
            dane->y++;
            dane->x = 0;
            break;
        }
    }
}

//wypisuje tablice (macierz)
void printfile(Lab *dane, FILE *out) {
    int i, j;
    for(i = 0; i < dane->w; i++) {
        fprintf(out, "\n");
        for(j = 0; j < dane->k; j++) {
            fprintf(out, "%d", dane->lab[i][j]);
        }
    }
}
