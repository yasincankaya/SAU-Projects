#ifndef SINEK_H
#define SINEK_H
#include "Bocek.h"

struct SINEK
{
    Bocek super;
	void (*yoket)(struct SINEK*);
};

typedef struct SINEK* Sinek;

Sinek SinekOlustur(int,int,int);
void SinekYoket(const Sinek);
char* sinekGorunum(const Sinek);


#endif