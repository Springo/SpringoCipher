/**
 * Created by Kevin on 2/15/2016.
 */

import java.util.Scanner;

public class SPE {
    private final int start = 32;
    private final int size = 94;

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter a message to encrypt: ");
        String s = scan.nextLine();
        System.out.print("\nEnter a key: ");
        String k = scan.nextLine();
        System.out.println("\n\nEncrypted text: " + encryptText(s, k));
        System.out.print("Enter a message to decrypt: ");
        s = scan.nextLine();
        System.out.print("\nEnter a key: ");
        k = scan.nextLine();
        System.out.println("\n\nDecrypted text: " + decryptText(s, k));
    }

    public static String encryptText(String text, String key) {
        if (key == null || text == null || key.length() == 0)
            return null;
        int keypoint = 0;
        String encrypted = "";
        for (int i = 0; i < text.length(); i++) {
            encrypted += getTrueValue((char)((int)(text.charAt(i)) + (int)(key.charAt(keypoint))));
            keypoint++;
            if (keypoint >= key.length())
                keypoint = 0;
        }
        return encrypted;
    }

    public static String decryptText(String text, String key) {
        if (key == null || text == null || key.length() == 0)
            return null;
        int keypoint = 0;
        String decrypted = "";
        for (int i = 0; i < text.length(); i++) {
            decrypted += getRangeValue((int)getRawValue(text.charAt(i)) - (int)(key.charAt(keypoint)));
            keypoint++;
            if (keypoint >= key.length())
                keypoint = 0;
        }
        return decrypted;
    }

    public static char getTrueValue(char raw) {
        int start = 32;
        int size = 94;
        return (char)(start + ((int)raw % size));
    }

    public static char getRawValue(char enc) {
        int start = 32;
        int size = 94;
        int rawenc = (int)enc - start;
        if (rawenc < 32)
            return (char)(rawenc + size);
        return (char)rawenc;
    }

    public static char getRangeValue(int value) {
        int newvalue = value;
        int start = 32;
        int size = 94;
        while (newvalue < start || newvalue >= (size + start))
            newvalue += size;
        return (char)newvalue;
    }
}
