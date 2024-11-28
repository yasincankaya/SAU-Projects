/**
* @file         G221210021
* @description  Dosyadan sayıları okuyup canlı oluşturarak bu canlıların habitatta birbirini yemesi sağlanıyor.
* @course       2.Öğretim Cgrubu
* @assignment   2. Ödev
* @date         11.05.2024
* @author       yasin.kaya6@ogr.sakarya.edu.tr
*/


#include "Sinek.h"

Sinek SinekOlustur(int deger,int x,int y){
	Sinek this;
	this = (Sinek)malloc(sizeof(struct SINEK));
	this->super = BocekOlustur(deger,x,y);
	this->yoket = &SinekYoket;
	this->super->super->gorunum = &sinekGorunum;
	return this;
}

void SinekYoket(const Sinek this){
	if(this == NULL) return;
	this->super->yoket(this->super);
	free(this);
}

char* sinekGorunum(const Sinek this)
{
	return "S";
}