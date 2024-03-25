public class SynchronizedExample {
    public synchronized void method1() {
        // code to be executed by only one thread at a time
    }

    public void method2() {
        synchronized (this) {
            // code to be executed by only one thread at a time
        }
    }
}