import javax.crypto.Cipher;
import javax.crypto.SecretKey;
import javax.crypto.spec.SecretKeySpec;
import java.nio.charset.StandardCharsets;
import java.util.Base64;
import java.util.*;

public class Cryptography {
        public static String secretKey = "ThisIsASecretKey";
        public static SecretKey key = new SecretKeySpec(secretKey.getBytes(StandardCharsets.UTF_8), "AES");
    public static void main(String[] args) throws Exception {
        Scanner input = new Scanner(System.in);

        //String or text that will be encrypted
        String plaintext = new String();
        plaintext = input.nextLine();

        //encrypted text will be stored encrypted variable
        String encrypted = encrypt(plaintext, secretKey);
        //decrypted text will be stored in decrypted variable
        String decrypted = decrypt(encrypted, secretKey);

        System.out.println(encrypted);
        System.out.println(decrypted);
    }

    public static String encrypt(String plainText, String secretKey) throws Exception
    {
        Cipher cipher = Cipher.getInstance("AES");
        cipher.init(Cipher.ENCRYPT_MODE, key);
        byte[] encryptedBytes = cipher.doFinal(plainText.getBytes(StandardCharsets.UTF_8));
        return Base64.getEncoder().encodeToString(encryptedBytes);
    }

    public static String decrypt(String encryptedText, String secretKey) throws Exception{
        Cipher cipher = Cipher.getInstance("AES");
        cipher.init(Cipher.DECRYPT_MODE, key);

        byte[] decodedBytes = Base64.getDecoder().decode(encryptedText);
        byte[] decryptedBytes = cipher.doFinal(decodedBytes);

        return new String (decryptedBytes, StandardCharsets.UTF_8);
    }
}


