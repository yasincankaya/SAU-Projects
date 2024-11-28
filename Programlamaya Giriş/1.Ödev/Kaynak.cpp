/****************************************************************************
**						 SAKARYA ÜNÝVERSÝTESÝ
**			   BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
**				    BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
**				      PROGRAMLAMAYA GÝRÝÞ DERSÝ
**
**
**				ÖDEV NUMARASI....:1
**				ÖÐRENCÝ ADI......:Yasin Can Kaya
**				ÖÐRENCÝ NUMARASI.:G221210021
**				DERS GRUBU.......:B
****************************************************************************/
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
using namespace std;
struct Ogrenci
{
	string adi, soyadi;
	float no, kisasinav1, kisasinav2, odev1, odev2, proje, vize, final, yilicinotu, basarinotu;
};
Ogrenci ogrenciler[100];
struct Tarih
{
	int gun, ay, yil;
};
void notHarfiBulma(int ortalama)
{
	string notHarfi;
	if (ortalama >= 90) //ortalamasý 90 dan yuksek olanlarýn notHarfi AA oluyor.//
	{
		notHarfi = "AA";
	}
	else if ((ortalama >= 85) && (ortalama < 90))
	{
		notHarfi = "BA";
	}
	else if ((ortalama >= 80) && (ortalama < 85))
	{
		notHarfi = "BB";
	}
	else if ((ortalama >= 75) && (ortalama < 80))
	{
		notHarfi = "CB";
	}
	else if ((ortalama >= 70) && (ortalama < 75))
	{
		notHarfi = "CC";
	}
	else if ((ortalama >= 65) && (ortalama < 70))
	{
		notHarfi = "DC";
	}
	else if ((ortalama >= 60) && (ortalama < 65))
	{
		notHarfi = "DD";
	}
	else if ((ortalama >= 50) && (ortalama < 60))
	{
		notHarfi = "FD";
	}
	else {
		notHarfi = "FF";
	}
}
float kontrolEt(string a, float min, float max)
{
	float sayi;										
	do                                            //girilen sayi min ve max deðer arasýnda mý diye kontrol ediliyor.//
	{
		cout << a;
		cin >> sayi;
	} while (!(sayi >= min && sayi <= max));
	return sayi;
}
void sinifListesi()								
{
	cout << "Sinif Listesi:" << endl;
	for (int i = 0; i < 100; i++)				//0 dan 100 e kadar öðrenciler yazdýrýlýyor her 20 ööðrencide duruyor ve bir tuþa basýlýnca silinip devam ediyor.//
	{   
		cout << ogrenciler[i].adi << " " << ogrenciler[i].soyadi << endl;
		if(i==20 || i == 40 || i==60 || i==80)
		{
			system("pause");
			system("cls");
		}
	}
}
void enYuksekNotBulma()
{
	int enYuksekNot;
	for(int i=0;i<100;i++)					//0 dan 100 e kadar öðrenciler arasýndaki en yüksek not bulunuyor//
	{
		if (ogrenciler[i + 1].basarinotu> ogrenciler[i].basarinotu)
		{	
			enYuksekNot = ogrenciler[i+1].basarinotu;
		}
	}
	cout << "Sinifin en yuksek notu:" << enYuksekNot << endl;
}
void enDusukNotBulma()
{
	int enDusukNot;
	for (int i = 0; i < 100; i++)			//0 dan 100 e kadar öðrenciler arasýndaki en yüksek not bulunuyor//
	{
		if (ogrenciler[i + 1].basarinotu < ogrenciler[i].basarinotu)
		{
			enDusukNot = ogrenciler[i + 1].basarinotu;
		}
	}
	cout << "Sinifin en dusuk notu:" << enDusukNot << endl;
}
void sinifOrtalamasiHesaplama()			
{
	int sinifPuanToplami = 0;
	int sinifOrtalamasi;
	for (int i = 0; i < 100; i++)			//0 dan 100 e kadar öðrencilerin notlarý toplanýp öðrenci sayýsýna bölünerek ortalama bulunuyor.//
	{
		sinifPuanToplami += ogrenciler[i].basarinotu;
	}
	sinifOrtalamasi = sinifPuanToplami / 100;
	cout << "Sinif Ortalamasi:" << sinifOrtalamasi << endl;
}
void standartSapmaHesaplama()	
{
	int sinifPuanToplami = 0;
	int sinifOrtalamasi;
	int standartSapma;
	for (int i = 0; i < 100; i++)		//Standart sapma bulunuyor//
	{
		sinifPuanToplami += ogrenciler[i].basarinotu;
	}
	sinifOrtalamasi = sinifPuanToplami / 100;
	int varyans = 0;
	for (int i = 0; i < 100; i++) 
	{
		varyans+=pow(ogrenciler[i].basarinotu - sinifOrtalamasi, 2);
	}
	standartSapma = sqrt(varyans / 99);
	cout << "Standart Sapma:" << standartSapma << endl;
}
void basariNotunaGoreListeleme(int a,int b)		//0 dan 100 e kadar baþarý notu belli bir aralýkta olan öðrenciler yazdýrýlýyor.//
{
	for (int i = 0; i < 100; i++) {
		if (ogrenciler[i].basarinotu > a && ogrenciler[i].basarinotu < b)
		{
			cout <<a<<" "<<b<<" "<<"arasinda puan alan ogrenciler:" << ogrenciler[i].adi << " " << ogrenciler[i].soyadi << endl;
		}
	}
}
void basariNotuAltindaOlanlariListeleme(int a)	//0 dan 100 e kadar baþarý notu belli bir nottan düþük olan öðrenciler yazdýrýlýyor.//
{
	for (int i = 0; i < 100; i++) {
		if (ogrenciler[i].basarinotu < a)
		{
			cout << a << " " << "dan dusuk alan ogrenciler:" << ogrenciler[i].adi << " " << ogrenciler[i].soyadi << endl;
		}
	}
}
void basariNotuUstundeOlanlariListeleme(int a)	//0 dan 100 e kadar baþarý notu belli bir nottan yüksek olan öðrenciler yazdýrýlýyor.//
{
	for (int i = 0; i < 100; i++) {
		if (ogrenciler[i].basarinotu > a)
		{
			cout << a << " " << "dan yuksek alan ogrenciler:" << ogrenciler[i].adi << " " << ogrenciler[i].soyadi << endl;
		}
	}
}
int main()
{	
	srand(time(NULL));
	Tarih dogumTarihi;
	string isimler[30] = { "Muhammed","Cemal","Enes","Yunus","Arif","Onur","Halil","Mehmet","Mustafa","Ahmet","Ali","Bugra","Serkan","Orhan","Burak","Furkan","Gokhan","Yasin","Yakup","Hasan","Batuhan","Tuna","Aysel","Havva","Ebru","Selma","Zeliha","Esra","Hacer","Melek" };
	string soyisimler[30] = { "Koc","Kurt","Celik","Yildiz","Yildirim","Cetin","Kara","Yilmaz","Kaya","Demir","Sahin","Ozkan","Simsek","Cabuk","Aydin","Ozdemir","Arslan","Dogan","Gazel","Aslan","Altin","Colak","Alparslan","Sasmaz","Ari","Kaplan","Kartal","Tekin","Terim","Ergun" };
	cout << "Isimler ve notlar rastgele belirlensin istiyorsaniz 1, siz girmek istiyorsaniz 2 yaziniz." << endl;
	int secim;
	cin >> secim;
	if (secim != 1 && secim != 2)   //secim i 1 ya da 2 girmezse tekrar secim hakký veriliyor.//
	{
		cout << "Yanlis girdiniz, lutfen tekrar Isimler ve notlar rastgele belirlensin istiyorsaniz 1, siz girmek istiyorsaniz 2 yaziniz. " << endl;
		cin >> secim;
	}
	if (secim == 1)					//secim 1 ise aþaðýdaki iþlemler yapýlýyor(öðrencilerin bilgileri rastgele belirleniyor)//
	{
		for (int i = 0; i < 100; i++)	//0 dan 100 e kadar öðrencilerin ismi rastgele belirleniyor//
		{
			int random = rand() % 30;
			ogrenciler[i].adi = isimler[random];
		}
		for (int i = 0; i < 100; i++)	//0 dan 100 e kadar öðrencilerin soyismi rastgele belirleniyor//
		{
			int random = rand() % 30;
			ogrenciler[i].soyadi = soyisimler[random];
		}
		for (int i = 0; i < 10; i++)	//0 dan 10 a kadar öðrencilerin notlarý 0-40 arasýnda rastgele belirleniyor//
		{
			int enCok = 40, enAz = 0;
			ogrenciler[i].kisasinav1 = rand() % (enCok - enAz + 1) + enAz;
			ogrenciler[i].kisasinav2 = rand() % (enCok - enAz + 1) + enAz;
			ogrenciler[i].odev1 = rand() % (enCok - enAz + 1) + enAz;
			ogrenciler[i].odev2 = rand() % (enCok - enAz + 1) + enAz;
			ogrenciler[i].proje = rand() % (enCok - enAz + 1) + enAz;
			ogrenciler[i].vize = rand() % (enCok - enAz + 1) + enAz;
			ogrenciler[i].final = rand() % (enCok - enAz + 1) + enAz;
			ogrenciler[i].yilicinotu = ogrenciler[i].vize / 2 + ogrenciler[i].kisasinav1 * 7 / 100 + ogrenciler[i].kisasinav2 * 7 / 100 + ogrenciler[i].odev1 * 10 / 100 + ogrenciler[i].odev2 * 10 / 100 + ogrenciler[i].proje * 16 / 100;
			ogrenciler[i].basarinotu = ogrenciler[i].yilicinotu * 55 / 100 + ogrenciler[i].final * 45 / 100;
		}
		for (int i = 10; i < 60; i++)	//10 dan 60 a kadar öðrencilerin notlarý 40-70 arasýnda rastgele belirleniyor//
		{
			int enCok = 70, enAz = 40;
			ogrenciler[i].kisasinav1 = rand() % (enCok - enAz + 1) + enAz;
			ogrenciler[i].kisasinav2 = rand() % (enCok - enAz + 1) + enAz;
			ogrenciler[i].odev1 = rand() % (enCok - enAz + 1) + enAz;
			ogrenciler[i].odev2 = rand() % (enCok - enAz + 1) + enAz;
			ogrenciler[i].proje = rand() % (enCok - enAz + 1) + enAz;
			ogrenciler[i].vize = rand() % (enCok - enAz + 1) + enAz;
			ogrenciler[i].final = rand() % (enCok - enAz + 1) + enAz;
			ogrenciler[i].yilicinotu = ogrenciler[i].vize / 2 + ogrenciler[i].kisasinav1 * 7 / 100 + ogrenciler[i].kisasinav2 * 7 / 100 + ogrenciler[i].odev1 * 10 / 100 + ogrenciler[i].odev2 * 10 / 100 + ogrenciler[i].proje * 16 / 100;
			ogrenciler[i].basarinotu = ogrenciler[i].yilicinotu * 55 / 100 + ogrenciler[i].final * 45 / 100;
		}
		for (int i = 60; i < 75; i++)	//60 dan 75 e kadar öðrencilerin notlarý 70-80 arasýnda rastgele belirleniyor//
		{
			int enCok = 80, enAz = 70;
			ogrenciler[i].kisasinav1 = rand() % (enCok - enAz + 1) + enAz;
			ogrenciler[i].kisasinav2 = rand() % (enCok - enAz + 1) + enAz;
			ogrenciler[i].odev1 = rand() % (enCok - enAz + 1) + enAz;
			ogrenciler[i].odev2 = rand() % (enCok - enAz + 1) + enAz;
			ogrenciler[i].proje = rand() % (enCok - enAz + 1) + enAz;
			ogrenciler[i].vize = rand() % (enCok - enAz + 1) + enAz;
			ogrenciler[i].final = rand() % (enCok - enAz + 1) + enAz;
			ogrenciler[i].yilicinotu = ogrenciler[i].vize / 2 + ogrenciler[i].kisasinav1 * 7 / 100 + ogrenciler[i].kisasinav2 * 7 / 100 + ogrenciler[i].odev1 * 10 / 100 + ogrenciler[i].odev2 * 10 / 100 + ogrenciler[i].proje * 16 / 100;
			ogrenciler[i].basarinotu = ogrenciler[i].yilicinotu * 55 / 100 + ogrenciler[i].final * 45 / 100;
		}
		for (int i = 75; i < 100; i++)	//75 dan 100 e kadar öðrencilerin notlarý 80-100 arasýnda rastgele belirleniyor//
		{
			int enCok = 100, enAz = 80;
			ogrenciler[i].kisasinav1 = rand() % (enCok - enAz + 1) + enAz;
			ogrenciler[i].kisasinav2 = rand() % (enCok - enAz + 1) + enAz;
			ogrenciler[i].odev1 = rand() % (enCok - enAz + 1) + enAz;
			ogrenciler[i].odev2 = rand() % (enCok - enAz + 1) + enAz;
			ogrenciler[i].proje = rand() % (enCok - enAz + 1) + enAz;
			ogrenciler[i].vize = rand() % (enCok - enAz + 1) + enAz;
			ogrenciler[i].final = rand() % (enCok - enAz + 1) + enAz;
			ogrenciler[i].yilicinotu = ogrenciler[i].vize / 2 + ogrenciler[i].kisasinav1 * 7 / 100 + ogrenciler[i].kisasinav2 * 7 / 100 + ogrenciler[i].odev1 * 10 / 100 + ogrenciler[i].odev2 * 10 / 100 + ogrenciler[i].proje * 16 / 100;
			ogrenciler[i].basarinotu = ogrenciler[i].yilicinotu * 55 / 100 + ogrenciler[i].final * 45 / 100;
		}
		cout << " * * MENU * * " << endl;
		cout << "Sinif listesini gormek icin --> 1," << endl << "en yuksek notu gormek icin --> 2," << endl << "en dusuk notu gormek icin --> 3," << endl<<"sinif ortalamasini gormek icin --> 4," << endl<< "standart sapmayi gormek icin --> 5,"<<endl<< "50 - 80 puan arasindaki ogrencileri gormek icin --> 6,"<<endl<< "70'den dusuk alan ogrencileri gormek icin --> 7,"<<endl<<"70'den yuksek alan ogrencileri gormek icin --> 8'i tuslayiniz.";
		int sayi;
		cin >> sayi;
		if(sayi==1)	//secilen sayi 1 ise sinifListesi fonksiyonu uygulanýyor//
		{
			sinifListesi();
		}
		else if (sayi == 2)	//secilen sayi 2 ise enYuksekNotBulma fonksiyonu uygulanýyor//
		{
			enYuksekNotBulma();
		}
		else if (sayi == 3)	//secilen sayi 3 ise enDusukNotBulma fonksiyonu uygulanýyor//
		{
			enDusukNotBulma();
		}
		else if (sayi == 4)	//secilen sayi 4 ise sinifOrtalamasiHesaplama fonksiyonu uygulanýyor//
		{
			sinifOrtalamasiHesaplama();
		}
		else if (sayi == 5)	//secilen sayi 5 ise standartSapmaHesaplama fonksiyonu uygulanýyor//
		{
			standartSapmaHesaplama();
		}
		else if(sayi == 6)	//secilen sayi 6 ise basariNotunaGoreListeleme fonksiyonu uygulanýyor//
		{
			basariNotunaGoreListeleme(50, 80);
		}
		else if (sayi == 7)	//secilen sayi 7 ise basariNotuAltindaOlanlariListeleme fonksiyonu uygulanýyor//
		{
			basariNotuAltindaOlanlariListeleme(70);
		}
		else if (sayi == 8)	//secilen sayi 8 ise basariNotuUstundeOlanlariListeleme fonksiyonu uygulanýyor//
		{
			basariNotuUstundeOlanlariListeleme(70);
		}
	}
	if(secim == 2)	//secim 2 ise aþaðýdaki iþlemler uygulanýyor(öðrencilerin bilgilerini kullanýcý giriyor) //
	{
		int i = 0;
		int kisisayisi;
		cout << "kac kisi gireceksiniz:";
		cin >> kisisayisi;
		do //kullanýcý kac kisi girmek istiyorsa seçiyor.//
		{
			cout << i << ". Ogrencinin bilgilerini giriniz." << endl;
			cout << "Ogrencinin adini giriniz:";
			cin >> ogrenciler[i].adi;
			cout << "Ogrencinin soyadini  giriniz:";
			cin >> ogrenciler[i].soyadi;
			cout <<"Ogrencinin nosunu(sayi) giriniz:";
			cin >> ogrenciler[i].no;
			kontrolEt("ogrencinin kisasinav1 notunu giriniz:", 0, 100);
			cout<< "Onaylamak icin tekrar giriniz:"; cin >> ogrenciler[i].kisasinav1;
			kontrolEt("ogrencinin kisasinav2 notunu giriniz:", 0, 100);
			cout << "Onaylamak icin tekrar giriniz:"; cin >> ogrenciler[i].kisasinav2;
			kontrolEt("ogrencinin odev1 notunu giriniz:", 0, 100);
			cout << "Onaylamak icin tekrar giriniz:"; cin >> ogrenciler[i].odev1;
			kontrolEt("ogrencinin odev2 notunu giriniz:", 0, 100);
			cout << "Onaylamak icin tekrar giriniz:"; cin >> ogrenciler[i].odev2;
			kontrolEt("ogrencinin proje notunu giriniz:", 0, 100);
			cout << "Onaylamak icin tekrar giriniz:"; cin >> ogrenciler[i].proje;
			kontrolEt("ogrencinin vize notunu giriniz:", 0, 100);
			cout << "Onaylamak icin tekrar giriniz:"; cin >> ogrenciler[i].vize;
			kontrolEt("ogrencinin final notunu giriniz:", 0, 100);
			cout << "Onaylamak icin tekrar giriniz:"; cin >> ogrenciler[i].final;
			ogrenciler[i].yilicinotu = ogrenciler[i].vize / 2 + ogrenciler[i].kisasinav1 * 7 / 100 + ogrenciler[i].kisasinav2 * 7 / 100 + ogrenciler[i].odev1 * 10 / 100 + ogrenciler[i].odev2 * 10 / 100 + ogrenciler[i].proje * 16 / 100;
			ogrenciler[i].basarinotu = ogrenciler[i].yilicinotu * 55 / 100 + ogrenciler[i].final * 45 / 100;
			i++;
		} while (i < kisisayisi);
		cout << " * * MENU * * " << endl;
		cout << "Sinif listesini gormek icin --> 1," << endl << "en yuksek notu gormek icin --> 2," << endl << "en dusuk notu gormek icin --> 3," << endl << "sinif ortalamasini gormek icin --> 4," << endl << "standart sapmayi gormek icin --> 5," << endl << "50 - 80 puan arasindaki ogrencileri gormek icin --> 6," << endl << "70'den dusuk alan ogrencileri gormek icin --> 7," << endl << "70'den yuksek alan ogrencileri gormek icin --> 8'i tuslayiniz.";
		int sayi;
		cin >> sayi;
		if (sayi == 1)
		{
			sinifListesi();
		}
		else if (sayi == 2)
		{
			enYuksekNotBulma();
		}
		else if (sayi == 3)
		{
			enDusukNotBulma();
		}
		else if (sayi == 4)
		{
			sinifOrtalamasiHesaplama();
		}
		else if (sayi == 5)
		{
			standartSapmaHesaplama();
		}
		else if (sayi == 6)
		{
			basariNotunaGoreListeleme(50, 80);
		}
		else if (sayi == 7)
		{
			basariNotuAltindaOlanlariListeleme(70);
		}
		else if (sayi == 8)
		{
			basariNotuUstundeOlanlariListeleme(70);
		}
	}
	

}