//
// Created by Eazed on 24-6-5.
//

#ifndef TASK3_STORAGEIMPL_H
#define TASK3_STORAGEIMPL_H

#include "storage.h"

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

#endif //TASK3_STORAGEIMPL_H
