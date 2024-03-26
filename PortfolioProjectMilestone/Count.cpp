#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex mtx;
void countUp(int min, int max, int increment){
    cout << "Counting up: " << endl;
    for(int i = min; i <= max; i += increment){
        lock_guard<std::mutex> lock(mtx);
        cout << i << " ";
    }
    cout << endl;
}

void countDown(int min, int max, int increment) {
    cout << "Counting down: " << endl;
    for(int i = max; i >= min; i -= increment){
        lock_guard<std::mutex> lock(mtx);
        cout << i << " ";
    }
    cout << endl;
}

int main(){
    int min = 1, max = 20, increment = 1;
    thread t1(countUp, min, max, increment);
    t1.join();
    thread t2(countDown, min, max, increment);
    t2.join();
    return 0;
}