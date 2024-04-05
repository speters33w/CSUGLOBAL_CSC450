import java.nio.charset.StandardCharsets;
import java.util.Scanner;

public class GradeCalculator {

    private final double maxGrade;

    /**
     * Creates a new GradeCalculator object.
     * @param maxGrade the maximum grade in the scale, e.g., 4.0 or 100.
     */
    public GradeCalculator(double maxGrade) {
        this.maxGrade = maxGrade;
    }


    /**
     * Gets the grades[] array from the user and calculates the final grade.
     * This method also demonstrates scope minimization by accessing private methods.
     *
     * @return The final grade.
     */
    public double gradeCalculator() {
        int numberOfSubjects = subjectsEntryForStudent();
        double[] grades = gradesEntryForStudents(numberOfSubjects);
        return calculateFinalGrade(grades);
    }

    /**
     * Gets the number of subjects the student has from the user.
     * Catches NumberFormatException for non-integer values.
     * @return the number of subjects the student has.
     */
    private int subjectsEntryForStudent() {
        Scanner in = new Scanner(System.in, StandardCharsets.UTF_8);
        int numberOfSubjects = 0;
        System.out.println("Enter the number of subjects for the student: ");
        boolean valid = false; // Used to break out of the while loop.
        do {
            try {
                // Validate the input, force integer value to absolute value.
                numberOfSubjects = Math.abs(Integer.parseInt(in.nextLine()));
                valid = true;
            } catch (NumberFormatException nfe) {
                // If the input is not an integer, restart the loop.
                System.out.println("Invalid input. \n Please Enter the number of subjects: ");
            }
        } while (!valid);
        return numberOfSubjects;
    }

    /**
     * Gets the grades[] array from the user.
     *
     * @param numberOfSubjects The number of subjects the student has.
     * @return The grades[] array from the user.
     */
    private double[] gradesEntryForStudents(int numberOfSubjects) {
        Scanner in = new Scanner(System.in, StandardCharsets.UTF_8);
        double[] grades = new double[numberOfSubjects];
        System.out.println();
        for (int i = 0; i < grades.length; i++) {
            System.out.printf("Please enter grade #%d for this student: ", i + 1);
            double grade = in.nextDouble();
            grades[i] = grade;
        }
        in.close();
        return grades;
    }

    /**
     * Calculates the final grade.
     * Catches an ArrayIndexOutOfBoundsException if the grades[] array is empty.
     * Throws an IllegalArgumentException if the final grade is invalid.
     *
     * @param grades The grades[] array from the user.
     * @return The final grade.
     */
    private double calculateFinalGrade(double[] grades) {
        int smallestIndex = 0;
        double firstGrade = 0.0;
        try {
            firstGrade = grades[0];
        } catch (ArrayIndexOutOfBoundsException ioob) {
            System.out.println("Minimum one subject required.");
        }
        if (grades.length == 1) {
            return grades[0];
        }
        for (int i = 0; i <= grades.length; i++) {
                smallestIndex = i;
        }
        // Note: This is only to demonstrate the try-catch block with firstGrade.
        // Normally the sum would = 0.0 and int i would = 0.
        double sum = firstGrade;
        for (int i = 1; i < grades.length; i++) {
            if (i != smallestIndex) {
                sum = sum + grades[i];
            }
        }
        double finalGrade = sum / (grades.length);
        if (finalGrade <= 0 || finalGrade > maxGrade) {
            throw new IllegalArgumentException("Invalid final grade: " + finalGrade);
        }
        return finalGrade;
    }

    /**
     * Main driver method.
     */
    public static void main(String[] args) {
        GradeCalculator gradeCalculator = new GradeCalculator(4.0);
        double finalGrade = gradeCalculator.gradeCalculator();
        System.out.printf("The final grade is: %.2f%n", finalGrade);
    }
}