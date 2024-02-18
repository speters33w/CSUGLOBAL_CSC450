#include <iostream>
#include <string>
using namespace std;

int main() {
    struct {
        string make ="Honda";
        string model ="Civic";

    } car;
    cout << car.make  + " " + car.model + "\n";
    car.model = "Accord";
    cout << car.make + " " + car.model + "\n";
    return 0;
}
