#include "stack.h"

// ArrStack

// 压栈操作
bool ArrStack::push (int n) {
    if (this->size == ARR_MAX) {
        return false;
    }
    this->arr[this->size++] = n;
    return true;
}

// 出栈操作
bool ArrStack::pop(int &n) {
    if (is_empty())
        return false;
    n = this->arr[--this->size];
    return true;
}

// 打印栈中的所有元素
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

// 重载+操作符进行压栈
ArrStack &ArrStack::operator+ (int n) {
    this->push(n);
    return *this;
}

// 重载-操作符进行出栈
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

// ListStack
// 压栈操作
bool ListStack::push (int n) {
    if(this->lis.length() == LIST_MAX) {
        return false;
    }
    this->lis.prepend(n);
    return true;
}

// 出栈操作
bool ListStack::pop (int &n) {
    if (this->lis.length() == 0) {
        return false;
    }
    return this->lis.delete_right(n);
}

// 打印栈中的所有元素
void ListStack::print () const { this->lis.print(); }

// 重载+操作符进行压栈
ListStack &ListStack::operator+ (int n) {
    this->push(n);
    return *this;
}

// 重载-操作符进行出栈
ListStack &ListStack::operator- (int &n) {
    this->pop(n);
    return *this;
}

std::ostream &operator<< (std::ostream &os, const ListStack &lstk) {
    lstk.print();
    return os;
}

std::ostream &operator<< (std::ostream &os, const ListStack *lstk) {
    return os << *lstk;
}