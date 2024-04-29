#include "list.h"

// 默认构造函数，初始化空链表
List::List() : head(nullptr), tail(nullptr), len(0) {}

// 从数组构造链表
List::List(int arr[], int num) : head(nullptr), tail(nullptr), len(0) {
    for (int i = 0; i < num; ++i) {
        append(arr[i]);  // 添加每个元素到链表
    }
}

// 析构函数，释放链表中所有节点
List::~List() {
    Node *current = head;
    while (current != nullptr) {
        Node *next = current->next;
        delete current;  // 删除当前节点
        current = next;  // 移动到下一个节点
    }
    head = tail = nullptr;
    len = 0;
}

// 在链表尾部添加一个新节点
void List::append(int n) {
    Node *newNode = new Node{ n, nullptr, nullptr }; // 创建新节点
    if (head == nullptr) { // 如果链表为空
        head = tail = newNode; // 新节点成为头尾节点
    } else {
        tail->next = newNode; // 链接新节点到尾部
        newNode->prev = tail; // 设置新节点的前节点
        tail = newNode; // 更新尾节点
    }
    len++; // 增加链表长度
}

// 在链表头部添加一个新节点
void List::prepend(int n) {
    Node *newNode = new Node{ n, nullptr, nullptr};
    if (head == nullptr) { // 如果链表为空
        head = tail = newNode; // 新节点成为头尾节点
    } else {
        newNode->next = head; // 新节点链接到原头节点
        head->prev = newNode; // 原头节点的前节点指向新节点
        head = newNode; // 更新头节点
    }
    len++; // 增加链表长度
}

// 从链表头部删除节点
bool List::delete_left(int &n) {
    if (head == nullptr) {
        return false; // 链表为空，返回false
    }
    n = head->data;
    Node *next = head->next;
    delete head; // 删除头节点
    head = next; // 更新头节点
    if (head) {
        head->prev = nullptr; // 确保新的头节点的前节点为nullptr
    }
    len--; // 减少链表长度
    return true;
}

// 从链表尾部删除节点
bool List::delete_right(int &n) {
    if (head == nullptr) {
        return false; // 链表为空，返回false
    }
    n = tail->data;
    Node *prev = tail->prev;
    delete tail; // 删除尾节点
    tail = prev; // 更新尾节点
    if (tail) {
        tail->next = nullptr; // 确保新的尾节点的后节点为nullptr
    }
    len--; // 减少链表长度
    return true;
}

// 打印链表内容
void List::print() const{
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

// 重载 << 操作符，用于输出链表到ostream
std::ostream& operator<<(std::ostream &os, const List &lis) {
    Node *current = lis.head;
    os << "[";
    while (current != nullptr) {
        os << current->data;
        if (current->next != nullptr) {
            os << ", ";
        }
        current = current->next;
    }
    os << "]" << std::endl;;
    return os;
}

// 重载 << 操作符，允许对链表指针使用
std::ostream& operator<<(std::ostream &os, const List *lis) {
    return os << *lis; // 直接重用List引用的版本
}

// 查找元素值并返回其在链表中的索引
int List::find(int value) const {
    Node *current = head;
    int index = 0;
    while (current != nullptr) {
        if (current->data == value) {
            return index; // 找到返回索引
        }
        current = current->next;
        index++;
    }
    return -1;  // 未找到返回-1
}

// 从链表中移除指定值的节点
bool List::remove(int value) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == value) {
            if (current == head) {
                head = current->next;
                if (head) {
                    head->prev = nullptr;
                }
            } else if (current == tail) {
                tail = current->prev;
                if (tail) {
                    tail->next = nullptr;
                }
            } else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }
            if (head == nullptr) {
                tail = nullptr;
            }
            delete current; // 删除找到的节点
            len--; // 减少链表长度
            return true;
        }
        current = current->next;
    }
    return false;  // 未找到元素
}

// 清空链表，删除所有节点
void List::clear() {
    Node *current = head;
    while (current != nullptr) {
        Node *next = current->next;
        delete current; // 逐个删除节点
        current = next;
    }
    head = tail = nullptr; // 重置头尾指针
    len = 0; // 链表长度置0
}

// 将链表数据转换为数组
int* List::toArray() const {
    int *arr = new int[len]; // 分配数组空间
    Node *current = head;
    int i = 0;
    while (current != nullptr) {
        arr[i++] = current->data; // 填充数组
        current = current->next;
    }
    return arr; // 返回数组指针
}
