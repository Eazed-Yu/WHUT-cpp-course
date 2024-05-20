#ifndef STACK_H
#define STACK_H

#include <iostream>

#include "list.h"

// Task3: 基于数组实现数据栈（ArrStack）
class ArrStack {
 private:
  static const int ARR_MAX = 1000;  ///< 最大长度
  int arr[ARR_MAX];                 ///< 数组数据
  int size;                         ///< 当前数量
 public:
  ArrStack() : size(0){};
  ~ArrStack(){};

  /**
   * @brief 压栈函数，用于在数据栈的栈顶（即arr(size) 位置）压入参数n
   * 中传递的数据，并更新size
   *
   * @param n
   * @return true 添加成功
   * @return false 容量已满
   */
  bool push(int n);

  /**
   * @brief 出栈函数，用于弹出数据栈顶的元素（即arr(size-1)
   * 位置）并将其值保存到引用参数n 中
   *
   * @param n
   * @return true 出栈成功
   * @return false 栈为空
   */
  bool pop(int &n);

  bool is_full() const { return this->size == ARR_MAX; }

  bool is_empty() const { return this->size == 0; };  // 检查栈是否为空

  int get_size() const { return this->size; };  // 获取栈中的元素数量

  void print() const;  // 打印栈中的所有元素

  ArrStack &operator+(int n);  // 重载+操作符进行压栈

  ArrStack &operator-(int &n);  // 重载-操作符进行出栈

  friend std::ostream &operator<<(std::ostream &os, const ArrStack &stk);

  friend std::ostream &operator<<(std::ostream &os, const ArrStack *stk);
};

// Task4: 基于链表实现数据栈（ListStack）
class ListStack {
 private:
  List lis;            ///< 链表数据
  int LIST_MAX = 100;  ///< 最大数量
 public:
  ListStack() : lis(List()){};
  ~ListStack(){};

  bool push(int n);  // 压栈操作

  bool pop(int &n);  // 出栈操作

  bool is_full() const {
    return this->lis.length() == LIST_MAX;
  }  // 检查栈是否已满

  bool is_empty() const { return this->lis.length() == 0; }  // 检查栈是否为空

  int get_size() const { return this->lis.length(); }  // 获取栈中的元素数量

  void print() const;  // 打印栈中的所有元素

  ListStack &operator+(int n);  // 重载+操作符进行压栈

  ListStack &operator-(int &n);  // 重载-操作符进行出栈

  friend std::ostream &operator<<(std::ostream &os, const ListStack &lstk);

  friend std::ostream &operator<<(std::ostream &os, const ListStack *lstk);
};

#endif