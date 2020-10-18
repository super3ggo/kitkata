import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
import java.util.regex.*;

public class Main {
    //
    // Solutions:
    //

    // Functional
    // static String timeConversion(String s) {
    // }

    // Imperative
    static String timeConversion(String s) {
        // TODO:
        // 1. Split string by ":" and obtain the hour and AM/PM suffix
        // 2. If AM and the hour == 12 then subtract 12 from the hour
        // 3. If PM and the hour < 12 then add 12 to the hour
        // 4. Remove the AM/PM suffix

        String[] undelimited = s.split("\\:");
        String hour          = undelimited[0];
        String minute        = undelimited[1];
        String second        = undelimited[2].replaceAll("[a-zA-Z]", "");
        String meridiem      = undelimited[2].replaceAll("[0-9]+", "").toUpperCase();
        String hourAdjusted  = "";
        Integer hourAsInt    = Integer.parseInt(hour);

        if (meridiem.equals("AM")) {
            if (hourAsInt == 12) {
                // Return 00 instead of subtracting; doing this will
                // preserve the formatting for returning the String.
                hourAdjusted = "00";
            } else {
                hourAdjusted = hour;
            }
        } else {
            if (hourAsInt < 12) {
                hourAdjusted = String.valueOf(hourAsInt+=12);
            } else {
                hourAdjusted = hour;
            }
        }

        return hourAdjusted + ":" + minute + ":" + second;
    }

    private static final Scanner scan = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String s = scan.nextLine();

        String result = timeConversion(s);

        bw.write(result);
        bw.newLine();

        bw.close();
    }
}
