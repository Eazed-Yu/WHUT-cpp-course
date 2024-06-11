#include <iostream>
#include "Storage.h"

using namespace std;

int main() {

    Storage<double> *st[8];
    st[0] = new SingleList<double>;
    st[1] = new DoubleList<double>;
    st[2] = new ArrStack<double>;
    st[3] = new ListStack<double>;
    st[4] = new ArrQ<double>;
    st[5] = new ListQ<double>;
    st[6] = new Array<double>;
    st[7] = new CircleArr<double>;

    // testing the put_in() function
    for (int j = 0; j <= 5; j++) {
        for (int k = 0; k <= 7; k++) // put in 5 items
            st[k]->add(j + 1.0);
    }

    // testing the take_out() function
    for (int j = 0; j <= 7; j++) {
        double x;
        for (int k = 0; k <= 1; k++) // take out 2 items
            st[j]->remove(x);
    }

    // testing the print() and operator<< function
    for (int k = 0; k <= 7; k++) {
        cout << (*st[k]);  // test the polymorphic inheritance of, should print the class name
        cout << endl;
        cout << " is_full() ==  " << st[k]->isFull() << endl;
        cout << " is_empty() ==  " << st[k]->isEmpty() << endl;
        cout << " size() == " << st[k]->getSize() << endl;
        cout << "-----------------" << endl;
    }
    // test the methods of the 8 decendant classes of Storage.

    return 0;
}
