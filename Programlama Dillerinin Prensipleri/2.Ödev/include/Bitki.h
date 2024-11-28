#ifndef BITKI_H
#define BITKI_H
#include "Canli.h"

struct BITKI
{
    Canli super;
	void (*yoket)(struct BITKI*);
};

typedef struct BITKI* Bitki;

Bitki BitkiOlustur(int,int,int);
void BitkiYoket(const Bitki);
char* bitkiGorunum(const Bitki);


#endif
