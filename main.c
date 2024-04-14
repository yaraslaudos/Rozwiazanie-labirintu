#include "bibl.h"

int main(int argc, char **argv) {
    Lab *dane = malloc(sizeof(Lab)); //alokacja pamięci dla struktury głównej
    FILE *in, *out; // in - plik do danych wejściowych, out - wyjściowych
    
    //sprawdzanie na błędy 
    if (dane == NULL) return 3;
    if(argc > 1) in = fopen(argv[1], "r"); 
    else return 1;
    if (in == NULL) return 2;
    
    memal(dane, in); //alokacja pamięci dla tablicy przechowującej labirynt

    fclose(in);
    in = fopen(argv[1], "r");

    readfile(dane, in); //zczytywanie ścian w labiryncie i zapis do tablicy

    if(argc > 2) out = fopen(argv[2], "w"); 
    else return 1;

    findpath(dane); //algorymt dla poszukiwania ścieżki (dodaj tu swój algorytm)
    printfile(dane, out); //wypisuje tablice z labiryntem i ścieżką w nim

    fclose(in);
    fclose(out);

    freemem(dane); //zwalnia pamięć dla struktury i tablicy

    return 0;
}
