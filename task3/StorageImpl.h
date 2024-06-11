//
// Created by Eazed on 24-6-5.
//

#ifndef TASK3_STORAGEIMPL_H
#define TASK3_STORAGEIMPL_H

#include "Storage.h"

template<typename T>
SingleList<T>::SingleList() : head(nullptr), tail(nullptr), size(0) {}

template<typename T>
SingleList<T>::~SingleList() {
    Node *current = head;
    while (current) {
        Node *tmp = current;
        current = current->next;
        delete tmp;
    }
    head = nullptr;
    tail = nullptr;
}


template<typename T>
bool SingleList<T>::append(T n) {
    if (!isFull()) {
        Node *node = new Node(n);
        if (tail) {
            tail->next = node;
            tail = node;
        } else {
            head = tail = node;
        }
        size++;
        return true;
    }
}

template<typename T>
bool SingleList<T>::prepend(T n) {
    if (!isFull()) {
        Node *node = new Node(n);
        if (head) {
            node->next = head;
            head = node;
        } else {
            head = tail = node;
        }
        size++;
        return true;
    }
    return false;
}

template<typename T>
bool SingleList<T>::delete_head(T &n) {
    if (head) {
        Node *temp = head;
        head = head->next;

        n = temp->data;
        delete temp;

        if (head == nullptr) {
            tail = nullptr;
        }
        size--;
        return true;
    }
    return false;
}


template<typename T>
bool SingleList<T>::delete_tail(T &n) {
    if (tail) {
        n = tail->data;
        if (tail == head) {
            delete tail;
            head = tail = nullptr;
        } else {
            Node *current = head;
            while (current->next != tail) {
                current = current->next;
            }
            delete tail;
            tail = current;
            tail->next = nullptr;
        }
        size--;
        return true;
    }
    return false;
}

template<typename T>
void SingleList<T>::print() {
    Node *current = head;
    std::cout << "[";
    while (current != nullptr) {
        std::cout << current->data;
        if (current->next != nullptr) {
            std::cout << ", ";
        }
        current = current->next;
    }
    std::cout << "]" << std::endl;
}

template<typename T>
bool SingleList<T>::find(T n) {
    Node *current = head;
    while (current) {
        if (current->data == n) {
            return true;
        }
        current = current->next;
    }
    return false;
}

template<typename T>
DoubleList<T>::DoubleList() : head(nullptr), tail(nullptr), size(0) {}

template<typename T>
DoubleList<T>::~DoubleList() {
    Node *current = head;
    while (current) {
        Node *tmp = current;
        current = current->next;
        delete tmp;
    }
    head = nullptr;
    tail = nullptr;
}


template<typename T>
void DoubleList<T>::print() {
    Node *current = head;
    std::cout << "[";
    while (current != nullptr) {
        std::cout << current->data;
        if (current->next != nullptr) {
            std::cout << ", ";
        }
        current = current->next;
    }
    std::cout << "]" << std::endl;
}

template<typename T>
bool DoubleList<T>::find(T n) {
    Node *current = head;
    while (current) {
        if (current->data == n) {
            return true;
        }
        current = current->next;
    }
    return false;
}


template<typename T>
bool DoubleList<T>::append(T n) {
    if (!isFull()) {
        Node *node = new Node(n);
        if (tail) {
            tail->next = node;
            tail = node;
        } else {
            head = tail = node;
        }
        size++;
        return true;
    }
}

template<typename T>
bool DoubleList<T>::prepend(T n) {
    if (!isFull()) {
        Node *node = new Node(n);
        if (head) {
            node->next = head;
            head = node;
        } else {
            head = tail = node;
        }
        size++;
        return true;
    }
    return false;
}

template<typename T>
bool DoubleList<T>::delete_head(T &n) {
    if (head) {
        Node *temp = head;
        head = head->next;

        n = temp->data;
        delete temp;

        if (head == nullptr) {
            tail = nullptr;
        }
        size--;
        return true;
    }
    return false;
}

template<typename T>
bool DoubleList<T>::delete_tail(T &n) {
    if (tail) {
        n = tail->data;
        if (tail == head) {
            delete tail;
            head = tail = NULL;
        } else {
            Node *current = head;
            while (current->next != tail) {
                current = current->next;
            }
            delete tail;
            tail = current;
            tail->next = NULL;
        }
        size--;
        return true;
    }
    return false;
}

template<typename T>
Array<T>::Array(unsigned int n) : MAX_SIZE(n) {
    arr = new T[n]();
}

template<typename T>
Array<T>::~Array() {
    delete arr;
    arr = nullptr;
    size = 0;
}


template<typename T>
bool Array<T>::add(T n) {
    if (size < MAX_SIZE) {
        arr[size++] = n;
        return true;
    }
    return false;
}

template<typename T>
bool Array<T>::remove(T &n) {
    if (size > 0) {
        n = arr[--size];
        return true;
    }
    return false;
}

template<typename T>
void Array<T>::print() {
    int index = size;
    std::cout << "[";
    while (index--) {
        std::cout << arr[size - index - 1];
        if (index != 0) {
            std::cout << ", ";
        }
    }
    std::cout << "]";
}

template<typename T>
bool Array<T>::find(T n) {
    for (auto i: arr) {
        if (i == n) {
            return true;
        }
    }
    return false;
}

template<typename T>
const T Array<T>::operator[](int n) const {
    return arr[n];
}

template<typename T>
T &Array<T>::operator[](int n) {
    return arr[n];
}

template<typename T>
CircleArr<T>::CircleArr(unsigned int s, unsigned int limit): Array<T>(limit), start(s) {}

template<typename T>
bool CircleArr<T>::add(T n) {
    return Array<T>::add(n);
}

template<typename T>
bool CircleArr<T>::remove(T &n) {
    return Array<T>::remove(n);
}

template<typename T>
void CircleArr<T>::print() {
    Array<T>::print();
}

template<typename T>
bool CircleArr<T>::find(T n) {
    return Array<T>::find(n);
}

template<typename T>
CircleArr<T>::CircleArr(const CircleArr &arr) : Array<T>(arr) {
    start = arr.start;
}

template<typename T>
Array<T> &CircleArr<T>::operator=(CircleArr<T> &ref) {
    Array<T>::operator=(ref);
    start = ref.start;
    return *this;
}

template<typename T>
ArrStack<T>::ArrStack(unsigned int n) : MAX_SIZE(n) {
    arr = new T[n]();
}

template<typename T>
unsigned int ArrStack<T>::getSize() {
    return size;
}

template<typename T>
bool ArrStack<T>::isEmpty() {
    return size == 0;
}

template<typename T>
bool ArrStack<T>::isFull() {
    return size == MAX_SIZE;
}

template<typename T>
bool ArrStack<T>::add(T n) {
    return push(n);
}

template<typename T>
bool ArrStack<T>::remove(T &t) {
    return pop(t);
}

template<typename T>
bool ArrStack<T>::find(T item) {
    for (signed int i = 0; i < size; ++i) {
        if (arr[i] == item) {
            return true;
        }
    }
    return false;
}

template<typename T>
void ArrStack<T>::print() {
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

template<typename T>
bool ArrStack<T>::push(T n) {
    if (size < MAX_SIZE) {
        arr[size++] = n;
        return true;
    }
    return false;
}

template<typename T>
bool ArrStack<T>::pop(T &n) {
    if (size > 0) {
        n = arr[--size];
        return true;
    }
    return false;
}

template<typename T>
ListStack<T>::ListStack() : lis(DoubleList<T>()) {

}

template<typename T>
unsigned int ListStack<T>::getSize() {
    return size;
}

template<typename T>
bool ListStack<T>::isEmpty() {
    return size == 0;
}

template<typename T>
bool ListStack<T>::isFull() {
    return size == MAX_SIZE;
}

template<typename T>
bool ListStack<T>::add(T n) {
    return push(n);
}

template<typename T>
bool ListStack<T>::remove(T &t) {
    return pop(t);
}

template<typename T>
bool ListStack<T>::find(T item) {
    return lis.find(item);
}

template<typename T>
void ListStack<T>::print() {
    lis.print();
}

template<typename T>
bool ListStack<T>::push(T item) {
    if (!isFull()) {
        lis.append(item);
        size++;
        return true;
    }
    return false;
}

template<typename T>
bool ListStack<T>::pop(T &n) {
    bool succeed = lis.delete_tail(n);
    if (succeed) {
        --size;
    }
    return succeed;
}


#endif //TASK3_STORAGEIMPL_H
