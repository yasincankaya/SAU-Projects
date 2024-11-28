/**
* @file 		G221210021
* @description  Bağlı liste veri yapısında çeşitli işlemler gerçekleştirir.
* @course 		Bilgisayar Mühendisliği 2.Öğretim B grubu
* @assignment 	1. Ödev
* @date 		26.11.2023
* @author 		Yasin Can Kaya yasin.kaya6@ogr.sakarya.edu.tr
*/

#include <iostream>
#include "Dugum.hpp"
#include "SayilarListesi.hpp"
#include <fstream>
#include <string>
#include <cmath>
#include <iomanip>
#include <limits>
#include <memory>

using namespace std;


void karsilastirVeSil(SayilarListesi* sayilar, int& geciciSayiAdedi)    //sayı listesindeki sayıları karşılaştırıp en büyüğü silen fonksiyon
{
    int enBuyuk = 0;
    int enBuyukIndex = 0;

    // En büyük sayıyı ve index'ini bul
    for (int i = 0; i < geciciSayiAdedi; ++i) 
    {
        int birlesimSayi = sayilar[i].birlesimSayiBul();
        if (birlesimSayi > enBuyuk)
        {
            enBuyuk = birlesimSayi;
            enBuyukIndex = i;
        }
    }
    
    if(enBuyukIndex >= 0 && enBuyukIndex < geciciSayiAdedi)
    {
        // en büyük sayıyı içeren bağlı listeyi sil
        sayilar[enBuyukIndex].~SayilarListesi();
        
        // silinen elemanın yerine dizideki diğer elemanları kopyalayan döngü
        for (int i = enBuyukIndex + 1; i < geciciSayiAdedi; i++) 
        {
            sayilar[i-1] = sayilar[i];
        }


        geciciSayiAdedi--;
        
    }
    
}


int main() {

    ifstream dosya1("Sayilar.txt");

    if (!dosya1.is_open()) 
    {
        cerr << "Dosya acilamadi." << endl;
        return 1;
    }

    int s;
    int sayiAdedi = 0;

    while (dosya1 >> s) //dosyada kaç sayı varsa sayı adedini o kadar arttıran döngü
    {
        sayiAdedi++;
    }

    dosya1.close();

    cout << "Dosyadaki toplam sayi adedi: " << sayiAdedi << endl;

    int geciciSayiAdedi=sayiAdedi;

    SayilarListesi* sayilar = new SayilarListesi[geciciSayiAdedi];

    

    ifstream dosya("Sayilar.txt");
    if (!dosya.is_open()) {
        cerr << "Dosya acilamadi." << endl;
        return 1; // Hata durumunu belirt
    }

    int sayi;
    int index = 0;
    

    while (dosya >> sayi && index < sayiAdedi)          //dosyadaki sayı adedi kadar dinamik dizide düğüm oluşturan döngü
    {
        cout << "Sayi" << index + 1 << " dosyasi okunuyor." << endl;
        sayilar[index].olusturDugumler(sayi);
        ++index;
    }

    dosya.close();

    for (int i = 0; i < sayiAdedi; ++i) 
    {
        sayilar[i].listeYazdir();
        cout << endl;
    }

    int secim;
    

    do{
    cout<<"1. Tek Basamaklari Basa Al"<<endl;
    cout<<"2. Basamaklari Tersle"<<endl;
    cout<<"3. En Buyuk Cikar"<<endl;
    cout<<"4. Cikis"<<endl;
    cin>>secim;

    if(secim==1)
    {
        for (int i = 0; i < geciciSayiAdedi; ++i) 
        {
        sayilar[i].tekBasa();
        cout<<endl;
        }
        for (int i = 0; i < geciciSayiAdedi; ++i) 
        {
        sayilar[i].listeYazdir();
        cout << endl;
        }
    }
    else if(secim==2)
    {
        for (int i = 0; i < geciciSayiAdedi; ++i) 
        {
        sayilar[i].tersCevir();
        cout<<endl;
        }
        for (int i = 0; i < geciciSayiAdedi; ++i) 
        {
        sayilar[i].listeYazdir();
        cout << endl;
        }
    }
    else if(secim==3)
    {
        karsilastirVeSil(sayilar,geciciSayiAdedi);
        for (int i = 0; i < geciciSayiAdedi; ++i) 
        {
        sayilar[i].listeYazdir();
        cout << endl;
        }
    }
    else if(secim==4)
    {
        
        for (int i = 0; i < geciciSayiAdedi; ++i) 
        {
            sayilar[i].~SayilarListesi();
        }
        sayilar=nullptr;
        delete[] sayilar;
        cout << "Program sona erdi." << endl;
        break;
    }
}while(true);    


    
return 0;

}