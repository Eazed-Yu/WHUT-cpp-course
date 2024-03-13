// hmk1.cpp是整个程序的⼊⼝⽂件，它包含程序的main()函数
#include "tools.h"
#include <iostream>
#include <string>
extern Date today;
int main() {
    char a = 'a'; // 常规字符
    unsigned char b = 'c'; // 无符号字符
    signed char c = 'c'; // 有符号字符
    wchar_t d = L'd'; // 宽字符
    char16_t e = u'e'; // Unicode字符
    char32_t f = U'e'; // Unicode字符

    short g = 1; // 短整型
    unsigned short h = 2; // 无符号短整型
    int i = 3; // 整型
    unsigned int j = 4; // 无符号整型
    long k = 5L; // 长整型
    unsigned long l = 6UL; // 无符号长整型
    long long m = 7LL; // 长长整型
    unsigned long long n = 8ULL; // 无符号长长整型

    float o = 1.0f; // 单精度浮点数
    double p = 2.0; // 双精度浮点数
    long double q = 3.0L; // 扩展精度浮点数
    int _weekday;
    int _month;
    int _year;
    std::string _name;
    
    std::cout << "请输入年份" << std::endl;
    std::cin >> _year;
    std::cout << "请输入月份" << std::endl;
    std::cin >> _month;
    std::cout << "请输入星期" << std::endl;
    std::cin >> _weekday;
    std::cout << "请输入姓名" << std::endl;
    std::cin >> _name;
    std::cout << "请输入最好的书" << std::endl;
    
    
}