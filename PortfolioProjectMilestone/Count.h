#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <type_traits>

using namespace std;

class Count {
public:
    explicit Count(int min = 1, int max = 10, int increment = 1)
            : min_(min), max_(max), increment_(increment) {}

    void countUp() const {
        for (int i = min_; i <= max_; i += increment_) {
            cout << i << endl;
        }
        cout << endl;
    }

    void countUp(bool wait) {
        if (wait) {
            unique_lock<mutex> lock(mutex_);
            cv_.wait(lock, [this] { return count_ == max_; });
        }
        for (int i = min_; i <= max_; i += increment_) {
            cout << i << endl;
        }
        cout << endl;
        count_ = min_;
        cv_.notify_all();
    }

    void countDown() const {
        for (int i = max_; i >= min_; i -= increment_) {
            cout << i << endl;
        }
        cout << endl;
    }

    void countDown(bool wait) {
        if (wait) {
            unique_lock<mutex> lock(mutex_);
            cv_.wait(lock, [this] { return count_ == min_; });
        }
        for (int i = max_; i >= min_; i -= increment_) {
            cout << i << endl;
        }
        cout << endl;
        count_ = max_;
        cv_.notify_all();
    }

private:
    int min_, max_, increment_;
    int count_ = min_;
    mutex mutex_;
    condition_variable cv_;
};