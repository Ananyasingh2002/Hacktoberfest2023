import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a decimal number: ");
        int decimal = scanner.nextInt();
        scanner.close();

        int[] binaryArray = new int[32];
        int index = 0;
        while (decimal > 0) {
            binaryArray[index++] = decimal % 2;
            decimal /= 2;
        }


        System.out.print("Binary is: ");
        for (int i = 0; i < index; i++) {
            System.out.print(binaryArray[i]);
        }
    }
}
