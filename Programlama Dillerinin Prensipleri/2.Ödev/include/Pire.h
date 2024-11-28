#ifndef PIRE_H
#define PIRE_H
#include "Bocek.h"

struct PIRE
{
    Bocek super;
	void (*yoket)(struct PIRE*);
};

typedef struct PIRE* Pire;

Pire PireOlustur(int,int,int);
void PireYoket(const Pire);
char* pireGorunum(const Pire);


#endif