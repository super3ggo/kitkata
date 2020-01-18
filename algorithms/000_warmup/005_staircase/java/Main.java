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
    // static void staircase(int n) {
    // }

    // Imperative
    static void staircase(int n) {
        char miss = ' ';
        char step = '#';

        // Need to shift the loop over one to avoid printing a blank
        // line at "the top" of the staircase in addition to preventing
        // the longest flight, i.e. "the bottom," from being one step
        // short.
        for (int i=1; i <= n; i++) {
            char[] air    = new char[n - i];
            char[] flight = new char[i];

            Arrays.fill(air, miss);
            Arrays.fill(flight, step);

            System.out.println(new String(air) + new String(flight));
        }
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int n = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        staircase(n);

        scanner.close();
    }
}
