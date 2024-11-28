/**
* @file 		G221210021
* @description  AVL Ağacı ve yığıt veri yapısında ekleme, yazdırma gibi işlemler yapar.
* @course 		Bilgisayar Mühendisliği 2.Öğretim B grubu
* @assignment 	2. Ödev
* @date 		22.12.2023
* @author 		Yasin Can Kaya yasin.kaya6@ogr.sakarya.edu.tr
*/

#include <iostream>
#include "Dugum.hpp"
#include "AVLAgaci.hpp"
#include "Yigin.hpp"
#include <fstream>
#include <sstream>


using namespace std;

AVLAgaci AVL[500];
Yigin yigin[500];
Yigin geciciYigin[500];

void asciiYazdir()     //500 e kadar artan döngüde yığınlara yerleştirilmeyen sayıların formül ile ascii değerini yazdırıyor.//
{
    int toplam;

    for (int i = 0; i < 500; i++)
    {
        if(!yigin[i].bosmu())
        {
            toplam = AVL[i].YerlestirilmeyenleriTopla() % (90 - 65 + 1) + 65;
            char harf = static_cast<char>(toplam);
            cout << harf;
        }
    }
    system("cls");
}

void silmedenAsciiYazdir()
{
    int toplam;

    for (int i = 0; i < 500; i++)
    {
        if(!yigin[i].bosmu())
        {
            toplam = AVL[i].YerlestirilmeyenleriTopla() % (90 - 65 + 1) + 65;
            char harf = static_cast<char>(toplam);
            cout << harf;
        }
    }
}

bool birYiginKaldimi()  //programda sadece tek bir yığın kaldıysa true döndürüyor.
{
    int doluYiginSayisi=500;
    for(int a=0;a<500;a++)
    {
        if (yigin[a].bosmu()) 
        {
            doluYiginSayisi--;
        }
        if (doluYiginSayisi == 1)
        {
            return true;
        }
    } 
    return false;
}

void YiginlariOlustur()     //dosyadan sayıları okuyup avl ağacına ekliyor, sonra da yaprakları yığınlara ekliyor.
{
    ifstream dosya("Veri.txt");

    if (!dosya.is_open()) 
    {
        cerr << "Dosya acilamadi: " << "Veri.txt" << endl;
    }

    string satir;
    int index = 0;

    while (getline(dosya, satir)) 
    {
        istringstream iss(satir);
        int sayi;
        
        while (iss >> sayi) 
        {
            AVL[index].ekle(sayi);
        }

        index++;
    }

    for(int i=0;i<500;i++)
    {
        AVL[i].yapraklariYiginaEkle(yigin[i]);
    }

    dosya.close();
}

void YigittanEnAzCikar()    //yığıtların tepe değerlerinden en az değere sahip olanını çıkarıyor.
{
    int enAz=10000;
    int enAzIndex=-1;

    for(int d=0;d<500;d++)
    {
        if(!yigin[d].bosmu() && yigin[d].getir() < enAz)
        {
            enAz=yigin[d].getir();
            enAzIndex=d;
        }
    }
    yigin[enAzIndex].cikar();

    if (yigin[enAzIndex].bosmu())       //eleman çıkarılan yığıt tamamen bittiyse o yığıta ait avl ağacı ve kendisi yok ediliyor.
    {
        asciiYazdir();
        AVL[enAzIndex].yoket();
        yigin[enAzIndex].yoket();
        for(int i=0;i<500;i++)
        {
            if(!yigin[i].bosmu())   //yığıt bittiği için diğer yığıtlar yenileniyor.
            {
                yigin[i]=geciciYigin[i];    
            }
            
        }
        
        YigittanEnAzCikar();
        
    }

}

void YigittanEnFazlaCikar()     //yığıtların tepe değerlerinden en fazla değere sahip olanını çıkarıyor.
{
    int enFazla=-1;
    int enFazlaIndex=-1;

    for(int e=0;e<500;e++)
    {
        if(!yigin[e].bosmu() && yigin[e].getir() > enFazla)
        {
            enFazla=yigin[e].getir();
            enFazlaIndex=e;
        }
    }
    yigin[enFazlaIndex].cikar();

    if (yigin[enFazlaIndex].bosmu())    //eleman çıkarılan yığıt tamamen bittiyse o yığıta ait avl ağacı ve kendisi yok ediliyor.
    {
        asciiYazdir();
        AVL[enFazlaIndex].yoket();
        yigin[enFazlaIndex].yoket();
        for(int i=0;i<500;i++)
        {
            if(!yigin[i].bosmu())   //yığıt bittiği için diğer yığıtlar yenileniyor.
            {
                yigin[i]=geciciYigin[i];
            }
            
        }
        
    }
    
}




int main()
{

YiginlariOlustur();

for(int i=0;i<500;i++)  //yığınları geçici yığına atıyor.
{
    geciciYigin[i]=yigin[i];
}


while(!birYiginKaldimi())   //bir yığın kalana kadar yığınlardan eleman çıkarıyor.
{
    
    YigittanEnAzCikar();

    if (birYiginKaldimi())
    {
        break;
    }
    
    YigittanEnFazlaCikar();

}

for(int i=0;i<500;i++)      // son kalan yığının sırasını ve ascii değerini yazdırıyor.
{
    if(!yigin[i].bosmu())
    {
        cout<<"=============================="<<endl<<"|                            |"<<endl<<"|                            |"<<endl;
        cout<<"|      Son Karakter: ";
        silmedenAsciiYazdir();
        cout<<"       |"<<endl<<"|      AVL NO      : "<<i+1<<"     |"<<endl<<"|                            |"<<endl<<"|                            |"<<endl;
        cout<<"==============================";
    }
    
}

return 0;

}

