#include "stack.h"

bool ArrStack::push (int n) {
    if (this->size == ARR_MAX) {
        return false;
    }
    this->arr[this->size++] = n;
    return true;
}
bool ArrStack::pop(int &n) {
    if (is_empty())
        return false;
    n = this->arr[--this->size];
    return true;
}

bool ArrStack::is_full () const {
    return this->size == ARR_MAX;
}

bool ArrStack::is_empty () const {
    return this->size == 0;
}

int ArrStack::get_size () const {
    return this->size;
}

void ArrStack::print () const {
    int index = 0;
    std::cout << "[";
    while (index < size) {
        std::cout << this->arr[index];
        if (index != size - 1) {
            std::cout << ", ";
        }
        index++;
    }
    std::cout << "]" << std::endl;
}

ArrStack &ArrStack::operator+ (int n) {
    this->push(n);
    return *this;
}

ArrStack &ArrStack::operator- (int &n) {
    this->pop(n);
    return *this;
}

std::ostream &operator<< (std::ostream &os, const ArrStack &stk) {
    std::cout << "[";
    for (int i = 0; i < stk.get_size(); i++) {
        os << stk.arr[i];
        if (i != stk.get_size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
    return os;
}

std::ostream& operator<<(std::ostream &os, const ArrStack *stk) {
    return os << *stk;
}


