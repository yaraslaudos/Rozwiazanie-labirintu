#ifndef _BIBL_H
#define _BIBL_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

struct _Lab {
    int **lab; // tablica (macierz) w której przechowujemy labirynt
    int x; //współrzędne dla poruszania się w labiryncie
    int y;
    int w; // ilość wierszów i kolumn
    int k;
};

//stos
typedef struct punkt {
    int x;
    int y;
    struct punkt *next;
} *punkt_t;

typedef struct {
    punkt_t head;
    int n;
} *stos_t;


typedef struct _Lab Lab; //deklaracja struktury
stos_t init_stos();// dla stosu
void memal(Lab *dane, FILE *in);
void push( stos_t s, int x, int y );// dla stosu
void pop( stos_t s, Lab *dane);// dla stosu
void readfile(Lab *dane, FILE *in);
void findpath(Lab *dane);
void printfile(Lab *dane, FILE *out);
void freemem(Lab *dane);

#endif
