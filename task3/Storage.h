//
// Created by Eazed on 24-6-3.
//

#ifndef TASK3_STORAGE_H
#define TASK3_STORAGE_H


#include <iostream>


template<typename T>
class Storage {
public:
    virtual ~Storage() = default;

    virtual unsigned int getSize() = 0;

    virtual bool isEmpty() = 0;

    virtual bool isFull() = 0;

    virtual bool add(T n) = 0;

    virtual bool remove(T &) = 0;

    virtual bool find(T item) = 0;

    virtual void print() = 0;
};

template<typename T>
class List : public Storage<T> {
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

    unsigned int getSize() { return size; };

    bool isEmpty() { return size == 0; };

    bool isFull() { return size == MAX_SIZE; };

    bool add(T n) { return append(n); };

    bool remove(T &n) { return delete_head(n); };

    void print();

    bool find(T n);

    bool append(T n);

    bool prepend(T n);

    bool delete_head(T &n);

    bool delete_tail(T &n);

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

    unsigned int getSize() { return size; };

    bool isEmpty() { return size == 0; };

    bool isFull() { return size == MAX_SIZE; };

    bool add(T n) { return append(n); };

    bool remove(T &n) { return delete_head(n); };

    void print();

    bool find(T n);

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
class Array : public Storage<T> {
public:
    explicit Array(unsigned int n = 10);

    virtual ~Array();

    unsigned int getSize() { return size; };

    bool isEmpty() { return size == 0; };

    bool isFull() { return size == MAX_SIZE; };

    virtual bool add(T n);

    virtual bool remove(T &n);

    virtual void print();

    virtual bool find(T n);

    virtual const T operator[](int n) const;

    virtual T &operator[](int n);


protected:
    unsigned int size;
    const unsigned int MAX_SIZE;
    T *arr;
};


template<typename T>
class CircleArr : public Array<T> {
public:
    explicit CircleArr(unsigned int s = 0, unsigned int limit = 10);

    ~CircleArr() = default;

    bool add(T n) override;

    bool remove(T &n) override;

    virtual void print();

    virtual bool find(T n);

    CircleArr(const CircleArr<T> &);

    Array<T> &operator=(CircleArr<T> &ref);

private:
    unsigned int start;

    unsigned int mapIndex(unsigned int n) const { return (n + start) % this->MAX_SIZE; }
};




template<typename T>
class Stack : public Storage<T> {
public:
    virtual ~Stack() = default;

    virtual bool push(T item) = 0;

    virtual bool pop(T &n) = 0;
};

template<typename T>
class ArrStack : public Stack<T> {
public:
    explicit ArrStack(unsigned int n = 10);
    ~ArrStack() = default;

    unsigned int getSize() override;

    bool isEmpty() override;

    bool isFull() override;

    bool add(T n) override;

    bool remove(T &t) override;

    bool find(T item) override;

    void print() override;

    bool push(T item) override;

    bool pop(T &n) override;

private:
    unsigned int size;
    const unsigned int MAX_SIZE;
    Array<T> arr;
};




#endif//TASK3_STORAGE_H
