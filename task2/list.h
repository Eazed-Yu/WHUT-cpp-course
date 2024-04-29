#ifndef LIST_H
#define LIST_H

#include <iostream>

/**
 * 使用Node 类描述双向链表的组成节点，该类应包含如下数据成员：
 * data : 用于保存当前节点中的整型数据
 * prev : 指向链表中的前置邻接节点（左节点）的指针，如果当前节点没有前置邻接节点，则该数据成员应为空值；
 * next : 指向链表中的后置邻接节点（右节点）的指针，如果当前节点没有后置邻接节点，则该数据成员应为空值；
 */
struct Node {
    int data;
    Node *prev;
    Node *next;
};


// Task2: 实现双向链表（doubly-linked list）
class List {
private:
    Node *head; ///< 指向链表头部的指针
    Node *tail; ///< 指向链表尾部的指针
    int len;    ///< 链表中的节点数量

public:
    /**
     * @brief 默认构造函数，初始化一个空的链表
     */
    List();

    /**
     * @brief 构造函数，通过整型数组初始化链表
     * 
     * @param arr 指向整型数组的指针
     * @param num 数组中元素的数量
     */
    List(int arr[], int num);

    /**
     * @brief 析构函数，负责释放链表中所有节点的内存
     */
    ~List();

    Node *getHead() { return this->head; }
    Node *getTail() { return this->tail; }

    /**
     * @brief 向链表后方添加一个节点
     * 
     * @param n 节点的数据
     */
    void append(int n);

    /**
     * @brief 向链表前方添加一个节点
     * 
     * @param n 节点的数据
     */
    void prepend(int n);

    /**
     * @brief 用于从双向链表上删除其头节点（最左节点），并将该节点中的数据保存到参数n
     * 
     * @param n 保存到参数n
     * @return true 操作成功
     * @return false 链表为空
     */
    bool delete_left(int &n);

    /**
     * @brief 用于从双向链表上删除其尾节点（最右节点），并将该节点中的数据保存到参数n
     * 
     * @param n 保存到参数n
     * @return true 操作成功
     * @return false 链表为空
     */
    bool delete_right(int &n);
    // 获取链表长度
    int length() const { return this->len; }
    // 打印链表
    void print() const;
    // 重载"<<"运算符
    friend std::ostream& operator<<(std::ostream &os, const List &lis);
    // 重载"<<"运算符
    friend std::ostream& operator<<(std::ostream &os, const List *lis);

    /**
     * @brief 在链表中搜索指定的整型元素值，并返回其节点序号
     * 
     * @param value 需要查找的值
     * @return int 返回索引 未找到返回 "-1"
     */
    int find(int value) const;

    /**
     * @brief 从链表中删除指定的整型元素值
     * 
     * @param value 需要删除的值
     * @return true 成功删除
     * @return false 找不到该值
     */
    bool remove(int value);

    /**
     * @brief 从链表中删除所有节点
     * 
     */
    void clear();

    /**
     * @brief 基于链表中的所有节点创建一个数组
     * 
     * @return int* 返回的数组
     */
    int* toArray() const;

};

#endif