import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Main {
    //
    // Solutions:
    //

    // Functional
    // static void plusMinus(int[] arr) {
    // }

    // Imperative
    static void plusMinus(int[] arr) {
        int arrLength = arr.length;
        int countPositive = 0;
        int countNegative = 0;
        int countZero = 0;

        for (int i=0; i < arrLength; i++) {
            if (arr[i] > 0) {
                countPositive++;
            } else if (arr[i] < 0) {
                countNegative++;
            } else {
                countZero++;
            }
        }

        System.out.println(String.format("%.6f", countPositive / Double.valueOf(arrLength)));
        System.out.println(String.format("%.6f", countNegative / Double.valueOf(arrLength)));
        System.out.println(String.format("%.6f", countZero / Double.valueOf(arrLength)));
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int n = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        int[] arr = new int[n];

        String[] arrItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < n; i++) {
            int arrItem = Integer.parseInt(arrItems[i]);
            arr[i] = arrItem;
        }

        plusMinus(arr);

        scanner.close();
    }
}
