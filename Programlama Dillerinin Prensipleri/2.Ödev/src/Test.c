/**
* @file         G221210021
* @description  Dosyadan sayıları okuyup canlı oluşturarak bu canlıların habitatta birbirini yemesi sağlanıyor.
* @course       2.Öğretim Cgrubu
* @assignment   2. Ödev
* @date         11.05.2024
* @author       yasin.kaya6@ogr.sakarya.edu.tr
*/



#include "Habitat.h"

int satirSayisiBul()
{
    FILE *dosya;
    char karakter;
    int satir_sayisi = 0;
    

    // Dosyayı aç
    dosya = fopen("Veri.txt", "r");

    // Dosyanın başarıyla açılıp açılmadığını kontrol et
    if (dosya == NULL) {
        printf("Dosya açilamadi!\n");
        return 1; // Programı hata ile sonlandır
    }

    while ((karakter = fgetc(dosya)) != EOF) {
        // Her '\n' karakteri bulunduğunda satır sayısını bir artır
        if (karakter == '\n') 
        {
            satir_sayisi++;
        }
    }
    fclose(dosya);

    satir_sayisi++; 
    return satir_sayisi;
}

int sutunSayisiBul() 
{
    FILE *dosya;
    int sutun_sayisi = 0;
    int karakter;

    // Dosyayı aç
    dosya = fopen("Veri.txt", "r");

    // Dosyanın başarıyla açılıp açılmadığını kontrol et
    if (dosya == NULL) {
        printf("Dosya açilamadi!\n");
        return 1; // Programı hata ile sonlandır
    }
    printf("D");

    // İlk satırı oku ve sütun sayısını bul
    while ((karakter = fgetc(dosya)) != EOF && karakter != '\n') {
    if (karakter == ' ') {
        sutun_sayisi++;
    }
}
    printf("E");
    fclose(dosya);

    sutun_sayisi++;
    return sutun_sayisi;
}

int** dosyayiMatriseAta(int satir_sayisi,int sutun_sayisi) {
    
    int karakter;

    FILE *dosya;
    dosya = fopen("Veri.txt", "r");
    if (dosya == NULL) {
        printf("Dosya açilamadi!\n");
        return NULL;
    }

    // Matris için bellek tahsisi
    int **matris = (int **)malloc(satir_sayisi * sizeof(int *));
    if (matris == NULL) {
        printf("Bellek tahsisi başarisiz!\n");
        return NULL;
    }

    for (int i = 0; i < satir_sayisi; i++) {
        matris[i] = (int *)malloc(sutun_sayisi * sizeof(int));
        if (matris[i] == NULL) {
            printf("Bellek tahsisi başarisiz!\n");
            return NULL;
        }
    }

    // Dosyadan veriyi oku ve matrise ata
    for (int i = 0; i < satir_sayisi; i++) {
        for (int j = 0; j < sutun_sayisi; j++) {
            fscanf(dosya, "%d", &matris[i][j]);
        }
    }

    fclose(dosya);
    return matris;
}


int main() {

    int satir_sayisi = satirSayisiBul();
    int sutun_sayisi = sutunSayisiBul();

    int **matris = dosyayiMatriseAta(satir_sayisi,sutun_sayisi);

    Habitat habitat = HabitatOlustur();

    habitat->bitki_matris = habitat->bitkiMatrisiOlustur(satir_sayisi,sutun_sayisi,matris);    //habitat matrislerini oluştur.
    habitat->bocek_matris = habitat->bocekMatrisiOlustur(satir_sayisi,sutun_sayisi,matris);
    habitat->sinek_matris = habitat->sinekMatrisiOlustur(satir_sayisi,sutun_sayisi,matris);
    habitat->pire_matris = habitat->pireMatrisiOlustur(satir_sayisi,sutun_sayisi,matris);


    habitat = YemeIslemleriYap(habitat,satir_sayisi,sutun_sayisi);

    habitat->yoket(habitat,satir_sayisi);

    if (matris != NULL) {   //matrisi yoket, diğer matrisler habitat içinde yok ediliyor.
        for (int i = 0; i < satir_sayisi; i++) {
            free(matris[i]);
        }
        free(matris);
    }
    return 0;
}
