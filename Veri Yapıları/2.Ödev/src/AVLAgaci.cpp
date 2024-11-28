/**
* @file 		G221210021
* @description  AVL Ağacı ve yığıt veri yapısında ekleme, yazdırma gibi işlemler yapar.
* @course 		Bilgisayar Mühendisliği 2.Öğretim B grubu
* @assignment 	2. Ödev
* @date 		22.12.2023
* @author 		Yasin Can Kaya yasin.kaya6@ogr.sakarya.edu.tr
*/

#include "AVLAgaci.hpp"
#include <iostream>

using namespace std;

AVLAgaci::AVLAgaci()
{
    kok= 0;
}

AVLAgaci::~AVLAgaci()
{
    yoket(kok);
}

void AVLAgaci::ekle(int eklenecek)
{
    kok = ekle(eklenecek,kok);
}

int AVLAgaci::yukseklik() 
{
	return yukseklik(kok);
}

int AVLAgaci::yukseklik(Dugum* aktifDugum) 
{
	if(aktifDugum)
    {
        return 1+max(   yukseklik(aktifDugum->sol),
                        yukseklik(aktifDugum->sag));
    }
    return -1;
}

Dugum* AVLAgaci::ekle(int veri,Dugum* aktifDugum) 
{
    if(aktifDugum==0)
        return new Dugum(veri);

	else if(aktifDugum->veri<veri)
    {
        aktifDugum->sag=ekle(veri,aktifDugum->sag);
        if(yukseklik(aktifDugum->sag)-yukseklik(aktifDugum->sol)>1)
        {   
            if(veri>aktifDugum->sag->veri)
                aktifDugum = solaDondur(aktifDugum);
                
            else
            {
                aktifDugum->sag = sagaDondur(aktifDugum->sag);
                aktifDugum =solaDondur(aktifDugum);
            }
        }
    }
    else if(aktifDugum->veri>veri)
    {
        aktifDugum->sol = ekle(veri,aktifDugum->sol);
        if(yukseklik(aktifDugum->sol)-yukseklik(aktifDugum->sag)>1)
        {

            if(veri<aktifDugum->sol->veri)
                aktifDugum = sagaDondur(aktifDugum);
            else
            {
                aktifDugum->sol = solaDondur(aktifDugum->sol);
                aktifDugum =sagaDondur(aktifDugum);
            }
        }

    }
    return aktifDugum;
}

Dugum* AVLAgaci::solaDondur(Dugum* buyukEbeveyn) 
{
	Dugum* sagCocuk = buyukEbeveyn->sag;
    buyukEbeveyn->sag = sagCocuk->sol;
    sagCocuk->sol = buyukEbeveyn;
    return sagCocuk;
}

Dugum* AVLAgaci::sagaDondur(Dugum* buyukEbeveyn) 
{
	Dugum* solCocuk = buyukEbeveyn->sol;
    buyukEbeveyn->sol = solCocuk->sag;
    solCocuk->sag = buyukEbeveyn;
    return solCocuk;
}

void AVLAgaci::yapraklariYiginaEkle(Yigin& yigin)
{
    yapraklariYiginaEkle(kok, yigin);
}

void AVLAgaci::yapraklariYiginaEkle(Dugum* aktif, Yigin& yigin)
{
    if (aktif) 
    {
        yapraklariYiginaEkle(aktif->sol, yigin);
        yapraklariYiginaEkle(aktif->sag, yigin);

        if (aktif->sol == nullptr && aktif->sag == nullptr) 
        {
            yigin.ekle(aktif->veri);
        }
    }
}

int AVLAgaci::YerlestirilmeyenleriTopla() const 
{
    return YerlestirilmeyenleriTopla(kok);
}

int AVLAgaci::YerlestirilmeyenleriTopla(Dugum* aktif) const 
{
    if (aktif == nullptr) 
    {
        return 0;
    }

    if (aktif->sol != nullptr || aktif->sag != nullptr) 
    {
        return aktif->veri + YerlestirilmeyenleriTopla(aktif->sol) + YerlestirilmeyenleriTopla(aktif->sag);
    } 
    else 
    {
        return 0;
    }
}

void AVLAgaci::yoket() 
{
    yoket(kok);
}

void AVLAgaci::yoket(Dugum* &aktif) 
{
    if (aktif != nullptr) 
    {
        yoket(aktif->sol);
        yoket(aktif->sag);
        delete aktif;
        aktif = nullptr;
    }
}

bool AVLAgaci::bosmu()
{
    if(kok==nullptr)
    return true;
    else 
    return false;
}

