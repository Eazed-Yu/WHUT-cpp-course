/*
`g++ -o driver.exe list.cpp stack.cpp queue.cpp driver.cpp`
`./driver.exe`
*/


#include "list.h"

int main() {
    system("chcp 65001 > nul");
    int arr[] = {1, 2, 3, 4, 21, 2, 42, 432};
    List *list = new List(arr, 8);
    list->print();
    std::cout << list;
    system("pause");
}