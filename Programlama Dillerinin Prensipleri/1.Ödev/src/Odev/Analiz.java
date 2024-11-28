/**
*
* @author Yasin Can Kaya yasin.kaya6@ogr.sakarya.edu.tr
* @since 06.04.2024
* <p>
* Analiz sınıfı ayıklanan java classlarında yorum satırı sayısı,fonksiyon sayısı bulmak vb. işlemleri yapar.
* </p>
*/

package Odev;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.text.DecimalFormat;

public class Analiz {

    public static void ekranaYazdir(File dosya) 
    {
    	System.out.println("Javadoc Satır Sayısı: "+javadocYorumSatiriBul(dosya));
        System.out.println("Yorum Satır Sayısı: "+digerYorumSatiriBul(dosya));
        System.out.println("Kod Satır Sayısı: "+kodSatiriSayisiBul(dosya));
        System.out.println("LOC: "+herseyDahilSatirSayisiBul(dosya));
        System.out.println("Fonksiyon Sayısı: "+fonksiyonSayisiBul(dosya));
        System.out.println("Yorum Sapma Yüzdesi: % "+yorumSapmaYuzdesiBul(dosya));
        System.out.println("----------------------------------");
    }
    
    public static int yorumSatiriBul(File dosya) {
        int yorumSatirSayisi = 0;
        try {
            String content = new String(java.nio.file.Files.readAllBytes(dosya.toPath()));
            String[] lines = content.split("\n");

            boolean yorumIcinde = false;

            for (String line : lines) {
                line = line.trim();

                if (line.contains("//")) {  // yorum satırını arttır.
                    yorumSatirSayisi++;
                }else if (line.contains("/*")&&line.contains("*/")) {  
                	 yorumSatirSayisi++;
                } else if (line.contains("/*")) {  //yorum satırının içine girildi.
                    yorumIcinde = true;
                } else if (line.contains("*/")) { //yorum satırı bitti.
                    yorumIcinde = false;
                } else if (yorumIcinde) {   // yorum satırının içindeyse 1 arttır.
                    yorumSatirSayisi++;
                }
            }

        } catch (IOException e) {
            e.printStackTrace();
        }

        return yorumSatirSayisi;
    }

    public static int javadocYorumSatiriBul(File dosya) {
        int javadocSatirSayisi = 0;
        try {
            String content = new String(java.nio.file.Files.readAllBytes(dosya.toPath()));
            String[] lines = content.split("\n");

            boolean javadocIcinde = false;

            for (String line : lines) {
                line = line.trim();

                if (line.contains("/**")&&line.contains("*/")) {  //yorum satırının içine girildi.
                	javadocSatirSayisi++;
                }else if (line.contains("/**")) { // Javadoc yorumunun başlangıcı
                    javadocIcinde = true;
                } else if (line.contains("*/") && javadocIcinde) { // Javadoc yorumunun sonu
                    javadocIcinde = false;
                } else if (javadocIcinde) { // Javadoc yorumu içindeyse 1 arttır.
                    javadocSatirSayisi++;
                }
            }

        } catch (IOException e) {
            e.printStackTrace();
        }

        return javadocSatirSayisi;
    }
    
    public static int kodSatiriSayisiBul(File dosya) {  // yorum satırı veya boş satırsa saymaz, kod satırı ise sayıyı 1 arttırır.
        int kodSatirSayisi = 0;
        try {
            String content = new String(java.nio.file.Files.readAllBytes(dosya.toPath()));
            String[] lines = content.split("\n");

            boolean yorumIcinde = false;

            for (String line : lines) {
                line = line.trim();

                if (line.startsWith("//")) { 
                    continue; 
                } else if (line.startsWith("/*")) { 
                    yorumIcinde = true;
                    continue; 
                } else if (line.endsWith("*/")) { 
                    yorumIcinde = false;
                    continue; 
                } else if (line.isEmpty() || yorumIcinde) { 
                    continue; 
                } else {
                    kodSatirSayisi++;	
                }
            }

        } catch (IOException e) {
            e.printStackTrace();
        }

        return kodSatirSayisi;
    }
    
    public static int herseyDahilSatirSayisiBul(File dosya) {
        int satirSayisi = 0;
        try {
            String content = new String(java.nio.file.Files.readAllBytes(dosya.toPath()));
            String[] lines = content.split("\n");

            for (String line : lines) {
                line = line.trim();

                // Boş satır veya yorum satırı olup olmadığını kontrol etmez, her satırı sayar
                satirSayisi++;
            }

        } catch (IOException e) {
            e.printStackTrace();
        }

        return satirSayisi;
    }
    
    public static int fonksiyonSayisiBul(File dosya) {
        int fonksiyonSayisi = 0;
        boolean fonksiyonIcinde = false; 
        try (BufferedReader br = new BufferedReader(new FileReader(dosya))) {
            String line;
            while ((line = br.readLine()) != null) {
                line = line.trim(); // Boşlukları kaldır
                // Eğer satır boşsa veya yorum satırı ise bir sonraki satıra geç
                if (line.isEmpty() || line.startsWith("//") || line.startsWith("/*") || line.startsWith("*")) {
                    continue;
                }
                // satırın fonksiyon başlangıcı olup olmadığını kontrol ediyoruz.
                if ((line.contains("(") && line.contains(")")&& !line.contains(";"))&&(line.contains("public")||line.contains("private")||line.contains("protected")||line.contains("static"))) 
                {
                	fonksiyonIcinde = true;
                }
                // Eğer fonksiyon içindeysek ve kapanış parantezini bulduysak.
                else if (fonksiyonIcinde && line.contains("}")) {
                	fonksiyonIcinde = false;
                    fonksiyonSayisi++;
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        return fonksiyonSayisi;
    }
    
    public static int digerYorumSatiriBul(File dosya)  //javadoc olmayan yorum satırlarını bulmak için bütün yorum satırlarından javadocları çıkarır.
    {
    	return (yorumSatiriBul(dosya)-javadocYorumSatiriBul(dosya));
    }
    
    public static String yorumSapmaYuzdesiBul(File dosya) {
        double javadocSatirSayisi = javadocYorumSatiriBul(dosya);
        double digerYorumSatirSayisi = digerYorumSatiriBul(dosya);
        double fonksiyonSayisi = fonksiyonSayisiBul(dosya);
        double kodSatirSayisi = kodSatiriSayisiBul(dosya);
        
        double YG = ((javadocSatirSayisi + digerYorumSatirSayisi) * 0.8) / fonksiyonSayisi;
        double YH = (kodSatirSayisi / fonksiyonSayisi) * 0.3;
        
        double sonuc = ((100 * YG) / YH) - 100;
        
        // Sonucu istenilen formatta biçimlendirme
        DecimalFormat df = new DecimalFormat("#.##");
        String istenilensonuc = df.format(sonuc);
        
        if (!istenilensonuc.contains(",")) {
        	istenilensonuc += ",00";
        }
        
        return istenilensonuc;
    }
}
