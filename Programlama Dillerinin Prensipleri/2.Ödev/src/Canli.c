/**
* @file         G221210021
* @description  Dosyadan sayıları okuyup canlı oluşturarak bu canlıların habitatta birbirini yemesi sağlanıyor.
* @course       2.Öğretim Cgrubu
* @assignment   2. Ödev
* @date         11.05.2024
* @author       yasin.kaya6@ogr.sakarya.edu.tr
*/


#include "Canli.h"


Canli CanliOlustur(int deger,int x,int y) {
    Canli this = (Canli)malloc(sizeof(struct CANLI));
    this->deger=deger;
    this->x=x;
    this->y=y;
    this->toString = &toString;
    this->yoket = &CanliYoket;
    return this;
}

char* toString(const Canli this, void* p) {
    int toplamUzunluk = 4;
	toplamUzunluk += strlen(this->gorunum(p));
	char* str = (char*)malloc(sizeof(char)*toplamUzunluk+1);
	sprintf(str,"%s ",this->gorunum(p));
											
    return str;
}

void CanliYoket(const Canli this) {
    if (this == NULL) return;
    free(this);
}

