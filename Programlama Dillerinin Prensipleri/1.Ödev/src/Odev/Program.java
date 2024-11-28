/**
*
* @author Yasin Can Kaya yasin.kaya6@ogr.sakarya.edu.tr
* @since 06.04.2024
* <p>
* Program sınıfı main sınıftır, klonlama işlemi bu classta yapılır ve diğer classların fonksiyonları burada çalıştırılır.
* </p>
*/

package Odev;

import java.io.BufferedReader;
import java.io.File;
import java.io.IOException;
import java.io.InputStreamReader;


public class Program {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

        File tempDir = geciciDosyaOlustur();
        
        try {
            // Kullanıcıdan GitHub deposunun URL'sini isteyin
            System.out.print("Lütfen GitHub deposunun URL'sini girin:");
            String repoUrl = reader.readLine();
            System.out.println();
            

            // Git klonlama komutunu oluşturun
            String[] command = {"git", "clone", repoUrl};
            ProcessBuilder processBuilder = new ProcessBuilder(command);
            processBuilder.directory(tempDir);

            Process process = processBuilder.start();

            // Çıktıyı okuyun
            BufferedReader inputReader = new BufferedReader(new InputStreamReader(process.getInputStream()));
            
            while ((inputReader.readLine()) != null) {
                
            }

            
            
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            // Okuyucuyu kapat
            try {
                reader.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }

        Ayiklama.javaClasslariBul(tempDir);
        
        
    }

    // Geçici bir dosya oluşturur
    private static File geciciDosyaOlustur() throws IOException {
        File tempDir = File.createTempFile("temp", Long.toString(System.nanoTime()));
        tempDir.deleteOnExit();
        if (!(tempDir.delete())) {
            throw new IOException("Geçici dizin oluşturulamadı: " + tempDir.getAbsolutePath());
        }
        if (!(tempDir.mkdir())) {
            throw new IOException("Geçici dizin oluşturulamadı: " + tempDir.getAbsolutePath());
        }
        
        return tempDir;
    }
    
    
    

    

    
}
