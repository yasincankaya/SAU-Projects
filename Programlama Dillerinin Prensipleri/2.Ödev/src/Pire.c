/**
* @file         G221210021
* @description  Dosyadan sayıları okuyup canlı oluşturarak bu canlıların habitatta birbirini yemesi sağlanıyor.
* @course       2.Öğretim Cgrubu
* @assignment   2. Ödev
* @date         11.05.2024
* @author       yasin.kaya6@ogr.sakarya.edu.tr
*/


#include "Pire.h"

Pire PireOlustur(int deger,int x,int y){
	Pire this;
	this = (Pire)malloc(sizeof(struct PIRE));
	this->super = BocekOlustur(deger,x,y);
	this->yoket = &PireYoket;
	this->super->super->gorunum = &pireGorunum;
	return this;
}

void PireYoket(const Pire this){
	if(this == NULL) return;
	this->super->yoket(this->super);
	free(this);
}

char* pireGorunum(const Pire this)
{
	return "P";
}
