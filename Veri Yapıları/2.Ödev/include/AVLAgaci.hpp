#ifndef AVLAgaci_hpp
#define AVLAgaci_hpp

#include "Dugum.hpp"

using namespace std;

class AVLAgaci
{
public:

	AVLAgaci();
	~AVLAgaci();
	void ekle(int veri);
	int yukseklik();
	void yapraklariYiginaEkle(Yigin& yigin);
	void yapraklariYiginaEkle(Dugum* aktif, Yigin& yigin);
	int YerlestirilmeyenleriTopla() const;
	int YerlestirilmeyenleriTopla(Dugum* aktif) const;
	void yoket();
	void yoket(Dugum* &aktif);
	bool bosmu();

private:
	Dugum* solaDondur(Dugum* dugum);
	Dugum* sagaDondur(Dugum* dugum);
	int yukseklik(Dugum* aktifDugum);
	Dugum* ekle(int veri,Dugum* aktifDugum);
	Dugum* sil(int veri,Dugum* aktif);
	Dugum* kok;
};

#endif