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
public:
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
    unsigned int MAX_SIZE;
    T *arr;
};

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
    for (unsigned int i = 0; i < size; i++) {
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
    unsigned int MAX_SIZE;
    Array<T> arr;
};
template<typename T>
ArrStack<T>::ArrStack(unsigned int n) : MAX_SIZE(n), arr(Array<T>(n)){
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
    for (unsigned int i = 0; i < size; ++i) {
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
class ListStack : public Stack<T> {
public:
    ListStack();

    ~ListStack() override = default;

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
    DoubleList<T> lis;
    unsigned int size;
    static const unsigned int MAX_SIZE = 1000;
};

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


template<typename T>
class Queue : public Storage<T> {
public:
    virtual bool enqueue(T) = 0;
    virtual bool dequeue(T&) = 0;
};

template<typename T>
class ArrQ : public Queue<T> {
public:
    explicit ArrQ(unsigned int s = 0, unsigned int limit = 10);

    ~ArrQ() override = default;

    unsigned int getSize() override;

    bool isEmpty() override;

    bool isFull() override;

    bool add(T n) override;

    bool remove(T &t) override;

    bool find(T item) override;

    void print() override;

    bool enqueue(T t) override;

    bool dequeue(T &t) override;

private:
    unsigned int front;
    unsigned int end;
    CircleArr<T> arr;

};

template<typename T>
ArrQ<T>::ArrQ(unsigned int s, unsigned int limit) : arr(CircleArr<T>(s, limit)), front(0), end(0) {

}

template<typename T>
unsigned int ArrQ<T>::getSize() {
    return arr.getSize();
}

template<typename T>
bool ArrQ<T>::isEmpty() {
    return arr.isEmpty();
}

template<typename T>
bool ArrQ<T>::isFull() {
    return arr.isFull();
}

template<typename T>
bool ArrQ<T>::add(T n) {
    return arr.add(n);
}

template<typename T>
bool ArrQ<T>::remove(T &t) {
    return arr.remove(t);
}

template<typename T>
bool ArrQ<T>::find(T item) {
    return arr.find(item);
}

template<typename T>
void ArrQ<T>::print() {
    arr.print();
}

template<typename T>
bool ArrQ<T>::enqueue(T t) {
    return arr.add(t);
}

template<typename T>
bool ArrQ<T>::dequeue(T &t) {
    return arr.remove(t);
}


#endif//TASK3_STORAGE_H
