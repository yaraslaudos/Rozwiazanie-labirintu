#include "bibl.h"

void findpath(Lab *dane) {
    stos_t s = init_stos();

    int i, j;
    //find start
    for(i = 0; i < dane->w; i++) {
        for(j = 0; j < dane->k; j++) {
            if(dane->lab[i][j] == 2 )  {
                push(s, j, i);
                dane->x = j;
                dane->y = i;
                break;
            }
        }
    }
    printf("\n Start: %d, %d \n", dane->x, dane->y);
    //
    while (dane->lab[dane->y][dane->x] != 4) {
        if(dane->lab[dane->y][dane->x + 1] == 0 && dane->x + 1 < dane->k) {

            dane->x++;
            push(s, dane->x, dane->y);
            dane->lab[dane->y][dane->x] = 2;
        } else if(dane->lab[dane->y + 1][dane->x] == 0 && dane->y + 1 < dane->w) {
            dane->y++;
            push(s, dane->x, dane->y);
            dane->lab[dane->y][dane->x] = 2;
        } else if(dane->lab[dane->y - 1][dane->x] == 0 && dane->y - 1 >= 0) {
            dane->y--;
            push(s, dane->x, dane->y);
            dane->lab[dane->y][dane->x] = 2;
        } else if(dane->lab[dane->y][dane->x - 1] == 0 && dane->x - 1 >= 0) {
            dane->x--;
            push(s, dane->x, dane->y);
            dane->lab[dane->y][dane->x] = 2;
        } else if(dane->lab[dane->y][dane->x + 1] == 4 || dane->lab[dane->y + 1][dane->x] == 4 || dane->lab[dane->y - 1][dane->x] == 4 || dane->lab[dane->y][dane->x - 1] == 4) {
            break;
        } else {
            pop(s, dane);
        }

    }
    free(s);
}

stos_t init_stos() {
	stos_t s = malloc( sizeof *s );
	s->head = NULL;
	s->n = 0;
	return s;
}

void push( stos_t s, int x, int y ) {
	punkt_t nowy = malloc( sizeof *nowy );
	nowy->x = x;
    nowy->y = y;
	nowy->next = s->head;
	s->head = nowy;
	s->n++;
}

void pop( stos_t s, Lab *dane ) {
	if( s->head == NULL ) {
		return;
	}
    dane->lab[s->head->y][s->head->x] = 3;
	punkt_t stary = s->head;
	s->head = s->head->next;
    if (s->head != NULL) {
    dane->x = s->head->x;
    dane->y = s->head->y;
    }
	free( stary );
	s->n--;
}
