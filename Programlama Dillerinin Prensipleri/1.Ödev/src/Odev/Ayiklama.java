/**
*
* @author Yasin Can Kaya yasin.kaya6@ogr.sakarya.edu.tr
* @since 06.04.2024
* <p>
* Ayiklama sınıfı klonlanan dosyadaki java classlarını ayıklar.
* </p>
*/

package Odev;

import java.io.File;
import java.io.IOException;

public class Ayiklama {
	
	public static void javaClasslariBul(File directory) throws IOException {
        File[] files = directory.listFiles();
        if (files != null) {       
            
            for (File file : files) {
                if (file.isDirectory()) {
                    // Eğer bir dizinse, dizin içinde dolaş.
                    javaClasslariBul(file);
                    
                } else if (file.getName().endsWith(".java")) {
                    // Eğer .java uzantılı bir dosyaysa, dosya içeriğini kontrol et.
                	
                    try {
                        String content = new String(java.nio.file.Files.readAllBytes(file.toPath()));
                        
                        if (classVarmi(content)) {
                        	//dosya class ise ekrana bilgileri yazdır.
                            System.out.println("Sınıf: " + file.getName());
                            Analiz.ekranaYazdir(file);
                        }
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                }
            }
        } 
    }
    
    private static boolean classVarmi(String content) {
        // Dosyanın sınıf dosyası olup olmadığını kontrol eder.
        return content.contains("class");
        
    }

}
