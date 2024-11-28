#ifndef CANLI_H
#define CANLI_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct CANLI {
    int deger;
    int x,y;
    char* (*toString)(struct CANLI*, void*);
    void (*yoket)(struct CANLI*);
    char* (*gorunum)();
    
};

typedef struct CANLI* Canli;

Canli CanliOlustur(int,int,int);
char* toString(const Canli, void*);
void CanliYoket(const Canli);


#endif
