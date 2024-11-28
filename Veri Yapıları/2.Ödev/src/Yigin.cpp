/**
* @file 		G221210021
* @description  AVL Ağacı ve yığıt veri yapısında ekleme, yazdırma gibi işlemler yapar.
* @course 		Bilgisayar Mühendisliği 2.Öğretim B grubu
* @assignment 	2. Ödev
* @date 		22.12.2023
* @author 		Yasin Can Kaya yasin.kaya6@ogr.sakarya.edu.tr
*/

#include "Yigin.hpp"

Yigin::Yigin()
{
    tepe = -1;
    veriler=0;
    kapasite = 5;
    genislet(kapasite);
}

Yigin::~Yigin()
{
    if (veriler != nullptr)
    {
        delete[] veriler;
        veriler = nullptr;
    }

    tepe = -1;
    kapasite = 5;
}

bool Yigin::bosmu()
{
    if(tepe==-1)
        return true;
    return false;
}

void Yigin::ekle(int veri)
{
    if(tepe==kapasite-1)
        genislet(kapasite);

    tepe++;
    veriler[tepe]=veri;
}

void Yigin::cikar()
{
    if(tepe!=-1)
    {
        tepe--;
    }
}

int Yigin::getir()
{
    if(tepe!=-1)
        return veriler[tepe];
}

void Yigin::genislet(int boyut)
{
    int *yeniAlan = new int[boyut+kapasite];
    for(int i=0;i<=tepe;i++)
    {
        
         yeniAlan[i] = veriler[i];   
        
    }
    if(veriler)
        delete[] veriler;
    veriler = yeniAlan;
    kapasite += boyut;
   
}

Yigin::Yigin(const Yigin& diger)
    : tepe(diger.tepe), kapasite(diger.kapasite), veriler(new int[diger.kapasite])
{
    for (int i = 0; i <= tepe; i++) 
    {
        veriler[i] = diger.veriler[i];
    }
}

Yigin& Yigin::operator=(const Yigin& diger)
{
    if (this != &diger) 
    {
        delete[] veriler; 

        tepe = diger.tepe;
        kapasite = diger.kapasite;
        veriler = new int[diger.kapasite];

        for (int i = 0; i <= tepe; i++) 
        {
            veriler[i] = diger.veriler[i];
        }
    }

    return *this;
}

void Yigin::yoket()
{
    if (veriler != nullptr)
    {
        delete[] veriler;
        veriler = nullptr;
    }

    tepe = -1;
    kapasite = 5;
}