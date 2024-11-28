/**
* @file 		G221210021
* @description  AVL Ağacı ve yığıt veri yapısında ekleme, yazdırma gibi işlemler yapar.
* @course 		Bilgisayar Mühendisliği 2.Öğretim B grubu
* @assignment 	2. Ödev
* @date 		22.12.2023
* @author 		Yasin Can Kaya yasin.kaya6@ogr.sakarya.edu.tr
*/

#include "Dugum.hpp"
#include <iostream>

using namespace std;

Dugum::Dugum(int veri)
{
    this->veri = veri;
    sol=sag=0;
}
