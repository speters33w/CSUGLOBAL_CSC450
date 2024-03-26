#include <iostream>
#include <mutex>

using namespace std;

mutex mtx;
static void staticCountUp(int min, int max, int increment){
    for(int i = min; i <= max; i += increment){
        lock_guard<std::mutex> lock(mtx);
        cout << i << " ";
    }
    cout << endl;
}

static void staticCountDown(int min, int max, int increment) {
    for(int i = max; i >= min; i -= increment){
        lock_guard<std::mutex> lock(mtx);
        cout << i << " ";
    }
    cout << endl;
}
