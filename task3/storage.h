//
// Created by Eazed on 24-6-3.
//

#ifndef TASK3_STORAGE_H
#define TASK3_STORAGE_H


#include <iostream>


template<typename T>
class storage {
public:
    virtual ~storage() = default;

    virtual unsigned int getSize() = 0;

    virtual bool isEmpty() = 0;

    virtual bool isFull() = 0;

    virtual bool add(T n) = 0;

    virtual bool remove(T &) = 0;

    virtual bool find(T item) = 0;

    virtual void print() = 0;
};

template<typename T>
class List : public storage<T> {
    virtual ~List() = default;

    virtual bool append(T n) = 0;

    virtual bool prepend(T n) = 0;

    virtual bool delete_head(T &n) = 0;

    virtual bool delete_tail(T &n) = 0;
};

template<typename T>
class SingleList : public List<T> {
public:
    SingleList();

    ~SingleList();

    unsigned int getSize() override { return size; };

    bool isEmpty() override { return size == 0; };

    bool isFull() override { return size == MAX_SIZE; };

    bool add(T n) override { return append(n); };

    bool remove(T &n) override { return delete_head(n); };

    void print() override;

    bool find(T n) override;

    bool append(T n) override;

    bool prepend(T n) override;

    bool delete_head(T &n) override;

    bool delete_tail(T &n) override;

private:
    struct Node {
        Node(const T &data) : data(data), next(nullptr) {

        }

        T data;
        Node *next;
    };

    Node *head;
    Node *tail;
    unsigned int size;
    unsigned int MAX_SIZE = 1000;
};

template<typename T>
class DoubleList : public List<T> {
public:

    DoubleList();

    ~DoubleList();

    unsigned int getSize() override { return size; };

    bool isEmpty() override { return size == 0; };

    bool isFull() override { return size == MAX_SIZE; };

    bool add(T n) override { return append(n); };

    bool remove(T &n) override { return delete_head(n); };

    void print() override;

    bool find(T n) override;

    bool append(T n);

    bool prepend(T n);

    bool delete_head(T &n);

    bool delete_tail(T &n);


private:
    struct Node {
        Node(const T &data) : data(data), prev(nullptr), next(nullptr) {

        }

        T data;
        Node *prev;
        Node *next;
    };

    Node *head;
    Node *tail;
    unsigned int size;
    static const unsigned int MAX_SIZE = 1000;
};


template<typename T>
class Stack : public storage<T> {
public:
    virtual ~Stack() = default;

    virtual bool push(T item) = 0; // 压栈
    virtual bool pop(T &n) = 0; // 出栈
    bool add(T n) { push(n); }

    bool remove(T &n) { return pop(n); }
};

template<typename T>
class ArrStack : public Stack<T> {
public:
    void push(T item) override;

    T pop() override;

private:

};


#endif//TASK3_STORAGE_H
