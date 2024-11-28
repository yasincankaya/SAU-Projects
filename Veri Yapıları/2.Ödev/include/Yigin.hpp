#ifndef Yigin_hpp
#define Yigin_hpp

using namespace std;

class Yigin
{
public:

	Yigin();
	~Yigin();
	void ekle(int veri);
	void cikar();
    bool bosmu();
	int getir();
	Yigin(const Yigin& diger);
	Yigin& operator=(const Yigin& diger);
	void yoket();
private:
	void genislet(int boyut);
	int kapasite;
    int tepe;
	int* veriler;
};

#endif