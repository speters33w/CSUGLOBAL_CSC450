#include <iostream>
#include <thread>
#include <stack>
#include <queue>
#include <mutex>

using namespace std;
queue<stack<string>> orderQueue;
mutex criticalLock;

void orderProcess(int threadNum){
    stack<string> thisOrder;
    //criticalLock.lock();
    if (!orderQueue.empty()) {
        thisOrder = orderQueue.front();
        orderQueue.pop();
        //criticalLock.unlock();

        string orderBag[thisOrder.size()];
        int i = 0;
        while (!thisOrder.empty()) {
            orderBag[i] = thisOrder.top();
            thisOrder.pop();
            i++;
        }
        //criticalLock.lock();
        cout << "Order of: " << endl;
        for (int j = 0; j < i; j++) {
            if (j < i - 1) {
                cout << orderBag[j] << ", ";
            } else {
                cout << orderBag[j] << " ";
            }
        }
        cout << "ready! Prepared by thread: " << threadNum << endl;
        //criticalLock.unlock();
    }
    else {
        //criticalLock.unlock();
    }
}

int order_process_main(){
    // Adding orders
    stack<string> order1;
    order1.emplace("Milkshake"); //Clang-Tidy push equivalent
    order1.emplace("Burger");
    order1.emplace("Fries");
    order1.emplace("Coke");
    criticalLock.lock();
    orderQueue.push(order1);
    criticalLock.unlock();

    stack<string> order2;
    order2.emplace("Burger");
    order2.emplace("Ice Cream Cone");
    order2.emplace("Fries");
    order2.emplace("Ice Tea");
    criticalLock.lock();
    orderQueue.push(order2);
    criticalLock.unlock();

    stack<string> order3;
    order3.emplace("Cheese Burger");
    order3.emplace("Chicken Sandwich");
    order3.emplace("Strawberry Milkshake");
    order3.emplace("Doughnut");
    criticalLock.lock();
    orderQueue.push(order3);
    criticalLock.unlock();

    //Processing orders
    cout<<"Processing Orders:"<<endl;
    while (!orderQueue.empty()) {
        thread threadObj1(orderProcess, 1);
        thread threadObj2(orderProcess, 2);
        threadObj1.join();
        threadObj2.join();
    }

    cout<<"All orders processed. Goodbye."<<endl;
    return 0;
}