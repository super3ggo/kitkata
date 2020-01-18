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
    // static void miniMaxSum(int[] arr) {
    // }

    // Imperative
    static void miniMaxSum(int[] arr) {
        // We use 64 bit integers here incase of overflow. Heh.
        long sumMin = 0;
        long sumMax = 0;

        // The argument array does not come sorted. We'll use this
        // sorting function from the Arrays library for now, but later
        // on in the problem sets, we'll more than likely have to
        // implement our own sorting function. Perhaps many times over.
        Arrays.sort(arr);

        for (int i=0; i < arr.length; i++) {
            if (i != arr.length - 1) {
                sumMin+=arr[i];
            }

            if (i != 0) {
                sumMax+=arr[i];
            }
        }

        System.out.println(sumMin + " " + sumMax);
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int[] arr = new int[5];

        String[] arrItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < 5; i++) {
            int arrItem = Integer.parseInt(arrItems[i]);
            arr[i] = arrItem;
        }

        miniMaxSum(arr);

        scanner.close();
    }
}
