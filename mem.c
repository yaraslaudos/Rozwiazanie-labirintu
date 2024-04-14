#include "bibl.h"

 
void memal(Lab *dane, FILE *in) {
    int w = 1; //wiersz
    int k = 0; //kolumna
    char c; //symbol
    while((c = fgetc(in)) != EOF) {  //kod zczytuje każdy symbol po koleje i przenoszenie na kolejny wiersz
        switch (c)
        {
        case '\n':
            w++;
            break;
        default:
            k++;
            break;
        }
    }
    
    k /= w; // po dzieleniu otrzymujemy ilość kolumn
    dane->w = w; 
    dane->k = k;

    printf("%d, %d", k, w); //można usunąć jak chcesz

    //alokacja pamięci dla tablicy
    dane->lab = (int **)malloc(w * sizeof(int*));
    if (dane->lab == NULL) exit(EXIT_FAILURE);
    int i;
    for (i = 0; i < w; i++) {
        dane->lab[i] = (int *)malloc(k * sizeof(int));
        if (dane->lab[i] == NULL) exit(EXIT_FAILURE);
    }
} 

//zwolnienie pamięci
void freemem(Lab *dane) {
    for (int i = 0; i < dane->w; ++i) {
        free(dane->lab[i]);
    }
    free(dane->lab);
    free(dane);
}
