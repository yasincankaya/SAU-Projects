/**
* @file 		G221210021
* @description  Bağlı liste veri yapısında çeşitli işlemler gerçekleştirir.
* @course 		Bilgisayar Mühendisliği 2.Öğretim B grubu
* @assignment 	1. Ödev
* @date 		26.11.2023
* @author 		Yasin Can Kaya yasin.kaya6@ogr.sakarya.edu.tr
*/

#include "SayilarListesi.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

SayilarListesi::SayilarListesi() : ilk(nullptr) {}

SayilarListesi::~SayilarListesi() 
{
    
    Dugum* gecici=ilk;
    while (gecici != nullptr) 
    {
        Dugum* sil=gecici;
        gecici=gecici->sonraki;
        delete sil;
    }
    
}



void SayilarListesi::olusturDugumler(int sayi)      //sayılistesinin basamakları ile düğüm oluşturan fonksiyon
{
    Dugum* yeni = nullptr;

    while (sayi > 0) 
    {
        int basamak = sayi % 10;
        Dugum* temp = new Dugum(basamak);
        temp->sonraki = yeni;
        yeni = temp;
        sayi /= 10;
    }

    if (ilk == nullptr) 
    {
        cout << "Ilk deger atandi." << endl;
        ilk = yeni;
    } 
    else 
    {
        yeni->sonraki = ilk;
        ilk = yeni;
    }

    Dugum* gecici = ilk;
    while (gecici != nullptr) 
    {
        cout << "Dugum adresi: " << gecici << ", Dugum verisi: " << gecici->veri << endl;
        gecici = gecici->sonraki;
    }
}


void SayilarListesi::listeYazdir()          //listeyi düzenli biçimde ekrana yazdıran fonksiyon
{
  Dugum* gecici = ilk;
  int i=0;
  int a=0;
    while (gecici != nullptr) 
    {
        gecici = gecici->sonraki;
        i++;
    }
    gecici=ilk;
    cout<< "###########";

    while(a<i)
    {
      cout<<" ******* ";
      a++;
    }
    cout<<endl;

    cout <<"#"<<setfill(' ')<<setw(9)<<this<<"#";

    while (gecici != nullptr) 
    {
        cout<<" * "<< setfill(' ')<<setw(3)<< hex << setfill('0') << (reinterpret_cast<int>(gecici) % 0x1000) << dec <<" * ";
        gecici = gecici->sonraki;
    }
    cout<<endl<<"#---------#";
    a=0;
    gecici=ilk;
    while(a<i)
    {
      cout<<" ******* ";
      a++;
    }
    cout<<endl;
    cout <<"#";

    gecici=ilk;
    int birlesimSayi = 0;
    while (gecici != nullptr) 
    {
      birlesimSayi = birlesimSayi * 10 + gecici->veri;
      gecici = gecici->sonraki;  
    }

    gecici=ilk;
    cout<<setfill(' ')<<setw(9)<<birlesimSayi<<"#";

    while (gecici != nullptr) 
    {
      cout<<" * "<<setfill(' ')<<setw(3)<<gecici->veri<<" * ";
      gecici = gecici->sonraki;
    }
    gecici=ilk;
    cout<<endl;
    cout<< "###########";
    a=0;
    while(a<i)
    {
      cout<<" ******* ";
      a++;
    }
    cout<<endl;
}

void SayilarListesi::tekBasa()              //verisi tek sayı olan düğümleri ilk sıraya geçiren fonksiyon
{
    Dugum* gecici = ilk;

    while (gecici != nullptr && gecici->veri % 2 == 0) {
        gecici = gecici->sonraki;
    }

    while (gecici != nullptr) {
        while (gecici != nullptr && gecici->veri % 2 == 0) {
            gecici = gecici->sonraki;
        }

        if (gecici != nullptr) {
            Dugum* temp = gecici;
            gecici = gecici->sonraki;

            if (temp != ilk) {
                Dugum* onceki = ilk;
                while (onceki->sonraki != temp) {
                    onceki = onceki->sonraki;
                }
                onceki->sonraki = temp->sonraki;
            } else {
                ilk = temp->sonraki;
            }

            temp->sonraki = ilk;
            ilk = temp;
        }
    }
}

void SayilarListesi::tersCevir()            //düğümleri ters çeviren fonksiyon
{
    Dugum* suanki = ilk;
    Dugum* sonraki = nullptr;

    while (suanki != nullptr) 
    {
        Dugum* gecici = suanki->sonraki;
        suanki->sonraki = sonraki;
        sonraki = suanki;
        suanki = gecici;
    }

    ilk = sonraki;
}

int SayilarListesi::birlesimSayiBul()           //düğümlerin birleşimi olan sayıyı bulan fonksiyon
{
    Dugum* gecici = ilk;
    int birlesimSayi = 0;
    while (gecici != nullptr) 
    {
      birlesimSayi = birlesimSayi * 10 + gecici->veri;
      gecici = gecici->sonraki;  
    }
    return birlesimSayi;
}
 


