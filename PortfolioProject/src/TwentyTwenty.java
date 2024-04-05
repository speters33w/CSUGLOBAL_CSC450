/**
 * A Java application that will exhibit concurrency concepts.
 * The application creates two threads that will act as counters.
 * One thread counts up to 20.
 * Once thread one reaches 20, then a second thread counts down to 0.
 * Includes a timer thread that will print the elapsed time
 * for performance comparison to a C++ implementation.
 */
public class TwentyTwenty {
    static Count count = new Count(0,20);

    public static void main(String[] args) {
        Thread countUp = new Thread(() -> count.countUp(false));
        Thread countDown = new Thread(() -> count.countDown(true));
        // This additional thread is used for benchmarking.
        Thread timer = new Thread(() -> count.getElapsedTime());
        countUp.start();
        countDown.start();
        try {
            countDown.join();
        } catch (InterruptedException ie) {
            ie.printStackTrace();
        }
        timer.start();
        try {
            timer.join();
        } catch (InterruptedException ie) {
            ie.printStackTrace();
        }
    }
}
