#ifndef BOCEK_H
#define BOCEK_H
#include "Canli.h"

struct BOCEK
{
    Canli super;
	void (*yoket)(struct BOCEK*);
};

typedef struct BOCEK* Bocek;

Bocek BocekOlustur(int,int,int);
void BocekYoket(const Bocek);
char* bocekGorunum(const Bocek);


#endif
