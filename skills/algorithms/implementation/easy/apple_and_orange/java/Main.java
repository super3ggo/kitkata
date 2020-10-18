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
    // static void countApplesAndOranges(int s, int t, int a, int b, int[] apples, int[] oranges) {
    // }

    // Imperative
    static void countApplesAndOranges(int s, int t, int a, int b, int[] apples, int[] oranges) {
        // Where
        // int s         = leftmost point of house
        // int t         = rightmost point of house
        // int a         = point of apple tree
        // int b         = point of orange tree
        // int[] apples  = points of fallen apples relative to the apple tree
        // int[] oranges = points of fallen apples relative to the apple tree

        // Motivation:
        // We can represent Sam's house as the set of all consecutive
        // Integers from s to t inclusive.
        //
        // We can represent the absolute points of fallen fruit as by
        // the expression:
        // \x -> x + y . [z]
        // where x  = an Integer
        //       y  = a | b
        //      [z] = apples | oranges
        //
        // Therefore, to determine the number of fruit that have landed
        // on Sam's house, we merely have to count the number of
        // elements returned from the above expression that belong with
        // the set representing Sam's house.
        //
        // BE CAREFUL when representing the returned expression of
        // landed fruit. If you choose to represent it as a set, then
        // you cannot account for fruit that have landed on the same
        // position (you made this mistake during your first crack at
        // this problem).

        Set<Integer> samHouse  = new HashSet<>();
        Integer contactApples  = 0;
        Integer contactOranges = 0;

        // Populate samHouse
        for (int i=s; i <= t; i++) {
            samHouse.add(i);
        }

        // Count fallen apples
        for (int i=0; i < apples.length; i++) {
            int absoluteDistance = apples[i] + a;
            if (samHouse.contains(absoluteDistance)) {
                contactApples++;
            }
        }

        // Count fallen oranges
        for (int i=0; i < oranges.length; i++) {
            int absoluteDistance = oranges[i] + b;
            if (samHouse.contains(absoluteDistance)) {
                contactOranges++;
            }
        }

        // Print
        System.out.println(contactApples);
        System.out.println(contactOranges);
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        String[] st = scanner.nextLine().split(" ");

        int s = Integer.parseInt(st[0]);

        int t = Integer.parseInt(st[1]);

        String[] ab = scanner.nextLine().split(" ");

        int a = Integer.parseInt(ab[0]);

        int b = Integer.parseInt(ab[1]);

        String[] mn = scanner.nextLine().split(" ");

        int m = Integer.parseInt(mn[0]);

        int n = Integer.parseInt(mn[1]);

        int[] apples = new int[m];

        String[] applesItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < m; i++) {
            int applesItem = Integer.parseInt(applesItems[i]);
            apples[i] = applesItem;
        }

        int[] oranges = new int[n];

        String[] orangesItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < n; i++) {
            int orangesItem = Integer.parseInt(orangesItems[i]);
            oranges[i] = orangesItem;
        }

        countApplesAndOranges(s, t, a, b, apples, oranges);

        scanner.close();
    }
}
