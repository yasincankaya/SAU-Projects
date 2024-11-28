#ifndef HABITAT_H
#define HABITAT_H

#include "Bitki.h"
#include "Pire.h"
#include "Sinek.h"


struct HABITAT {
    
    int canliSayisi;
    Bitki** bitki_matris;
    Bocek** bocek_matris;
    Sinek** sinek_matris;
    Pire** pire_matris;
    Bitki** (*bitkiMatrisiOlustur)(int,int,int**);
    Bocek** (*bocekMatrisiOlustur)(int,int,int**);
    Sinek** (*sinekMatrisiOlustur)(int,int,int**);
    Pire** (*pireMatrisiOlustur)(int,int,int**);
    void (*HabitatEkranaYazdir)(struct HABITAT*, int, int);
    void (*yoket)(struct HABITAT*,int);
    int (*CanliSayisiniGetir)(struct HABITAT*,int,int);
};

typedef struct HABITAT* Habitat;

Habitat HabitatOlustur();
Habitat YemeIslemleriYap(const Habitat,int,int);
void HabitatEkranaYazdir(const Habitat, int,int);
void HabitatYoket(const Habitat,int);
Bitki** bitkiMatrisiOlustur(int,int,int**);
Bocek** bocekMatrisiOlustur(int,int,int**);
Sinek** sinekMatrisiOlustur(int,int,int**);
Pire** pireMatrisiOlustur(int,int,int**);
int CanliSayisiniGetir(const Habitat,int,int);



#endif