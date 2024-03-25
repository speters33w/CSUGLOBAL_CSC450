import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class ConcurrentExecutor {
    private final ExecutorService pool;

    public ConcurrentExecutor(ExecutorService pool) {
        this.pool = pool;
    }

    public static void main(String[] args) {
        System.out.printf("Main thread is- %s\n", Thread.currentThread().getName());
        Thread t1 = new Thread(new ConcurrentExecutor(Executors.newFixedThreadPool(5)).new RunnableImpl());
        Thread t2 = new Thread(new ConcurrentExecutor(Executors.newFixedThreadPool(5)).new RunnableImpl());
        t1.start();
        t2.start();
    }

    private class RunnableImpl implements Runnable {

        @Override
        public void run() { // run the service
                pool.execute(new ExampleClass());
        }
    }

    private static class ExampleClass implements Runnable {

        @Override
        public void run() {
            System.out.printf("pool thread is- %s\n", Thread.currentThread().getName());
        }
    }
}