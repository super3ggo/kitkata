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

class Result {
    //
    // Solutions:
    //

    // Functional
    // public static List<Integer> gradingStudents(List<Integer> grades) {
    // }

    // Imperative
    public static List<Integer> gradingStudents(List<Integer> grades) {
        // Stipulations on rounding:
        // 1. Grade cannot be a multiple of 5.
        // 2. Grade cannot be less than 38.
        // 3. If grade's one's place is 3 or 4, round it to 5.
        // 4. If grade's one's place is 8 or 9, round the ten's place to the next number.

        List<Integer> gradesRounded = new ArrayList<>();

        for (int i=0; i < grades.size(); i++) {
            int grade      = grades.get(i);
            int gradeFinal = 0;

            if (grade % 5 != 0 &&
                grade > 37) {
                switch (grade % 10) {
                case 3:
                    gradeFinal = grade + 2;
                    break;
                case 4:
                    gradeFinal = grade + 1;
                    break;
                case 8:
                    gradeFinal = grade - (grade % 10) + 10;
                    break;
                case 9:
                    gradeFinal = grade - (grade % 10) + 10;
                    break;
                default:
                    gradeFinal = grade;
                }
            } else {
                gradeFinal = grade;
            }

            gradesRounded.add(gradeFinal);
        }

        return gradesRounded;
    }
}

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int gradesCount = Integer.parseInt(bufferedReader.readLine().trim());

        List<Integer> grades = IntStream.range(0, gradesCount).mapToObj(i -> {
                try {
                    return bufferedReader.readLine().replaceAll("\\s+$", "");
                } catch (IOException ex) {
                    throw new RuntimeException(ex);
                }
            })
            .map(String::trim)
            .map(Integer::parseInt)
            .collect(toList());

        List<Integer> result = Result.gradingStudents(grades);

        bufferedWriter.write(
                             result.stream()
                             .map(Object::toString)
                             .collect(joining("\n"))
                             + "\n"
                             );

        bufferedReader.close();
        bufferedWriter.close();
    }
}
