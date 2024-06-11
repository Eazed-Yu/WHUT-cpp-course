#include <iostream>
#include "Storage.h"

int main() {
    Array<int>* array = new Array<int>();
    CircleArr<int>* circleArr = new CircleArr<int>();
    SingleList<int>* singleList = new SingleList<int> ();
    DoubleList<int>* doubleList = new DoubleList<int> ();
    ArrStack<int>* arrStack = new ArrStack<int> ();
    ListStack<int>* listStack = new ListStack<int> ();
    ArrQ<int>* arrQ = new ArrQ<int> ();

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
