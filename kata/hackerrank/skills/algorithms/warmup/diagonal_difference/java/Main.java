import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;

public class Main {
    //
    // Solutions:
    //

    // Functional
    // public static int diagonalDifference(List<List<Integer>> arr) {
    //     // Write your code here

    // }

    // Imperative
    public static int diagonalDifference(List<List<Integer>> arr) {
        // Steps:
        // 0. Find the length of the diagonal array, i.e. n.
        // 1. Convert the two dimensional array into a one dimensional array going top-to-bottom and left-to-right.
        // 2. Iterate left-to-right (LTR) diagonal array n times, choosing the value at index modulo n + 1.
        // 3. Iterate right-to-left (RTL) diagonal array n times, choosing the value at index modulo n - 1.
        // 4. Evaluate the expression: ABS(LTR - RTL).
        //
        // Write your code here

        List<Integer> arrFlattened = new ArrayList<>();

        // Step 1. I.e. We assume that it's a square array.
        int diagonalLength = arr.size();
        int incrementLtr = diagonalLength + 1;
        int incrementRtl = diagonalLength - 1;

        int countLtr = 0;
        int countRtl = 0;
        int sumLtr = 0;
        int sumRtl = 0;

        // Step 2. "Flatten" the array.
        for (int i=0; i < diagonalLength; i++) {
            for (int j=0; j < diagonalLength; j++) {
                arrFlattened.add(arr.get(i).get(j));
            }
        }

        // Step 3. Iterate accordingly.
        for (int i=0; i < arrFlattened.size(); i++) {
            if (i % incrementLtr == 0) {
                if (countLtr < diagonalLength) {
                    sumLtr += arrFlattened.get(i);
                    countLtr++;
                }
            }

            if (i != 0 && i % incrementRtl == 0) {
                if (countRtl < diagonalLength) {
                    sumRtl += arrFlattened.get(i);
                    countRtl++;
                }
            }
        }

        // Step 4. Evaluate the expression.
        return Math.abs(sumLtr - sumRtl);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int n = Integer.parseInt(bufferedReader.readLine().trim());

        List<List<Integer>> arr = new ArrayList<>();

        IntStream.range(0, n).forEach(i -> {
                try {
                    arr.add(
                            Stream.of(bufferedReader.readLine().replaceAll("\\s+$", "").split(" "))
                            .map(Integer::parseInt)
                            .collect(toList())
                            );
                } catch (IOException ex) {
                    throw new RuntimeException(ex);
                }
            });

        int result = diagonalDifference(arr);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedReader.close();
        bufferedWriter.close();
    }
}
