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
    // static int birthdayCakeCandles(int[] arr) {
    // }

    // Imperative
    static int birthdayCakeCandles(int[] arr) {
        // 1. Sort the array.
        // 2. Get the element at the last index, i.e. the maximum value.
        // 3. Loop through the array to count how many maximum values there are.

        // The argument array does not come sorted. We'll use this
        // sorting function from the Arrays library for now, but later
        // on in the problem sets, we'll more than likely have to
        // implement our own sorting function. Perhaps many times over.
        Arrays.sort(arr);

        int maxValue = arr[arr.length - 1];
        int maxCount = 0;

        for (int i=0; i < arr.length; i++) {
            if (arr[i] == maxValue) {
                maxCount++;
            }
        }

        return maxCount;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int arCount = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        int[] ar = new int[arCount];

        String[] arItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < arCount; i++) {
            int arItem = Integer.parseInt(arItems[i]);
            ar[i] = arItem;
        }

        int result = birthdayCakeCandles(ar);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
