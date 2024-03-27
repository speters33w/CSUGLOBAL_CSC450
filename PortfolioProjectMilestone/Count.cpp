/*
 * Creates two threads that will act as counters.
 * One thread counts up to 20.
 * Once the first reaches 20, then a second thread counts down to 0.
 * Demonstrates a non-static object method with a worker function,
 * and a static method using static functions.
 * (Count.cpp)
 */
#include "Count.h"
#include "StaticCount.h"

using namespace std;

// This is a worker function that allows the threads to use non-static functions.
auto worker(int min, int max, signed int increment, bool descending, bool wait) {
    // Initialize variables.
    int min_ = min, max_ = max;
    int count_;
    mutex mutex_;
    condition_variable cv_;
    // Create a non-static Count object.
    Count counter(min, max, increment);

    // Counts from the maximum to the minimum.
    // Initiates a thread-lock if wait is true.
    // Notifies listening threads the thread is complete.
    if (descending) {
        if (wait) {
            unique_lock<mutex> lock(mutex_);
            cv_.wait(lock, [&count_, &min_] { return count_ == min_; });
        }
        counter.countDown();
        count_ = min_;
        cv_.notify_all();
    // Counts from the minimum to the maximum.
    // Initiates a thread-lock if wait is true.
    // Notifies listening threads the thread is complete.
    } else {  // if(!descending)
        if (wait) {
            unique_lock<mutex> lock(mutex_);
            cv_.wait(lock, [&count_, &max_] { return count_ == max_; });
        }
        counter.countUp();
        count_ = max_;
        cv_.notify_all();
    }
}

// Main driver class that shows the count up and count down
// using non-static and static methods.
int main() {
    // Initialize the minimum, maximum, and increment.
    int min = 1, max = 20, increment = 1;

    // Using a non-static object through a worker function.
    cout << "This demonstrates using a non-static class object for the threads." << endl;
    thread t1(worker, min, max, increment, false, false);
    t1.join();
    thread t2(worker, min, max, increment, true, false);
    t2.join();

    // Using static functions.
    cout << endl << "This demonstrates using a static functions for the threads." << endl;
    thread t3(staticCountUp, min, max, increment);
    t3.join();
    thread t4(staticCountDown, min, max, increment);
    t4.join();
    return 0;
}
