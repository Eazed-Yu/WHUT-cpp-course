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
