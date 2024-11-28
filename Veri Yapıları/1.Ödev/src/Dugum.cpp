/**
* @file 		G221210021
* @description  Bağlı liste veri yapısında çeşitli işlemler gerçekleştirir.
* @course 		Bilgisayar Mühendisliği 2.Öğretim B grubu
* @assignment 	1. Ödev
* @date 		26.11.2023
* @author 		Yasin Can Kaya yasin.kaya6@ogr.sakarya.edu.tr
*/

#include "Dugum.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

Dugum::Dugum(int veri)
{
    this->veri = veri;
    this->sonraki = 0;

}
Dugum::~Dugum()
{
}