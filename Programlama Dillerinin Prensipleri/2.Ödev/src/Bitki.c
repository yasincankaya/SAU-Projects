/**
* @file         G221210021
* @description  Dosyadan sayıları okuyup canlı oluşturarak bu canlıların habitatta birbirini yemesi sağlanıyor.
* @course       2.Öğretim Cgrubu
* @assignment   2. Ödev
* @date         11.05.2024
* @author       yasin.kaya6@ogr.sakarya.edu.tr
*/


#include "Bitki.h"

Bitki BitkiOlustur(int deger,int x,int y){
	Bitki this;
	this = (Bitki)malloc(sizeof(struct BITKI));
	this->super = CanliOlustur(deger,x,y);
	this->yoket = &BitkiYoket;
	this->super->gorunum = &bitkiGorunum;
	return this;
}

void BitkiYoket(const Bitki this){
	if(this == NULL) return;
	this->super->yoket(this->super);
	free(this);
}

char* bitkiGorunum(const Bitki this)
{
	return "B";
}


