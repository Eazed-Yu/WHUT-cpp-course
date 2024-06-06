//
// Created by Eazed on 24-6-3.
//

#ifndef TASK3_STORAGE_H
#define TASK3_STORAGE_H


#include <iostream>


template <typename T>
class Storage {
public:
    virtual ~Storage() = default;
    Storage(unsigned int size = 0) {
        this->size = size;
    }

    unsigned int getSize() { return size; }
    bool isEmpt() const {return size == 0; }
    bool isFull() const { return size == MAX_SIZE; }

    virtual bool add(T n);
    virtual bool remove(T &);
    virtual bool find(T item) = 0; // 查找元素
    virtual void print() = 0; // 打印元素
protected:
    unsigned int size;   // 容器大小
    static const unsigned int MAX_SIZE = 1000;
};

template <typename T>
class Stack : public Storage<T> {
public:
    virtual ~Stack() = default;
    virtual bool push(T item) = 0; // 压栈
    virtual bool pop(T &n) = 0; // 出栈
    bool add(T n) { push(); }
    bool remove(T &n) { return pop(n); }
};

template <typename T>
class ArrStack : public Stack<T> {
public:
    void push(T item) override;
    T pop() override;
private:

};

template <typename T>
class List : public Storage<T> {
    virtual ~List() = default;

    virtual bool append(T n) = 0;

    virtual bool prepend(T n) = 0;

    virtual bool delete_head(T &n) = 0;

    virtual bool delete_tail(T &n) = 0;
};

template <typename T>
class SingleList : public List<T> {
public:
    SingleList();
    ~SingleList();

    bool append(T n) override;
    bool prepend(T n) override;
    bool delete_head(T &n) override;
    bool delete_tail(T &n) override;
    bool add(T) override;
    bool remove(T &) override;
    void print() override;
    bool find(T n) override;
private:
    struct Node
    {
        Node(const T& data)  : data(data), next(nullptr) {

        }
        T data;
        Node *next;
    };

    Node *head;
    Node *tail;
};

#endif//TASK3_STORAGE_H
