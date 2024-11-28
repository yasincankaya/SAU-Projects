/****************************************************************************
**					    SAKARYA ÜNÝVERSÝTESÝ
**			   BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
**				    BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
**				      PROGRAMLAMAYA GÝRÝÞÝ DERSÝ
**
**				ÖDEV NUMARASI…...:2
**				ÖÐRENCÝ ADI......:Yasin Can Kaya
**				ÖÐRENCÝ NUMARASI.:G221210021
**				DERS GRUBU…………...:B
****************************************************************************/

#include <iostream>
#include <cmath>
using namespace std;
class karmasik
{
private:
    float gercek;
    float sanal;
public:
    karmasik(): gercek(0),sanal(0){}
    void ekranaYazdir()
    {
        if (sanal > 0) //sanal kýsmý pozitifse + ile yazdýrýyor//
        {
            cout << gercek << "+" << sanal << "i" << endl;
        }
        else if (sanal < 0) //sanal kýsmý negatifse - ile yazdýrýyor//
        {
            cout << gercek << "-" << -sanal << "i" << endl;
        }
        else             //sanal kýsmý 0 ise sadece gercek kýsmý yazdýrýyor//
            cout << gercek << endl;
    }
    void sayiGir()     //karmasik sayiyi kullanýcýdan isteyen fonksiyon//
    {
        cout << "Sayinin once gercek sonra sanal kismini giriniz:" << endl;
        cin >> gercek;
        cin >> sanal;
    }
    karmasik operator+(karmasik sayi)  //+ operator overload//
    {
        this->gercek += sayi.gercek;
        this->sanal += sayi.sanal;
        return *this;
    }
    karmasik operator-(karmasik sayi)
    {
        this->gercek -= sayi.gercek;
        this->sanal -= sayi.sanal;
        return *this;
    }
    karmasik operator*(karmasik sayi)
    {
        karmasik a;
        a.gercek = (gercek * sayi.gercek) - (sanal * sayi.sanal);
        a.sanal = (gercek * sayi.sanal) + (sanal * sayi.gercek);
        return a;
    }
    karmasik operator/(karmasik sayi)
    {
        karmasik a;
        a.gercek = ((gercek * sayi.gercek) + (sanal * sayi.sanal)) / ((sayi.gercek * sayi.gercek) + (sayi.sanal * sayi.sanal));
        a.sanal = ((sanal * sayi.gercek) - (gercek * sayi.sanal)) / ((sayi.gercek * sayi.gercek) + (sayi.sanal * sayi.sanal));
        return a;
    }
    karmasik operator+=(karmasik sayi)
    {    
        gercek += sayi.gercek;
        sanal += sayi.sanal;
        return *this;
    }
    karmasik operator -=(karmasik sayi)
    {    
        gercek -= sayi.gercek;
        sanal -= sayi.sanal;
        return *this;
    }
    karmasik operator *=(karmasik sayi)
    {
        float a = (gercek * sayi.gercek) - (sanal * sayi.sanal);
        sanal = (gercek * sayi.sanal) + (sanal * sayi.gercek);
        gercek = a;
        return *this;
    }
    karmasik operator /=(karmasik sayi)
    {
        float temp;
        temp = ((gercek * sayi.gercek) + (sanal * sayi.sanal)) / ((sayi.sanal * sayi.sanal) + (sayi.gercek * sayi.gercek));
        sanal = ((sanal * sayi.gercek) - (gercek * sayi.sanal)) / ((sayi.gercek * sayi.gercek) + (sayi.sanal * sayi.sanal));
        gercek = temp;
        return *this;
    }
    void kutupsal()    //karmasik sayinin kutupsal gosterimini yapan fonksiyon//
    {
        float oklid = sqrt(gercek * gercek + sanal * sanal); // Öklid uzaklýðýný hesaplýyoruz
        float aci = atan2(sanal, gercek);                    // Açýyý hesaplýyoruz
        cout << "Kutupsal Gosterim: (" << oklid << ", " << aci << ")" << endl;
    }
};



int main()
{
    karmasik sayi1;
    karmasik sayi2;
    cout << "1.sayiyi giriniz:" << endl;
    sayi1.sayiGir();
    cout << "2.sayiyi giriniz:" << endl;
    sayi2.sayiGir();
    cout << "1.sayi:"; sayi1.ekranaYazdir();
    cout << "2.sayi:"; sayi2.ekranaYazdir();
    cout << "***MENU***" << endl;   
    cout << "+ islemi icin 1'i tuslayiniz" << endl;
    cout << "- islemi icin 2'yi tuslayiniz" << endl;
    cout << "* islemi icin 3'u tuslayiniz" << endl;
    cout << "/ islemi icin 4'u tuslayiniz" << endl;
    cout << "+= islemi icin 5'i tuslayiniz" << endl;
    cout << "-= islemi icin 6'yi tuslayiniz" << endl;
    cout << "*= islemi icin 7'yi tuslayiniz" << endl;
    cout << "/= islemi icin 8'i tuslayiniz" << endl;
    cout << "Kutupsal gosterim icin 9'u tuslayiniz" << endl;
    cout << "Menuden cikmak icin 0'i tuslayiniz" << endl;
    int secim;
    do                  //kullanýcý 0'a basana kadar menü iþlemleri yapan döngü//
    {   
        cin >> secim;
        switch (secim)  //kullanýcýnýn seçimine göre iþlem yaptýran switch yapýsý//
        {
        case 1:         //secim=1 ise case 1'in iþlemlerini yapýyor vs.//
            cout << "+ isleminin sonucu:";
            (sayi1 + sayi2).ekranaYazdir();
            break;
        case 2:
            cout << "- isleminin sonucu:";
            (sayi1 - sayi2).ekranaYazdir();
            break;
        case 3:
            cout << "* isleminin sonucu:";
            (sayi1 * sayi2).ekranaYazdir();
            break;
        case 4:
            cout << "/ isleminin sonucu:";
            (sayi1 / sayi2).ekranaYazdir();
            break;
        case 5:
            cout << "+= isleminin sonucu:";
            sayi1 += sayi2;
            sayi1.ekranaYazdir();
            break;
        case 6:
            cout << "-= isleminin sonucu:";
            sayi1 -= sayi2;
            sayi1.ekranaYazdir();
            break;
        case 7:
            cout << "*= isleminin sonucu:";
            sayi1 *= sayi2;
            sayi1.ekranaYazdir();
            break;
        case 8:
            cout << "/= isleminin sonucu:";
            sayi1 /= sayi2;
            sayi1.ekranaYazdir();
            break;
        case 9:
            cout << "1.sayinin ";
            sayi1.kutupsal();
            cout << "2.sayinin ";
            sayi2.kutupsal();
            break;
        case 0:
            cout << "Cikis yaptiniz.";
            break;
        default:                //secim gosterilenlerden farklý bir sayi ise ekrana gecersiz islem yazdýrýyor//
            cout << "Gecersiz secim";
            break;
        }
    } while (secim != 0);
    return 0;
}