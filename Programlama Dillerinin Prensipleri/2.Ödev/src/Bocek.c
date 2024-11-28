/**
* @file         G221210021
* @description  Dosyadan sayıları okuyup canlı oluşturarak bu canlıların habitatta birbirini yemesi sağlanıyor.
* @course       2.Öğretim Cgrubu
* @assignment   2. Ödev
* @date         11.05.2024
* @author       yasin.kaya6@ogr.sakarya.edu.tr
*/


#include "Bocek.h"

Bocek BocekOlustur(int deger,int x,int y){
	Bocek this;
	this = (Bocek)malloc(sizeof(struct BOCEK));
	this->super = CanliOlustur(deger,x,y);
	this->yoket = &BocekYoket;
	this->super->gorunum = &bocekGorunum;
	return this;
}

void BocekYoket(const Bocek this){
	if(this == NULL) return;
	this->super->yoket(this->super);
	free(this);
}

char* bocekGorunum(const Bocek this)
{
	return "C";
}