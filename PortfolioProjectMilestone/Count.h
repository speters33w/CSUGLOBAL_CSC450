#include <iostream>
#include <mutex>
#include <condition_variable>

using namespace std;

/*
 * An object class that stores a minimum, a maximum, and an incremental value for counting.
 * Class methods allow a countUp or countDown
 * with or without a mutex lock to wait for other threads to complete.
 */
class Count {
public:
    // Constructs the object and initializes the variables
    explicit Count(int min = 1, int max = 20, int increment = 1)
            : min_(min), max_(max), increment_(abs(increment)) {}

    // Initiates countUp() with wait false as a default.
    void countUp() {
        countUp(false);
    }
    // Counts from the minimum to the maximum.
    // Initiates a thread-lock if wait is true.
    // Notifies listening threads the thread is complete.
    void countUp(bool wait){
        if (wait) {
            unique_lock<mutex> lock(mutex_);
            cv_.wait(lock, [this] { return count_ == max_; });
        }
        for (int i = min_; i <= max_; i += increment_) {
            cout << i << " ";
        }
        cout << endl;
        count_ = min_;
        cv_.notify_all();
    }

    // Initiates countDown() with wait false as a default.
    void countDown() {
        countDown(false);
    }
    // Counts from the maximum to the minimum.
    // Initiates a thread-lock if wait is true.
    // Notifies listening threads the thread is complete.
    void countDown(bool wait) {
        if (wait) {
            unique_lock<mutex> lock(mutex_);
            cv_.wait(lock, [this] { return count_ == min_; });
        }
        for (int i = max_; i >= min_; i -= increment_) {
            cout << i << " ";
        }
        cout << endl;
        count_ = max_;
        cv_.notify_all();
    }

private:
    // Initialize variables that can be used as references.
    int min_, max_, increment_;
    int count_ = min_;
    mutex mutex_;
    condition_variable cv_;
};
