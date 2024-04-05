import java.util.concurrent.CountDownLatch;
import edu.princeton.cs.algs4.Stopwatch;

/**
 * A class that represents a count variable
 * that stores minimum and maximum, and increment values.
 * Default values for minimum and increment are 1
 */
public class Count {
    Stopwatch stopwatch;
    CountDownLatch latch = new CountDownLatch(1);
    private int min = 1;
    private int increment = 1;
    private final int MAX;

    /**
     * Represents a count variable
     * that stores minimum and maximum, and increment values.
     * @param max minimum value
     */
    public Count(int max) {
        this.stopwatch = new Stopwatch();
        this.MAX = max;
    }

    /**
     * Represents a count variable
     * that stores minimum and maximum, and increment values.
     * @param min minimum value
     * @param max minimum value
     */
    public Count(int min, int max) {
        this.stopwatch = new Stopwatch();
        this.min = min;
        this.MAX = max;
    }

    /**
     * Represents a count variable
     * that stores minimum and maximum, and increment values.
     * @param min minimum value
     * @param max minimum value
     * @param increment increment value
     */
    public Count(int min, int max, int increment) {
        this.stopwatch = new Stopwatch();
        this.min = min;
        this.MAX = max;
        this.increment = increment;
    }

    /**
     * Prints the elapsed CPU time (in milliseconds) since the stopwatch was created.
     */
    public void getElapsedTime() {
        synchronized (this) {
            try {
                latch.await();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            System.out.printf("\nDuration using the Java method: %.1f ms\n", stopwatch.elapsedTime() * 1000);
        }
    }

    /**
     * Counts up from minimum to maximum by the increment value.
     * By default, does not wait during concurrent threading.
     */
    public void countUp() {
        synchronized (this) {
            for (int i = min; i <= MAX; i += increment) {
                System.out.print(i + " ");
            }
            System.out.println();
        }
    }

    /**
     * Counts up from minimum to maximum by the increment value.
     * Notifies other threads when the count is done.
     * @param wait whether to wait for the other threads to finish.
     */
    public void countUp(boolean wait) {
        if (wait) {
            try {
                latch.await();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        countUp();
        latch.countDown();
    }

    /**
     * Counts down from maximum to minimum by the increment value.
     * By default, does not wait during concurrent threading.
     */
    public void countDown() {
        synchronized (this) {
            for (int i = MAX; i >= min; i -= increment) {
                System.out.print(i + " ");
            }
            System.out.println();
        }
    }

    /**
     * Counts down from maximum to minimum by the increment value.
     * Notifies other threads when the count is done.
     * @param wait whether to wait for the other threads to finish.
     */
    public void countDown(boolean wait) {
        if (wait) {
            try {
                latch.await();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        countDown();
        latch.countDown();
    }
}
