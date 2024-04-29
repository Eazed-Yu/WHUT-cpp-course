/*
`g++ -o driver.exe list.cpp stack.cpp queue.cpp driver.cpp`
`./driver.exe`
*/


#include "list.h"
#include "stack.h"

int main() {
    system("chcp 65001 > nul");
    int arr[] = {1, 2, 3, 4, 21, 2, 42, 432};
    List *list = new List(arr, 8);
    list->print();
    std::cout << list;
    ArrStack arrStack;
    arrStack.push(1);
    arrStack.push(2);
    arrStack.push(3);
    arrStack.push(4);
    arrStack.push(5);
    arrStack.push(6);
    arrStack = arrStack + 5;
    int n;
    arrStack - n;
    arrStack.print();
    ListStack listStack;
    listStack.push(10);
    listStack.push(10);
    listStack.push(10);
    listStack.push(10);
    listStack.push(10);
    std::cout << listStack;
    system("pause");
}