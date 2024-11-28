#ifndef SayilarListesi_hpp
#define SayilarListesi_hpp
#include "Dugum.hpp"

class SayilarListesi
{
public:
    Dugum* ilk;
    SayilarListesi();
    ~SayilarListesi();
    void dosyadanAl();
    void olusturDugumler(int sayi);
    void listeYazdir();
    void tekBasa();
    void tersCevir();
    int birlesimSayiBul();

    
private:
    

};




#endif