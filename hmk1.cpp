// g++ hmk1.cpp data.cpp tools.cpp -o main
// hmk1.cpp是整个程序的⼊⼝⽂件，它包含程序的main()函数
#include "tools.h"
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
Date today;
extern char myName[NAME_LEN];
extern Book bestBook;

int main() {
    system("chcp 65001 > nul");
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
    int _bookPrice;
    int _bookId;
    string _name;
    string _bookTitle;
    string _bookAuthors;
    cout << "请输入年份" << endl;
    cin >> _year;
    cout << "请输入月份" << endl;
    cin >> _month;
    cout << "请输入星期" << endl;
    cin >> _weekday;
    cout << "请输入你的姓名" << endl;
    cin >> _name;
    cout << "请输入最好的书的标题" << endl;
    cin >> _bookTitle;
    cout << "请输入最好的书的作者" << endl;
    cin >> _bookAuthors;
    cout << "请输入最好的书的价格" << endl;
    cin >> _bookPrice;
    cout << "请输入最好的书的id" << endl;
    cin >> _bookId;
    today.year = _year;
    today.month = static_cast<Month>(_month);
    today.weekday = static_cast<Weekday>(_weekday);
    strcpy(myName, _name.c_str());
    strcpy(bestBook.title, _bookTitle.c_str());
    strcpy(bestBook.authors, _bookAuthors.c_str());
    bestBook.price = _bookPrice;
    bestBook.u.library_id = _bookId;

    // Print all the input information
    cout << "年份: " << _year << endl;
    cout << "月份: " << _month << endl;
    cout << "星期: " << _weekday << endl;
    cout << "姓名: " << _name << endl;
    cout << "最好的书的标题: " << _bookTitle << endl;
    cout << "最好的书的作者: " << _bookAuthors << endl;
    cout << "最好的书的价格: " << _bookPrice << endl;
    cout << "最好的书的id: " << _bookId << endl;
    system("pause");
}