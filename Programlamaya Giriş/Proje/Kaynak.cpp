/****************************************************************************
**					 SAKARYA ÜNÝVERSÝTESÝ
**		  BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
**				 BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
**				   PROGRAMLAMAYA GÝRÝÞ DERSÝ
**
**				ÖDEV NUMARASI..........:1.Proje
**				ÖÐRENCÝ ADI............:Yasin Can Kaya
**				ÖÐRENCÝ NUMARASI.......:G221210021
**              DERSÝN ALINDIÐI GRUP...:B
****************************************************************************/


#include <iostream>
#include <fstream>
#include <string>
#include <locale.h>
#include <iomanip>

using namespace std;

class Tarih
{
public:
	int gun;
	int ay;
	int yil;
};

class Urun
{
public:
	int ukod;
	string ad;
	Tarih uretimTarihi;
	Tarih sonKullanmaTarihi;
	float kaloriGram;
	float stok;
	float fiyat;

	void ekranaYaz()
	{
		cout << "   *******urun bilgileri*******   ";
		cout << "Urun Adi: " << ad << endl;
		cout << "Uretim Tarihi: " << uretimTarihi.gun << "." << uretimTarihi.ay << "." << uretimTarihi.yil << endl;
		cout << "Son Kullanma Tarihi: " << sonKullanmaTarihi.gun << "." << sonKullanmaTarihi.ay << "." << sonKullanmaTarihi.yil << endl;
		cout << "Kalori: " << kaloriGram << endl;
		cout << "Stok: " << stok << " kilo" << endl;
		cout << "Fiyat: " << fiyat << endl;
		cout << " urun kodu : " << ukod << endl << endl;
	}

	void bilgiGir()
	{
		cout << "   *******urun bilgileri*******   ";
		cout << "Urun Adi: "; cin >> ad;
		cout << "Uretim Tarihi: "; cin >> uretimTarihi.gun; cin >> uretimTarihi.ay; cin >> uretimTarihi.yil;
		cout << "Son Kullanma Tarihi: "; cin >> sonKullanmaTarihi.gun; cin >> sonKullanmaTarihi.ay; cin >> sonKullanmaTarihi.yil;
		cout << "Kalori: "; cin >> kaloriGram;
		cout << "Stok: "; cin >> stok;
		cout << "Fiyat: "; cin >> fiyat;
		cout << "Urun kodu : "; cin >> ukod;
	}

	void kayitsil()
	{
		ofstream yazmaDosyasi("gecici.txt");
		ifstream okumaDosyasi("depo.txt");
		int kod;
		cout << "Silmek istediginiz urunun kodunu giriniz : " << endl;
		cin >> kod;
		while (okumaDosyasi >> ad >> ukod>> uretimTarihi.gun >> uretimTarihi.ay>> uretimTarihi.yil>>sonKullanmaTarihi.gun>> sonKullanmaTarihi.ay >> sonKullanmaTarihi.yil >> kaloriGram >> stok >> fiyat)  //Dosya satýr satýr, en sona gelene kadar okunuyor.//
		{

			if (!(kod == ukod)) //girilen kod ürün koduna eþit deðilse gecici.txt dosyasýna bilgileri yazdýrýr.//
			{
				yazmaDosyasi << ad << endl << ukod << endl << uretimTarihi.gun << endl << uretimTarihi.ay << endl << uretimTarihi.yil << endl << sonKullanmaTarihi.gun << endl << sonKullanmaTarihi.ay << endl << sonKullanmaTarihi.yil << endl << kaloriGram << endl << stok << endl << fiyat << endl << endl;
			}
		}
		okumaDosyasi.close();
		yazmaDosyasi.close();
		remove("depo.txt");
		rename("gecici.txt", "depo.txt");
	}

	void guncelleme()
	{
		ofstream yazmaDosyasi("gecici.txt");
		ifstream okumaDosyasi("depo.txt");
		int kod;
		cout << "Guncellemek istediginiz urunun kodunu giriniz : " << endl;
		cin >> kod;
		while (okumaDosyasi >> ad >> ukod >> uretimTarihi.gun >> uretimTarihi.ay >> uretimTarihi.yil >> sonKullanmaTarihi.gun >> sonKullanmaTarihi.ay >> sonKullanmaTarihi.yil >> kaloriGram >> stok >> fiyat) //Dosya satýr satýr, en sona gelene kadar okunuyor.//
		{

			if (!(kod == ukod)) //girilen kod ürün koduna eþit deðilse gecici.txt dosyasýna bilgileri yazdýrýr.//
			{
				yazmaDosyasi << ad << endl << ukod << endl << uretimTarihi.gun << endl << uretimTarihi.ay << endl << uretimTarihi.yil << endl << sonKullanmaTarihi.gun << endl << sonKullanmaTarihi.ay << endl << sonKullanmaTarihi.yil << endl << kaloriGram << endl << stok << endl << fiyat << endl << endl;
			}
			else if (kod == ukod) //girilen kod ürün koduna eþitse bilgileri günceller.//
			{
				cout << "yeni bilgileri giriniz." << endl;
				bilgiGir();
				yazmaDosyasi << ad << endl << ukod << endl << uretimTarihi.gun << endl << uretimTarihi.ay << endl << uretimTarihi.yil << endl << sonKullanmaTarihi.gun << endl << sonKullanmaTarihi.ay << endl << sonKullanmaTarihi.yil << endl << kaloriGram << endl << stok << endl << fiyat << endl << endl;
			}
		}
		okumaDosyasi.close();
		yazmaDosyasi.close();
		remove("depo.txt");
		rename("gecici.txt","depo.txt");
	}

	void raporal()
	{
		ifstream okumaDosyasi("depo.txt");
		int kod;
		cout << "raporunu almak istediginiz urunun kodunu giriniz : " << endl;
		cin >> kod;
		while (okumaDosyasi >> ad >> ukod >> uretimTarihi.gun >> uretimTarihi.ay >> uretimTarihi.yil >> sonKullanmaTarihi.gun >> sonKullanmaTarihi.ay >> sonKullanmaTarihi.yil >> kaloriGram >> stok >> fiyat) //Dosya satýr satýr, en sona gelene kadar okunuyor.//
		{

			if (kod == ukod) //girilen kod ürün koduna eþitse ürün bilgilerini ekrana yazdýrýr.//
			{
				ekranaYaz();
				system("pause");
			}

		}

	}

};
class yemek
{
public:
	string yemekadi;
	string malzemeleri;
	int kackisilik;
	int ykod;
	int mkod;
	float maliyet;
	float fiyat;
	Tarih uretimTarihi;
	Tarih sonKullanmaTarihi;

	void yemekleriYaz()
	{
		ofstream yemekdosyasi("yemekcesitleri.txt", ios::app);
		yemekdosyasi << yemekadi << endl << ykod << endl << fiyat << endl << uretimTarihi.gun << endl << uretimTarihi.ay << endl << uretimTarihi.yil << endl << sonKullanmaTarihi.gun << endl << sonKullanmaTarihi.ay << endl << sonKullanmaTarihi.yil << endl << endl;
		yemekdosyasi.close();
	}

	void ekranaYazdir()
	{
		cout << "    *****yemek bilgileri*****    " << endl;
		cout << "  yemek adi        :" << yemekadi << endl;
		cout << "  yemek kodu : " << ykod << endl;
		cout << "  fiyati           :" << fiyat << endl;
		cout << " Uretim Tarihi: " << uretimTarihi.gun << uretimTarihi.ay << uretimTarihi.yil << endl;
		cout << " Son Kullanma Tarihi: " << sonKullanmaTarihi.gun << sonKullanmaTarihi.ay << sonKullanmaTarihi.yil << endl;
	}

	void bilgiGir()
	{
		cout << "   ******yemek bilgileri*****   " << endl;
		cout << " yemek adi   :"; cin >> yemekadi;
		cout << " yemek kodu  :"; cin >> ykod;
		cout << "fiyat: "; cin >> fiyat;
		cout << "Uretim Tarihi: "; cin >> uretimTarihi.gun; cin >> uretimTarihi.ay; cin >> uretimTarihi.yil;
		cout << "Son Kullanma Tarihi: "; cin >> sonKullanmaTarihi.gun; cin >> sonKullanmaTarihi.ay; cin >> sonKullanmaTarihi.yil;
	}

	void dosyadansilme()
	{
	ofstream yazmaDosyasi("gecici.txt");
	ifstream okumaDosyasi("yemekcesitleri.txt");
	int kod;
	cout << "Silmek istediginiz yemegin kodunu giriniz : " << endl;
	cin >> kod;
	while (okumaDosyasi >> yemekadi>>ykod>>fiyat>> uretimTarihi.gun >> uretimTarihi.ay >> uretimTarihi.yil >> sonKullanmaTarihi.gun >> sonKullanmaTarihi.ay >> sonKullanmaTarihi.yil) //Dosya satýr satýr, en sona gelene kadar okunuyor.//
	{

		if (!(ykod == kod)) //girilen kod ürün koduna eþit deðilse bilgileri gecici.txt dosyasýna yazdýrýr.//
		{
			yazmaDosyasi << yemekadi << endl << ykod << endl << fiyat << endl << uretimTarihi.gun << endl << uretimTarihi.ay << endl << uretimTarihi.yil << endl << sonKullanmaTarihi.gun << endl << sonKullanmaTarihi.ay << endl << sonKullanmaTarihi.yil << endl << endl;
		}
	}
	okumaDosyasi.close();
	yazmaDosyasi.close();
	remove("yemekcesitleri.txt");
	rename("gecici.txt","yemekcesitleri.txt");
	}
	
	void guncelleme()
	{
		ofstream yazmaDosyasi("gecici.txt");
		ifstream okumaDosyasi("yemekcesitleri.txt");
		int kod;
		cout << "guncellemek istediginiz yemegin kodunu giriniz : " << endl;
		cin >> kod;
		while (okumaDosyasi >> yemekadi >> ykod >> fiyat >> uretimTarihi.gun >> uretimTarihi.ay >> uretimTarihi.yil >> sonKullanmaTarihi.gun >> sonKullanmaTarihi.ay >> sonKullanmaTarihi.yil) //Dosya satýr satýr, en sona gelene kadar okunuyor.//
		{

			if (!(kod == ykod)) //girilen kod ürün koduna eþit deðilse bilgileri gecici.txt dosyasýna yazdýrýr.//
			{
				yazmaDosyasi << yemekadi << endl << ykod << endl << fiyat << endl << uretimTarihi.gun << endl << uretimTarihi.ay << endl << uretimTarihi.yil << endl << sonKullanmaTarihi.gun << endl << sonKullanmaTarihi.ay << endl << sonKullanmaTarihi.yil << endl << endl;
			}
			else if(kod == ykod) //girilen kod ürün koduna eþitse bilgileri günceller.//
			{
				cout << "Yeni yemek bilgilerini giriniz:";
				bilgiGir();
				yazmaDosyasi << yemekadi << endl << ykod << endl << fiyat << endl << uretimTarihi.gun << endl << uretimTarihi.ay << endl << uretimTarihi.yil << endl << sonKullanmaTarihi.gun << endl << sonKullanmaTarihi.ay << endl << sonKullanmaTarihi.yil << endl << endl;
			}
		}
		okumaDosyasi.close();
		yazmaDosyasi.close();
		remove("yemekcesitleri.txt");
		rename("gecici.txt","yemekcesitleri.txt");
	}

	void raporal()
	{
		ifstream okumaDosyasi("yemekcesitleri.txt");
		int kod;
		cout << "raporunu almak istediginiz yemegin kodunu giriniz : " << endl;
		cin >> kod;
		while (okumaDosyasi >> yemekadi >> ykod >> fiyat >> uretimTarihi.gun >> uretimTarihi.ay >> uretimTarihi.yil >> sonKullanmaTarihi.gun >> sonKullanmaTarihi.ay >> sonKullanmaTarihi.yil) //Dosya satýr satýr, en sona gelene kadar okunuyor.//
		{

			if (kod == ykod) //girilen kod ürün koduna eþitse bilgileri ekrana yazdýrýr.//
			{
				ekranaYazdir();
				system("pause");
			}

		}

	}

};

void yemekMenu()
{
	int secim;
	do {

		do
		{
			system("CLS");
			cout << "  ***** Yemek Menusu *****  " << endl;
			cout << " [1] kayit ekle        " << endl;
			cout << " [2] kayit sil         " << endl;
			cout << " [3] kayit guncelle    " << endl;
			cout << " [4] rapor al          " << endl;
			cout << " [5] ana menuye dön    " << endl;
			cout << "     Seciminiz     :   "; cin >> secim;

		} while (!(secim >= 1 && secim < 6));
		if (secim == 1) //secim 1 ise yemekcesitleri.txt dosyasýna kayýt ekler//
		{
			char kontrol;
			Urun u;
			yemek y;
			fstream dyemek;
			dyemek.open("yemekcesitleri.txt", ios::app);
			do
			{
				y.bilgiGir();
				y.yemekleriYaz();
				cout << " yeni kayit eklenecek mi?  (y/n) "; cin >> kontrol;
			} while (!(kontrol == 'n'));
			dyemek.close();
		}
		else if (secim == 2) //secim 2 ise dosyadan ayný kodlu yemeði siler//
		{
			yemek y;
			y.dosyadansilme();
		}
		else if (secim == 3) //secim 3 ise ayný kodlu yemeði günceller//
		{
			yemek y;
			y.guncelleme();
		}
		else if (secim == 4) //secim 4 ise ayný kodlu yemeðin bilgilerini ekrana yazdýrýr//
		{
			yemek y;
			y.raporal();
		}
	} while (secim != 5); //secim 5 ise döngüden çýkar//

}

void depoMenu()
{
	int secim;
	do {

		do
		{
			system("CLS");
			cout << "   ***** Depo Menusu *****   " << endl;
			cout << " [1] - kayit ekle " << endl;
			cout << " [2] - kayit sil         " << endl;
			cout << " [3] - kayit guncelle    " << endl;
			cout << " [4] - rapor al          " << endl;
			cout << " [5] - ana menuye dön     " << endl;
			cout << " Seciminiz?     :"; cin >> secim;

		} while (!(secim >= 1 && secim < 6));//secim 1 ve 6 arasýndayken döngü devam eder//
		if (secim == 1) //secim 1 ise depo.txt dosyasýna yeni kayýt eklenir.//
		{
			char kontrol;
			Urun u;
			fstream yazmaDosyasi;
			yazmaDosyasi.open("depo.txt", ios::app);
			do
			{
				u.bilgiGir();
				yazmaDosyasi << u.ad << endl << u.ukod << endl << u.uretimTarihi.gun << endl << u.uretimTarihi.ay << endl << u.uretimTarihi.yil << endl << u.sonKullanmaTarihi.gun << endl << u.sonKullanmaTarihi.ay << endl << u.sonKullanmaTarihi.yil << endl << u.kaloriGram << endl << u.stok << endl <<u.fiyat << endl << endl;
				cout << " yeni kayit eklenecek mi?  (y/n) "; cin >> kontrol;
			} while (!(kontrol == 'n'));
			yazmaDosyasi.close();
		}
		else if (secim == 2) //secim 2 ise kayitsil fonksiyonuyla ayný kodlu ürün silinir//
		{
			Urun u;
			u.kayitsil();
		}
		else if (secim == 3) //secim 3 ise ayný kodlu ürün güncellenir//
		{
			Urun u;
			u.guncelleme();
		}
		else if (secim == 4) //secim 4 ise ayný kodlu ürünün raporu ekrana yazdýrýlýr.//
		{
			Urun u;
			u.raporal();
		}
	} while (secim != 5); //secim 5 ise döngüden çýkar//
}

void malzemeMenu()
{
	int secim;
	do {

		do
		{
			system("CLS");
			cout << "   ***** Malzeme Menusu *****   " << endl;
			cout << " [1] - kayit ekle        " << endl;
			cout << " [2] - kayit sil         " << endl;
			cout << " [3] - kayit guncelle    " << endl;
			cout << " [4] - rapor al          " << endl;
			cout << " [5] - ana menuye dön    " << endl;
			cout << " Seciminiz   : "; cin >> secim;

		} while (!(secim >= 1 && secim < 6)); 
		if (secim == 1)
		{
			char kontrol;
			yemek y;
			fstream dmalzeme;
			dmalzeme.open("malzemeler.txt", ios::app);
			do
			{
				cout << "yemek kodunu giriniz:"; cin >> y.ykod;
				cout << "malzeme kodunu giriniz:"; cin >> y.mkod;
				dmalzeme << y.ykod << endl << y.mkod << endl << endl;
				cout << " yeni kayit eklenecek mi?  (y/n) "; cin >> kontrol;
			} while (!(kontrol == 'n'));
			dmalzeme.close();
		}
		else if (secim == 2)
		{
			yemek y;
			ofstream yazmaDosyasi("gecici.txt");
			ifstream okumaDosyasi("malzemeler.txt");
			int kod;
			cout << "Silmek istediginiz malzemenin kodunu giriniz : " << endl;
			cin >> kod;
			while (okumaDosyasi >> y.ykod >> y.mkod) //Dosya satýr satýr, en sona gelene kadar okunuyor.//
			{

				if (!(y.mkod == kod))
				{
					yazmaDosyasi << y.ykod << endl << y.mkod << endl << endl;
				}
			}
			okumaDosyasi.close();
			yazmaDosyasi.close();
			remove("malzemeler.txt");
			rename("gecici.txt","malzemeler.txt");
		}
		else if (secim == 3)
		{
			yemek y;
			ofstream yazmaDosyasi("gecici.txt");
			ifstream okumaDosyasi("malzemeler.txt");
			int kod;
			cout << "guncellemek istediginiz malzemenin kodunu giriniz : " << endl;
			cin >> kod;
			while (okumaDosyasi >> y.ykod >> y.mkod) //Dosya satýr satýr, en sona gelene kadar okunuyor.//
			{

				if (!(y.mkod == kod))
				{
					yazmaDosyasi << y.ykod << endl << y.mkod << endl << endl;
				}
				else if (y.mkod == kod)
				{
					cout << "Yeni yemek kodunu giriniz:"; cin >> y.ykod;
					cout << "Yeni malzeme kodunu giriniz:"; cin >> y.mkod;
					yazmaDosyasi << y.ykod << endl << y.mkod << endl << endl;
				}
			}
			okumaDosyasi.close();
			yazmaDosyasi.close();
			remove("yemekcesitleri.txt");
			rename("gecici.txt","yemekcesitleri.txt");
		}
		else if (secim == 4)
		{
			yemek y;
			ifstream okumaDosyasi("malzemeler.txt");
			int kod;
			cout << "raporunu almak istediginiz malzemenin kodunu giriniz : " << endl;
			cin >> kod;
			while (okumaDosyasi >> y.ykod >> y.mkod)
			{

				if (y.mkod == kod)
				{
					cout << "yemek kodu : " << y.ykod << endl;
					cout << "malzeme kodu : " << y.mkod << endl;
					system("pause");
				}

			}
		}
	} while (secim != 5);

}

	void satisislemi()
	{
		yemek y;
		char cevap;
		float maliyet = 0;
		cout << " Yemek kac kisilik olacak : "; cin >> y.kackisilik;
		int kod;
		fstream duretim;
		duretim.open("yuretim.txt", ios::app);
		do
		{
			cout << " uretilecek yemek kodu "; cin >> kod;
			fstream okumaDosyasi;
			okumaDosyasi.open("yemekcesitleri.txt", ios::in);
			okumaDosyasi >> y.yemekadi >> y.ykod >> y.fiyat >> y.uretimTarihi.gun >> y.uretimTarihi.ay >> y.uretimTarihi.yil >> y.sonKullanmaTarihi.gun >> y.sonKullanmaTarihi.ay >> y.sonKullanmaTarihi.yil; // yemek okunuyor
			while (okumaDosyasi >> y.yemekadi >> y.ykod >> y.fiyat >> y.uretimTarihi.gun >> y.uretimTarihi.ay >> y.uretimTarihi.yil >> y.sonKullanmaTarihi.gun >> y.sonKullanmaTarihi.ay >> y.sonKullanmaTarihi.yil) //Dosya satýr satýr, en sona gelene kadar okunuyor.//
			{
				if (kod == y.ykod)
				{
					cout << " yemek maliyeti hesaplaniyor ...." << endl;
					fstream dymalzeme;
					dymalzeme.open("malzemeler.txt", ios::in);
					dymalzeme >> y.ykod >> y.mkod;
					while (dymalzeme >> y.ykod >> y.mkod) //Dosya satýr satýr, en sona gelene kadar okunuyor.//
					{
						if (kod == y.ykod) // girilen kod ykod a eþitse depo.txt dosyasýndan veri okunuyor//
						{
							Urun u;
							fstream ddepo;
							ddepo.open("depo.txt", ios::in);
							ddepo >> u.ad >> u.ukod >> u.uretimTarihi.gun >> u.uretimTarihi.ay >> u.uretimTarihi.yil >> u.sonKullanmaTarihi.gun >> u.sonKullanmaTarihi.ay >> u.sonKullanmaTarihi.yil >> u.kaloriGram >> u.stok >> u.fiyat;
							while (ddepo >> u.ad >> u.ukod >> u.uretimTarihi.gun >> u.uretimTarihi.ay >> u.uretimTarihi.yil >> u.sonKullanmaTarihi.gun >> u.sonKullanmaTarihi.ay >> u.sonKullanmaTarihi.yil >> u.kaloriGram >> u.stok >> u.fiyat) //Dosya satýr satýr, en sona gelene kadar okunuyor.//
							{
								if (kod == u.ukod) //girilen kod ukoda eþitse yemeðin maliyeti hesaplanýp ekrana yazdýrýlýyor.//
								{
									u.stok = u.stok - y.kackisilik;
									float gelir = 0;
									maliyet += u.fiyat * y.kackisilik;
									gelir += y.fiyat - maliyet;
									cout << "Toplam Maliyet : " << maliyet << endl;
									cout << "gelir:" << gelir << endl;
									
								}
								ddepo >> u.ad >> u.ukod >> u.uretimTarihi.gun >> u.uretimTarihi.ay >> u.uretimTarihi.yil >> u.sonKullanmaTarihi.gun >> u.sonKullanmaTarihi.ay >> u.sonKullanmaTarihi.yil >> u.kaloriGram >> u.stok >> u.fiyat;
							}
							ddepo.close();
						}
						dymalzeme >> y.ykod >> y.mkod;
					}
					dymalzeme.close();
					duretim << kod << " " << y.uretimTarihi.gun << " " << y.uretimTarihi.ay << " " << y.uretimTarihi.yil << y.kackisilik << " " << "\n";
				}
			}
			okumaDosyasi.close();
			cout << " yeni yemek eklenecek mi? (e/h)"; cin >> cevap;
		} while (!cevap == 'h'); //cevap h olana kadar döngü devam eder.//
		duretim.close();
	}



int main()
{
	setlocale(LC_ALL, "Turkish");
	int secim;
	do {
		do
		{
			system("CLS");
			cout << "   ***** Ana Menu *****   " << endl;
			cout << " [1]- Depo Menusu " << endl;
			cout << " [2]- Yemek menusu " << endl;
			cout << " [3]- yemek Satis islemleri     " << endl;
			cout << " [4]- malzeme menusu     " << endl;
			cout << " [5]- cikis     " << endl;
			cout << " Seciminiz  : "; cin >> secim;

		} while (!(secim >= 1 && secim < 6));
		if (secim == 1)
			depoMenu();
		else if (secim == 2)
			yemekMenu();
		else if (secim == 3)
			satisislemi();
		else if (secim == 4)
			malzemeMenu();
	} while (secim != 5);

	
}
