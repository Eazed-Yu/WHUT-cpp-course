// g++ hmk1.cpp data.cpp tools.cpp -o main
// hmk1.cpp是整个程序的⼊⼝⽂件，它包含程序的main()函数
#include "tools.h"
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;
Date today;
extern char myName[NAME_LEN];
extern Book bestBook;

int main() {
    // 控制台使用UTF-8编码
    system("chcp 65001 > nul");
    /* <9><10> */
    // 为上一步中声明的每一个变量进行初始化赋值
    // 按照下列要求声明若干局部变量 
    // 为每一种char类型声明一个变量
    char a = 'a'; // 常规字符
    unsigned char b = 'c'; // 无符号字符
    signed char c = 'c'; // 有符号字符
    wchar_t d = L'd'; // 宽字符
    char16_t e = u'e'; // Unicode字符
    char32_t f = U'e'; // Unicode字符
    
    // 为每一种整数类型声明一个变量
    short g = 1; // 短整型
    unsigned short h = 2; // 无符号短整型
    int i = 3; // 整型
    unsigned int j = 4; // 无符号整型
    long k = 5L; // 长整型
    unsigned long l = 6UL; // 无符号长整型
    long long m = 7LL; // 长长整型
    unsigned long long n = 8ULL; // 无符号长长整型
    
    // 为每一种浮点类型声明一个变量
    float o = 1.0f; // 单精度浮点数
    double p = 2.0; // 双精度浮点数
    long double q = 3.0L; // 扩展精度浮点数
    
    /* <18> */
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

    cout << "年份: " << _year << endl;
    cout << "月份: " << _month << endl;
    cout << "星期: " << _weekday << endl;
    cout << "姓名: " << _name << endl;
    cout << "最好的书的标题: " << _bookTitle << endl;
    cout << "最好的书的作者: " << _bookAuthors << endl;
    cout << "最好的书的价格: " << _bookPrice << endl;
    cout << "最好的书的id: " << _bookId << endl;
    system("pause");
    
    /* <19> */
    int x;
    const int* xp;
    const int* xp2 = new int[5];
    int* ar1[5];
    
    size_t (*fp1)(const char*) = strlen;
    auto fp2 = strncpy;
    
    /* <26> */
    cout << a << b << c << d << e << f << f << endl;
    
    /* <27> */
    cout << INT_MAX << endl << LONG_LONG_MIN << endl;
    
    /* <28> */
    int number {42};
    
    /* <29> */
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    cout << d << endl;
    cout << e << endl;
    cout << f << endl;
    cout << g << endl;
    cout << h << endl;
    cout << i << endl;
    cout << j << endl;
    cout << k << endl;
    cout << l << endl;
    cout << m << endl;
    cout << o << endl;
    cout << p << endl;
    cout << q << endl;
    
    /* <30> */
    // 打印十进制
    cout << "十进制: " << number << endl;
    // 打印八进制
    cout << "八进制: " << oct << number << endl;
    // 打印十六进制
    cout << "十六进制: " << hex << number << endl;
    
    /* <31> */
    char ch = 'A';
    // 打印字符
    std::cout << "字符: " << ch << std::endl;
    // 打印对应的整型值
    std::cout << "整型值: " << static_cast<int>(ch) << std::endl;
    
    /* <32> */
    cout << sizeof (ar1) << endl;
    
    /* <33> */
    cout << "请输入字符" << endl;
    char str1[100];
    cin >> str1;
    
    /* <35> */
    cout << "请输入字符" << endl;
    string str2;
    cin >> str2;
    
    char ch2;
    ch2 = getchar();
    
    /* <36> */
    // 打开文件info.txt，并写入myName变量的内容
    ofstream outFile("info.txt");
    if (outFile.is_open()) {
        outFile << myName << endl;
        outFile.close(); // 关闭文件
    } else {
        cout << "无法打开文件info.txt进行写入" << endl;
    }

    // 打开文件info.txt，并读取内容，然后打印到屏幕上
    ifstream inFile("info.txt");
    string line;
    if (inFile.is_open()) {
        while (getline(inFile, line)) {
            cout << "你的名字是：" << line << endl;
        }
        inFile.close(); // 关闭文件
    } else {
        cout << "无法打开文件info.txt进行读取" << endl;
    }
    system("pause");
    
    /* <37> */
    
}