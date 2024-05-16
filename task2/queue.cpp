#include "queue.h"
#include <iostream>


bool ArrQueue::enqueue (int n) {
    if (size == ARR_MAX) {
        return false;
    }
    if (size == 0) {
        this->front = 0;
        this->end = 0;
    }
    this->arr[end] = n;
    end = (end+1) %ARR_MAX;
    this->size++;
    return true;
}

bool ArrQueue::dequeue (int &n) {
    if (size == 0) {
        return false;
    }
    n = this->arr[front];
    front = (front+1) % ARR_MAX;
    this->size--;
    return true;
}


void ArrQueue::print (void) const {
    int index = front;
    std::cout << "[";
    while (index != end) {
        std::cout << this->arr[index];
        if ((index+1) % ARR_MAX != end) {
            std::cout << ", ";
        }
        index = (index+1) % ARR_MAX;
    }
    std::cout << "]" << std::endl;
}

ArrQueue &ArrQueue::operator+ (int n) {
    this->enqueue(n);
    return *this;
}

ArrQueue &ArrQueue::operator- (int &n) {
    this->dequeue(n);
    return *this;
}

std::ostream & operator<< (std::ostream &os, const ArrQueue &q) {
    q.print();
    return os;
}

std::ostream &operator<< (std::ostream &os, const ArrQueue *q) {
    return os << *q;
}

bool ListQueue::enqueue(int n) {
    lis.append(n);
    size++;
    return true;
}

bool ListQueue::dequeue(int &n) {
    if (is_empty()) {
        return false;
    }
    lis.delete_left(n); // 删除链表头部的元素
    size--;
    return true;
}

void ListQueue::print(void) const {
    lis.print(); // 打印链表内容
}


ListQueue &ListQueue::operator+(int n) {
    this->enqueue(n);
    return *this;
}

ListQueue &ListQueue::operator-(int &n) {
    this->dequeue(n);
    return *this;
}


std::ostream &operator<<(std::ostream &os, const ListQueue &q) {
    q.print();
    return os;
}

std::ostream &operator<<(std::ostream &os, const ListQueue *q) {
    return os << *q;
}