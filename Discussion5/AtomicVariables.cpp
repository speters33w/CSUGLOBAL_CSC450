#include <iostream>
#include <thread>
#include <atomic>

std::atomic<bool> flag1(false), flag2(false);

void thread1() {
    while (true) {
        flag1.store(true, std::memory_order_relaxed);
        while (flag2.load(std::memory_order_relaxed)) {
            std::this_thread::yield();
        }

        // Critical section

        std::cout << "Thread 1 entered critical section\n";
        flag1.store(false, std::memory_order_relaxed);
    }
}

void thread2() {
    while (true) {
        flag2.store(true, std::memory_order_relaxed);
        while (flag1.load(std::memory_order_relaxed)) {
            std::this_thread::yield();
        }

        // Critical section
        std::cout << "Thread 2 entered critical section\n";
        flag2.store(false, std::memory_order_relaxed);
    }
}

int main() {
    std::thread t1(thread1);
    std::thread t2(thread2);
    t1.join();
    t2.join();
    return 0;
}


