/*
g++ -o driver.exe list.cpp stack.cpp queue.cpp driver.cpp
*/

#include <iostream>
#include "list.h"
#include "stack.h"
#include "queue.h"

using namespace std;

int main() {
    // 使用utf-8
    system("chcp 65001 > nul");
    // 测试 List 类
    List list; // 默认构造函数
    cout << "当前链表长度: " << list.length() << endl; // 输出链表长度
    list.append(10); // 在链表尾部添加 10
    list.prepend(20); // 在链表头部添加 20
    list.append(30); // 在链表尾部添加 30
    cout << "链表内容: " << list << endl; // 打印链表内容
    int x;
    list.delete_left(x); // 删除链表头部元素
    cout << "删除头部元素: " << x << " 链表内容: " << list << endl;
    list.delete_right(x); // 删除链表尾部元素
    cout << "删除尾部元素: " << x << " 链表内容: " << list << endl;

    // 测试 ArrStack
    ArrStack as; // 默认构造函数
    cout << "当前数组栈大小: " << as.get_size() << endl; // 输出栈大小
    as.push(1); // 压入 1
    as + 3; // 压入 3
    cout << "当前数组栈大小: " << as.get_size() << endl; // 输出栈大小
    int y, z;
    as.pop(x); // 弹出栈顶元素
    as.pop(y); // 弹出栈顶元素
    cout << "x = " << x << " y = " << y << endl;
    as + 99 + 100 + 101 - z; // 测试重载的 + 和 -
    cout << as << endl; // 测试重载的 <<

    // 测试 ListStack
    ListStack ls; // 默认构造函数
    cout << "当前链表栈大小: " << ls.get_size() << endl; // 输出栈大小
    ls.push(2); // 压入 2
    ls + 4; // 压入 4
    cout << "当前链表栈大小: " << ls.get_size() << endl; // 输出栈大小
    ls.pop(x); // 弹出栈顶元素
    ls.pop(y); // 弹出栈顶元素
    cout << "x = " << x << " y = " << y << endl;
    ls + 101 + 102 + 103 - z; // 测试重载的 + 和 -
    cout << ls << endl; // 测试重载的 <<

    // 测试 ArrQueue
    ArrQueue aq; // 默认构造函数
    cout << "当前数组队列大小: " << aq.get_size() << endl; // 输出队列大小
    aq.enqueue(10); // 入队 10
    aq + 20 + 30; // 入队 20 和 30
    cout << "当前数组队列大小: " << aq.get_size() << endl; // 输出队列大小
    aq.dequeue(x); // 出队
    aq.dequeue(y); // 出队
    cout << "x = " << x << " y = " << y << endl;
    aq + 40 + 50 - z; // 测试重载的 + 和 -
    cout << aq << endl; // 测试重载的 <<

    // 测试 ListQueue
    ListQueue lq; // 默认构造函数
    cout << "当前链表队列大小: " << lq.get_size() << endl; // 输出队列大小
    lq.enqueue(100); // 入队 100
    lq + 200 + 300; // 入队 200 和 300
    cout << "当前链表队列大小: " << lq.get_size() << endl; // 输出队列大小
    lq.dequeue(x); // 出队
    lq.dequeue(y); // 出队
    cout << "x = " << x << " y = " << y << endl;
    lq + 400 + 500 - z; // 测试重载的 + 和 -
    cout << lq << endl; // 测试重载的 <<
    system("pause");
}