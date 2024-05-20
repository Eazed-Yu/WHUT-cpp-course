/*
g++ -o driver.exe list.cpp stack.cpp queue.cpp driver.cpp
*/

#include <iostream>

#include "list.h"
#include "queue.h"
#include "stack.h"


int main() {
  // 使用utf-8
  system("chcp 65001 > nul");
  // 测试 List 类
  std::cout << "测试 List 类:" << std::endl;
  int arr[] = {1, 2, 3, 4, 5};
  List list(arr, 5);
  std::cout << "初始链表: ";
  list.print();

  list.append(6);
  list.prepend(0);
  std::cout << "添加元素后: ";
  list.print();

  int value;
  list.delete_left(value);
  std::cout << "删除头部元素: " << value << std::endl;
  list.print();

  list.delete_right(value);
  std::cout << "删除尾部元素: " << value << std::endl;
  list.print();

  std::cout << "链表长度: " << list.length() << std::endl;

  // 测试 ArrStack 类
  std::cout << "测试 ArrStack 类:" << std::endl;
  ArrStack arrStack;
  arrStack.push(1);
  arrStack.push(2);
  arrStack + 3 + 4 + 5;
  std::cout << "当前栈: " << arrStack << std::endl;

  arrStack.pop(value);
  std::cout << "弹出栈顶元素: " << value << std::endl;
  std::cout << "弹出后栈: " << arrStack << std::endl;

  // 测试 ListStack 类
  std::cout << "测试 ListStack 类:" << std::endl;
  ListStack listStack;
  listStack.push(10);
  listStack.push(20);
  listStack + 30 + 40 + 50;
  std::cout << "当前栈: " << listStack << std::endl;

  listStack.pop(value);
  std::cout << "弹出栈顶元素: " << value << std::endl;
  std::cout << "弹出后栈: " << listStack << std::endl;

  // 测试 ArrQueue 类
  std::cout << "测试 ArrQueue 类:" << std::endl;
  ArrQueue arrQueue;
  arrQueue.enqueue(1);
  arrQueue.enqueue(2);
  arrQueue + 3 + 4 + 5;
  std::cout << "当前队列: " << arrQueue << std::endl;

  arrQueue.dequeue(value);
  std::cout << "出队列元素: " << value << std::endl;
  std::cout << "出队后队列: " << arrQueue << std::endl;

  // 测试 ListQueue 类
  std::cout << "测试 ListQueue 类:" << std::endl;
  ListQueue listQueue;
  listQueue.enqueue(100);
  listQueue.enqueue(200);
  listQueue + 300 + 400 + 500;
  std::cout << "当前队列: " << listQueue << std::endl;

  listQueue.dequeue(value);
  std::cout << "出队列元素: " << value << std::endl;
  std::cout << "出队后队列: " << listQueue << std::endl;
  system("pause");
}