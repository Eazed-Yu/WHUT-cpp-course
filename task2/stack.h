#ifndef STACK_H
#define STACK_H

#include <iostream>
class ArrStack
{
private:
    static const int ARR_MAX = 1000; ///< 最大长度
    int arr[ARR_MAX]; ///< 数组数据
    int size; ///< 当前数量
public:
    ArrStack() : size(0) {};
    ~ArrStack() {};

    bool push(int n);                // 压栈操作
    bool pop(int &n);                // 出栈操作
    bool is_full() const;            // 检查栈是否已满
    bool is_empty() const;           // 检查栈是否为空
    int get_size() const;            // 获取栈中的元素数量
    void print() const;              // 打印栈中的所有元素
    ArrStack& operator+(int n);      // 重载+操作符进行压栈
    ArrStack& operator-(int &n);     // 重载-操作符进行出栈
    friend std::ostream& operator<<(std::ostream &os, const ArrStack &stk);
    friend std::ostream& operator<<(std::ostream &os, const ArrStack *stk);
};

#endif