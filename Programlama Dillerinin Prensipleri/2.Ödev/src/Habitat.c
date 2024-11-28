/**
* @file         G221210021
* @description  Dosyadan sayıları okuyup canlı oluşturarak bu canlıların habitatta birbirini yemesi sağlanıyor.
* @course       2.Öğretim Cgrubu
* @assignment   2. Ödev
* @date         11.05.2024
* @author       yasin.kaya6@ogr.sakarya.edu.tr
*/


#include "Habitat.h"

Habitat HabitatOlustur() 
{
    Habitat this = (Habitat)malloc(sizeof(struct HABITAT));
    this->bitkiMatrisiOlustur = &bitkiMatrisiOlustur;
    this->bocekMatrisiOlustur = &bocekMatrisiOlustur;
    this->sinekMatrisiOlustur = &sinekMatrisiOlustur;
    this->pireMatrisiOlustur = &pireMatrisiOlustur;
    this->HabitatEkranaYazdir = &HabitatEkranaYazdir;
    this->CanliSayisiniGetir = &CanliSayisiniGetir;
    this->yoket = &HabitatYoket;
    return this;
}


void HabitatYoket(const Habitat this, int satir_sayisi) {  //habitatı ve içindeki matrisleri yok eden fonksiyon
    if (this == NULL) return;

    if (this->bitki_matris != NULL) {
        for (int i = 0; i < satir_sayisi; i++) {
            free(this->bitki_matris[i]);
        }
        free(this->bitki_matris);
    }

    if (this->bocek_matris != NULL) {
        for (int i = 0; i < satir_sayisi; i++) {
            free(this->bocek_matris[i]);
        }
        free(this->bocek_matris); 
    }

    if (this->sinek_matris != NULL) {
        for (int i = 0; i < satir_sayisi; i++) {
            free(this->sinek_matris[i]);
        }
        free(this->sinek_matris);
    }

    if (this->pire_matris != NULL) {
        for (int i = 0; i < satir_sayisi; i++) {
            free(this->pire_matris[i]);
        }
        free(this->pire_matris);
    }
    free(this);
}

Bitki** bitkiMatrisiOlustur(int satir_sayisi, int sutun_sayisi, int** matris) //bitki matrisi için bellekte yer açan ve matristeki sayılara göre canlı oluşturan kod
{
    Bitki **bitki_matris = (Bitki **)calloc(satir_sayisi, sizeof(Bitki *));
    if (bitki_matris == NULL) {
        printf("Bellek tahsisi basarisiz!\n");
        return NULL;
    }

    for (int i = 0; i < satir_sayisi; i++) {
        bitki_matris[i] = (Bitki *)calloc(sutun_sayisi, sizeof(Bitki));
        if (bitki_matris[i] == NULL) {
            printf("Bellek tahsisi basarisiz!\n");
            return NULL;
        }
    }

    for (int i = 0; i < satir_sayisi; i++) {
        for (int j = 0; j < sutun_sayisi; j++) 
        {
                if (1 <= matris[i][j] && matris[i][j] <= 9) 
                {
                    Bitki B = BitkiOlustur(matris[i][j],i,j);
                    bitki_matris[i][j] = B;
                } 
        }
        printf("\n");
        }
    
    return bitki_matris;
}

Bocek** bocekMatrisiOlustur(int satir_sayisi, int sutun_sayisi, int** matris) //böcek matrisi için bellekte yer açan ve matristeki sayılara göre canlı oluşturan kod
{
    Bocek **bocek_matris = (Bocek **)calloc(satir_sayisi, sizeof(Bocek *));
    if (bocek_matris == NULL) {
        printf("Bellek tahsisi basarisiz!\n");
        return NULL;
    }

    for (int i = 0; i < satir_sayisi; i++) {
        bocek_matris[i] = (Bocek *)calloc(sutun_sayisi, sizeof(Bocek));
        if (bocek_matris[i] == NULL) {
            printf("Bellek tahsisi basarisiz!\n");
            return NULL;
        }
    }

    for (int i = 0; i < satir_sayisi; i++) {
        for (int j = 0; j < sutun_sayisi; j++) 
        {
                if (10 <= matris[i][j] && matris[i][j] <= 20) 
                {
                    Bocek C = BocekOlustur(matris[i][j],i,j);
                    bocek_matris[i][j] = C;

                } 
        }
        printf("\n");
        }
    
    return bocek_matris;
}

Sinek** sinekMatrisiOlustur(int satir_sayisi, int sutun_sayisi, int** matris) //sinek matrisi için bellekte yer açan ve matristeki sayılara göre canlı oluşturan kod
{
    Sinek **sinek_matris = (Sinek **)calloc(satir_sayisi, sizeof(Sinek *));
    if (sinek_matris == NULL) {
        printf("Bellek tahsisi basarisiz!\n");
        return NULL;
    }

    for (int i = 0; i < satir_sayisi; i++) {
        sinek_matris[i] = (Sinek *)calloc(sutun_sayisi, sizeof(Sinek));
        if (sinek_matris[i] == NULL) {
            printf("Bellek tahsisi basarisiz!\n");
            return NULL;
        }
    }

    for (int i = 0; i < satir_sayisi; i++) {
        for (int j = 0; j < sutun_sayisi; j++) 
        {
                if (21 <= matris[i][j] && matris[i][j] <= 50) 
                {
                    Sinek S = SinekOlustur(matris[i][j],i,j);
                    sinek_matris[i][j] = S;

                } 
        }
        printf("\n");
        }
    
    return sinek_matris;
}

Pire** pireMatrisiOlustur(int satir_sayisi, int sutun_sayisi, int** matris) //pire matrisi için bellekte yer açan ve matristeki sayılara göre canlı oluşturan kod
{
    Pire **pire_matris = (Pire **)calloc(satir_sayisi, sizeof(Pire *));
    if (pire_matris == NULL) {
        printf("Bellek tahsisi basarisiz!\n");
        return NULL;
    }

    for (int i = 0; i < satir_sayisi; i++) {
        pire_matris[i] = (Pire *)calloc(sutun_sayisi, sizeof(Pire));
        if (pire_matris[i] == NULL) {
            printf("Bellek tahsisi basarisiz!\n");
            return NULL;
        }
    }

    for (int i = 0; i < satir_sayisi; i++) {
        for (int j = 0; j < sutun_sayisi; j++) 
        {
                if (51 <= matris[i][j] && matris[i][j] <= 99) 
                {
                    Pire P = PireOlustur(matris[i][j],i,j);
                    pire_matris[i][j] = P;

                } 
        }
        printf("\n");
        }
    
    return pire_matris;
}

int CanliSayisiniGetir(Habitat habitat, int satir_sayisi, int sutun_sayisi) {  // habitattaki güncel canlı sayısını getirir.
    
    habitat->canliSayisi=0;

    for (int i = 0; i < satir_sayisi; i++) {
        for (int j = 0; j < sutun_sayisi; j++) {
            if (habitat->bitki_matris[i][j] != NULL) {
                habitat->canliSayisi++;
            } else if (habitat->bocek_matris[i][j] != NULL) {
                habitat->canliSayisi++;
            } else if (habitat->sinek_matris[i][j] != NULL) {
                habitat->canliSayisi++;
            } else if (habitat->pire_matris[i][j] != NULL) {
                habitat->canliSayisi++;
            }
        }
    }

    return habitat->canliSayisi;
}

void HabitatEkranaYazdir(Habitat habitat, int satir_sayisi, int sutun_sayisi) //habitattaki canlıları ekrana yazdırır ve sonra 1 canlı kalınca kazananı yazdırır.
{
    system("cls");
    int canliSayisi = habitat->CanliSayisiniGetir(habitat,satir_sayisi,sutun_sayisi);

    for (int i = 0; i < satir_sayisi; i++) {
        for (int j = 0; j < sutun_sayisi; j++) 
        {
                if(habitat->bitki_matris[i][j]!=NULL){  //bitki_matris[i][j] doluysa ekrana yazdır.

                    char* str = habitat->bitki_matris[i][j]->super->toString(habitat->bitki_matris[i][j]->super,habitat->bitki_matris[i][j]);
	                printf("%s",str);
	                free(str);

                    if(canliSayisi == 1){       // canlı sayısı 1 se kazananı yazdır.
                        system("cls");
                        printf("Kazanan: ");
                        char* str = habitat->bitki_matris[i][j]->super->toString(habitat->bitki_matris[i][j]->super,habitat->bitki_matris[i][j]);
	                    printf("%s",str);
	                    free(str);
                        printf(" : (%d,%d)",habitat->bitki_matris[i][j]->super->x,habitat->bitki_matris[i][j]->super->y);
                        habitat->bitki_matris[i][j]->yoket(habitat->bitki_matris[i][j]);
                        return;
                    }
                }

                else if(habitat->bocek_matris[i][j]!=NULL){

                    char* str = habitat->bocek_matris[i][j]->super->toString(habitat->bocek_matris[i][j]->super,habitat->bocek_matris[i][j]);
	                printf("%s",str);
	                free(str);

                    if(canliSayisi == 1){       // canlı sayısı 1 se kazananı yazdır.
                        system("cls");
                        printf("Kazanan: ");
                        char* str = habitat->bocek_matris[i][j]->super->toString(habitat->bocek_matris[i][j]->super,habitat->bocek_matris[i][j]);
	                    printf("%s",str);
	                    free(str);
                        printf(" : (%d,%d)",habitat->bocek_matris[i][j]->super->x,habitat->bocek_matris[i][j]->super->y);
                        habitat->bocek_matris[i][j]->yoket(habitat->bocek_matris[i][j]);
                        return;
                    }
                }

                else if(habitat->sinek_matris[i][j]!=NULL){

                    char* str = habitat->sinek_matris[i][j]->super->super->toString(habitat->sinek_matris[i][j]->super->super,habitat->sinek_matris[i][j]);
	                printf("%s",str);
	                free(str);

                    if(canliSayisi == 1){       // canlı sayısı 1 se kazananı yazdır.
                        system("cls");
                        printf("Kazanan: ");
                        char* str = habitat->sinek_matris[i][j]->super->super->toString(habitat->sinek_matris[i][j]->super->super,habitat->sinek_matris[i][j]);
	                    printf("%s",str);
	                    free(str);
                        printf(" : (%d,%d)",habitat->sinek_matris[i][j]->super->super->x,habitat->sinek_matris[i][j]->super->super->y);
                        habitat->sinek_matris[i][j]->yoket(habitat->sinek_matris[i][j]);
                        return;
                    }
                }

                else if(habitat->pire_matris[i][j]!=NULL){

                    char* str = habitat->pire_matris[i][j]->super->super->toString(habitat->pire_matris[i][j]->super->super,habitat->pire_matris[i][j]);
	                printf("%s",str);
	                free(str);

                    if(canliSayisi == 1){       // canlı sayısı 1 se kazananı yazdır.
                        system("cls");
                        printf("Kazanan: ");
                        char* str = habitat->pire_matris[i][j]->super->super->toString(habitat->pire_matris[i][j]->super->super,habitat->pire_matris[i][j]);
	                    printf("%s",str);
	                    free(str);
                        printf(":(%d,%d)",habitat->pire_matris[i][j]->super->super->x,habitat->pire_matris[i][j]->super->super->y);
                        habitat->pire_matris[i][j]->yoket(habitat->pire_matris[i][j]);
                        return;
                    }
                }
                else
                {
                    printf("X ");
                }
                    
        }
            
        printf("\n");
        }
}

Habitat YemeIslemleriYap(Habitat habitat,int satir_sayisi,int sutun_sayisi) //tuşa basılınca yeme işlemi başlar ve canlıların türüne göre birbirlerini yemesi sağlanır.
{
    habitat->HabitatEkranaYazdir(habitat,satir_sayisi,sutun_sayisi);
    system("pause");

    for (int i = 0; i < satir_sayisi; i++) {
    for (int j = 0; j < sutun_sayisi; j++) {
        
        if (habitat->bitki_matris[i][j] != NULL) {
            
            for (int l = 0; l < satir_sayisi; l++) {
            for (int k = 0; k < sutun_sayisi; k++) {
                
                if (habitat->pire_matris[l][k] != NULL) {   // bitki pire ile karşılaşırsa pire ölür.

                    habitat->pire_matris[l][k]->yoket(habitat->pire_matris[l][k]);
                    habitat->pire_matris[l][k] = NULL;
                    i=0; j=-1;  //dış döngüyü baştan başlat.
                    l=satir_sayisi; k=sutun_sayisi;    // iç döngüyü bitir.
                    habitat->HabitatEkranaYazdir(habitat,satir_sayisi,sutun_sayisi);  
                }
                else if (habitat->sinek_matris[l][k] != NULL) {     // bitki sinek ile karşılaşırsa sinek ölür.
                    
                    habitat->sinek_matris[l][k]->yoket(habitat->sinek_matris[l][k]);
                    habitat->sinek_matris[l][k] = NULL;
                    i=0; j=-1;
                    l=satir_sayisi; k=sutun_sayisi;
                    habitat->HabitatEkranaYazdir(habitat,satir_sayisi,sutun_sayisi);                   
                }
                else if (habitat->bocek_matris[l][k] != NULL) {     // bitki bocek ile karşılaşırsa bitki ölür.
                    
                    habitat->bitki_matris[i][j]->yoket(habitat->bitki_matris[i][j]);
                    habitat->bitki_matris[i][j] = NULL;
                    i=0; j=-1;
                    l=satir_sayisi; k=sutun_sayisi;
                    habitat->HabitatEkranaYazdir(habitat,satir_sayisi,sutun_sayisi);                   
                }
                else if ((habitat->bitki_matris[l][k] != NULL) && (habitat->bitki_matris[i][j]!= NULL) && (habitat->bitki_matris[l][k] != habitat->bitki_matris[i][j])) {
                    //bitki bitki ile karşılaşırsa değeri büyük olan küçüğü yer, eşitse bitişe uzak olan yakını yer.
                    if((habitat->bitki_matris[l][k]->super->deger) > (habitat->bitki_matris[i][j]->super->deger))
                    {
                        habitat->bitki_matris[i][j]->yoket(habitat->bitki_matris[i][j]);
                        habitat->bitki_matris[i][j] = NULL;
                        i=0; j=-1;
                        l=satir_sayisi; k=sutun_sayisi;
                        habitat->HabitatEkranaYazdir(habitat,satir_sayisi,sutun_sayisi);
                    }
                    else if((habitat->bitki_matris[l][k]->super->deger) < (habitat->bitki_matris[i][j]->super->deger))
                    {    
                        habitat->bitki_matris[l][k]->yoket(habitat->bitki_matris[l][k]);
                        habitat->bitki_matris[l][k] = NULL;
                        i=0; j=-1;  
                        l=satir_sayisi; k=sutun_sayisi;
                        habitat->HabitatEkranaYazdir(habitat,satir_sayisi,sutun_sayisi); 
                    }
                    else if((habitat->bitki_matris[l][k]->super->deger) == (habitat->bitki_matris[i][j]->super->deger))
                    {
                        if(l > i)   //bitişe uzaklık kontrol ediliyor.
                        {
                            
                            habitat->bitki_matris[l][k]->yoket(habitat->bitki_matris[l][k]);
                            habitat->bitki_matris[l][k] = NULL;
                            i=0; j=-1;
                            l=satir_sayisi; k=sutun_sayisi;
                            habitat->HabitatEkranaYazdir(habitat,satir_sayisi,sutun_sayisi);
                            
                        }
                        else if(i > l)
                        {
                            habitat->bitki_matris[i][j]->yoket(habitat->bitki_matris[i][j]);
                            habitat->bitki_matris[i][j] = NULL;
                            i=0; j=-1;
                            l=satir_sayisi; k=sutun_sayisi;
                            habitat->HabitatEkranaYazdir(habitat,satir_sayisi,sutun_sayisi);
                            
                        }
                        else if(l == i && j > k)
                        {
                            habitat->bitki_matris[i][j]->yoket(habitat->bitki_matris[i][j]);
                            habitat->bitki_matris[i][j] = NULL;
                            i=0; j=-1;
                            l=satir_sayisi; k=sutun_sayisi;
                            habitat->HabitatEkranaYazdir(habitat,satir_sayisi,sutun_sayisi);
                            
                        }
                        else if(l == i && k > j)
                        {
                            habitat->bitki_matris[l][k]->yoket(habitat->bitki_matris[l][k]);
                            habitat->bitki_matris[l][k] = NULL;
                            i=0; j=-1;
                            l=satir_sayisi; k=sutun_sayisi;
                            habitat->HabitatEkranaYazdir(habitat,satir_sayisi,sutun_sayisi);
                            
                        }  
                    }
  
                }
            }
            }
        }

        else if (habitat->bocek_matris[i][j] != NULL) {     // devamı da bitkideki işlemler gibi.
            
            for (int l = 0; l < satir_sayisi; l++) {
            for (int k = 0; k < sutun_sayisi; k++) {
                
                if (habitat->bitki_matris[l][k] != NULL) {

                    habitat->bitki_matris[l][k]->yoket(habitat->bitki_matris[l][k]);
                    habitat->bitki_matris[l][k] = NULL;
                    i=0; j=-1;
                    l=satir_sayisi; k=sutun_sayisi;
                    habitat->HabitatEkranaYazdir(habitat,satir_sayisi,sutun_sayisi);
                }
                else if (habitat->pire_matris[l][k] != NULL) {

                    habitat->pire_matris[l][k]->yoket(habitat->pire_matris[l][k]);
                    habitat->pire_matris[l][k] = NULL;
                    i=0; j=-1;
                    l=satir_sayisi; k=sutun_sayisi;
                    habitat->HabitatEkranaYazdir(habitat,satir_sayisi,sutun_sayisi);
                }
                else if (habitat->sinek_matris[l][k] != NULL) {
                    
                    habitat->bocek_matris[i][j]->yoket(habitat->bocek_matris[i][j]);
                    habitat->bocek_matris[i][j] = NULL;
                    i=0; j=-1;
                    l=satir_sayisi; k=sutun_sayisi;
                    habitat->HabitatEkranaYazdir(habitat,satir_sayisi,sutun_sayisi);
                }
                else if ((habitat->bocek_matris[l][k] != NULL) && (habitat->bocek_matris[i][j]!= NULL) && (habitat->bocek_matris[l][k] != habitat->bocek_matris[i][j])) {
                    
                    if((habitat->bocek_matris[l][k]->super->deger) > (habitat->bocek_matris[i][j]->super->deger))
                    {
                        habitat->bocek_matris[i][j]->yoket(habitat->bocek_matris[i][j]);
                        habitat->bocek_matris[i][j] = NULL;
                        i=0; j=-1;
                        l=satir_sayisi; k=sutun_sayisi;  
                        habitat->HabitatEkranaYazdir(habitat,satir_sayisi,sutun_sayisi);  
                    }
                    else if((habitat->bocek_matris[l][k]->super->deger) < (habitat->bocek_matris[i][j]->super->deger))
                    {    
                        habitat->bocek_matris[l][k]->yoket(habitat->bocek_matris[l][k]);
                        habitat->bocek_matris[l][k] = NULL;
                        i=0; j=-1;
                        l=satir_sayisi; k=sutun_sayisi;
                        habitat->HabitatEkranaYazdir(habitat,satir_sayisi,sutun_sayisi);
                    }
                    else if((habitat->bocek_matris[l][k]->super->deger) == (habitat->bocek_matris[i][j]->super->deger))
                    {
                        
                        if(l > i)
                        {
                            habitat->bocek_matris[l][k]->yoket(habitat->bocek_matris[l][k]);
                            habitat->bocek_matris[l][k] = NULL;
                            i=0; j=-1;
                            l=satir_sayisi; k=sutun_sayisi;
                            habitat->HabitatEkranaYazdir(habitat,satir_sayisi,sutun_sayisi);
                        }
                        else if(i > l)
                        {
                            habitat->bocek_matris[i][j]->yoket(habitat->bocek_matris[i][j]);
                            habitat->bocek_matris[i][j] = NULL;
                            i=0; j=-1;
                            l=satir_sayisi; k=sutun_sayisi;
                            habitat->HabitatEkranaYazdir(habitat,satir_sayisi,sutun_sayisi);
                        }
                        else if(l == i && j > k)
                        {
                            habitat->bocek_matris[i][j]->yoket(habitat->bocek_matris[i][j]);
                            habitat->bocek_matris[i][j] = NULL;
                            i=0; j=-1;
                            l=satir_sayisi; k=sutun_sayisi;
                            habitat->HabitatEkranaYazdir(habitat,satir_sayisi,sutun_sayisi);
                        }
                        else if(l == i && k > j)
                        {
                            habitat->bocek_matris[l][k]->yoket(habitat->bocek_matris[l][k]);
                            habitat->bocek_matris[l][k] = NULL;
                            i=0; j=-1;
                            l=satir_sayisi; k=sutun_sayisi;
                            habitat->HabitatEkranaYazdir(habitat,satir_sayisi,sutun_sayisi);
                        }
                            
                    }
                    
                }

            }
            }
        }

        else if (habitat->sinek_matris[i][j] != NULL) {
            
            for (int l = 0; l < satir_sayisi; l++) {
            for (int k = 0; k < sutun_sayisi; k++) {
                
                if (habitat->pire_matris[l][k] != NULL) {
                    
                    habitat->pire_matris[l][k]->yoket(habitat->pire_matris[l][k]);
                    habitat->pire_matris[l][k] = NULL;
                    i=0; j=-1;
                    l=satir_sayisi; k=sutun_sayisi;
                    habitat->HabitatEkranaYazdir(habitat,satir_sayisi,sutun_sayisi);
                }
                else if (habitat->bocek_matris[l][k] != NULL) {
                    
                    habitat->bocek_matris[l][k]->yoket(habitat->bocek_matris[l][k]);
                    habitat->bocek_matris[l][k] = NULL;
                    i=0; j=-1;
                    l=satir_sayisi; k=sutun_sayisi;
                    habitat->HabitatEkranaYazdir(habitat,satir_sayisi,sutun_sayisi);
                }
                else if (habitat->bitki_matris[l][k] != NULL) {

                    habitat->sinek_matris[i][j]->yoket(habitat->sinek_matris[i][j]);
                    habitat->sinek_matris[i][j] = NULL;
                    i=0; j=-1;
                    l=satir_sayisi; k=sutun_sayisi;
                    habitat->HabitatEkranaYazdir(habitat,satir_sayisi,sutun_sayisi);
                }
                else if ((habitat->sinek_matris[l][k] != NULL) && (habitat->sinek_matris[i][j]!= NULL) && (habitat->sinek_matris[l][k] != habitat->sinek_matris[i][j])) {
                    
                    if((habitat->sinek_matris[l][k]->super->super->deger) > (habitat->sinek_matris[i][j]->super->super->deger))
                    {
                        habitat->sinek_matris[i][j]->yoket(habitat->sinek_matris[i][j]);
                        habitat->sinek_matris[i][j] = NULL;
                        i=0; j=-1;
                        l=satir_sayisi; k=sutun_sayisi;
                        habitat->HabitatEkranaYazdir(habitat,satir_sayisi,sutun_sayisi);
                        
                    }
                    else if((habitat->sinek_matris[l][k]->super->super->deger) < (habitat->sinek_matris[i][j]->super->super->deger))
                    {    
                        habitat->sinek_matris[l][k]->yoket(habitat->sinek_matris[l][k]);
                        habitat->sinek_matris[l][k] = NULL;
                        i=0; j=-1;
                        l=satir_sayisi; k=sutun_sayisi;
                        habitat->HabitatEkranaYazdir(habitat,satir_sayisi,sutun_sayisi);
                    }
                    else if((habitat->sinek_matris[l][k]->super->super->deger) == (habitat->sinek_matris[i][j]->super->super->deger))
                    {
                        
                        if(l > i)
                        {
                            habitat->sinek_matris[l][k]->yoket(habitat->sinek_matris[l][k]);
                            habitat->sinek_matris[l][k] = NULL;
                            i=0; j=-1;
                            l=satir_sayisi; k=sutun_sayisi;
                            habitat->HabitatEkranaYazdir(habitat,satir_sayisi,sutun_sayisi);
                        }
                        else if(i > l)
                        {
                            habitat->sinek_matris[i][j]->yoket(habitat->sinek_matris[i][j]);
                            habitat->sinek_matris[i][j] = NULL;
                            i=0; j=-1;
                            l=satir_sayisi; k=sutun_sayisi;
                            habitat->HabitatEkranaYazdir(habitat,satir_sayisi,sutun_sayisi);
                        }
                        else if(l == i && j > k)
                        {
                            habitat->sinek_matris[i][j]->yoket(habitat->sinek_matris[i][j]);
                            habitat->sinek_matris[i][j] = NULL;
                            i=0; j=-1;
                            l=satir_sayisi; k=sutun_sayisi;
                            habitat->HabitatEkranaYazdir(habitat,satir_sayisi,sutun_sayisi);
                        }
                        else if(l == i && k > j)
                        {
                            habitat->sinek_matris[l][k]->yoket(habitat->sinek_matris[l][k]);
                            habitat->sinek_matris[l][k] = NULL;
                            i=0; j=-1;
                            l=satir_sayisi; k=sutun_sayisi;
                            habitat->HabitatEkranaYazdir(habitat,satir_sayisi,sutun_sayisi);
                        }
                            
                    }
                    
                }
            }
            }
        }

        else if (habitat->pire_matris[i][j] != NULL) {
            
            for (int l = 0; l < satir_sayisi; l++) {
            for (int k = 0; k < sutun_sayisi; k++) {
                
                if (habitat->bitki_matris[l][k] != NULL) {
                    
                    habitat->pire_matris[i][j]->yoket(habitat->pire_matris[i][j]);
                    habitat->pire_matris[i][j] = NULL;
                    i=0; j=-1;
                    l=satir_sayisi; k=sutun_sayisi;
                    habitat->HabitatEkranaYazdir(habitat,satir_sayisi,sutun_sayisi);
                }
                
                else if (habitat->sinek_matris[l][k] != NULL) {
                    
                    habitat->pire_matris[i][j]->yoket(habitat->pire_matris[i][j]);
                    habitat->pire_matris[i][j] = NULL;
                    i=0; j=-1;
                    l=satir_sayisi; k=sutun_sayisi;
                    habitat->HabitatEkranaYazdir(habitat,satir_sayisi,sutun_sayisi);
                }

                else if (habitat->bocek_matris[l][k] != NULL) {
                    
                    habitat->pire_matris[i][j]->yoket(habitat->pire_matris[i][j]);
                    habitat->pire_matris[i][j] = NULL;
                    i=0; j=-1;
                    l=satir_sayisi; k=sutun_sayisi;
                    habitat->HabitatEkranaYazdir(habitat,satir_sayisi,sutun_sayisi);
                }

                else if ((habitat->pire_matris[l][k] != NULL) && (habitat->pire_matris[i][j]!= NULL) && (habitat->pire_matris[l][k] != habitat->pire_matris[i][j])) {
                    
                    if((habitat->pire_matris[l][k]->super->super->deger) > (habitat->pire_matris[i][j]->super->super->deger))
                    {
                        habitat->pire_matris[i][j]->yoket(habitat->pire_matris[i][j]);
                        habitat->pire_matris[i][j] = NULL;
                        i=0; j=-1;
                        l=satir_sayisi; k=sutun_sayisi;
                        habitat->HabitatEkranaYazdir(habitat,satir_sayisi,sutun_sayisi);
                    }
                    else if((habitat->pire_matris[l][k]->super->super->deger) < (habitat->pire_matris[i][j]->super->super->deger))
                    {    
                        habitat->pire_matris[l][k]->yoket(habitat->pire_matris[l][k]);
                        habitat->pire_matris[l][k] = NULL;
                        i=0; j=-1;
                        l=satir_sayisi; k=sutun_sayisi;
                        habitat->HabitatEkranaYazdir(habitat,satir_sayisi,sutun_sayisi);
                    }
                    else if((habitat->pire_matris[l][k]->super->super->deger) == (habitat->pire_matris[i][j]->super->super->deger))
                    {
                        
                        if(l > i)
                        {
                            habitat->pire_matris[l][k]->yoket(habitat->pire_matris[l][k]);
                            habitat->pire_matris[l][k] = NULL;
                            i=0; j=-1;
                            l=satir_sayisi; k=sutun_sayisi;
                            habitat->HabitatEkranaYazdir(habitat,satir_sayisi,sutun_sayisi);
                        }
                        else if(i > l)
                        {
                            habitat->pire_matris[i][j]->yoket(habitat->pire_matris[i][j]);
                            habitat->pire_matris[i][j] = NULL;
                            i=0; j=-1;
                            l=satir_sayisi; k=sutun_sayisi;
                            habitat->HabitatEkranaYazdir(habitat,satir_sayisi,sutun_sayisi);
                        }
                        else if(l == i && j > k)
                        {
                            habitat->pire_matris[i][j]->yoket(habitat->pire_matris[i][j]);
                            habitat->pire_matris[i][j] = NULL;
                            i=0; j=-1;
                            l=satir_sayisi; k=sutun_sayisi;
                            habitat->HabitatEkranaYazdir(habitat,satir_sayisi,sutun_sayisi);
                        }
                        else if(l == i && k > j)
                        {
                            habitat->pire_matris[l][k]->yoket(habitat->pire_matris[l][k]);
                            habitat->pire_matris[l][k] = NULL;
                            i=0; j=-1;
                            l=satir_sayisi; k=sutun_sayisi;
                            habitat->HabitatEkranaYazdir(habitat,satir_sayisi,sutun_sayisi);
                        }
                            
                    }
                    
                }
            }
            }
        }
    }
    }
    return habitat;
}


