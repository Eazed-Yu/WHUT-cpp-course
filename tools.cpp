// tools.cpp中声明了程序中要⽤到的⼯具类函数
#include "data.cpp" // 包含data.cpp以访问myName变量
#include <string>
#include <cmath>
#include <iomanip>
/* <37> */
#include <iostream> 
#include <cstring>
using namespace std; 
// 定义函数print_my_name
void print_my_name() {
    cout << myName << endl; // 打印myName的值
}

/* <38> */
// 定义函数get_my_name
void get_my_name() {
    cout << "请输入你的名字: ";
    cin >> myName; // 从键盘读取名字并存储在myName变量中
}

/* <39> */
// 定义函数reverse_string
void reverse_string(char* str) {
    int len = strlen(str);
    for(int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

/* <41> */
// 定义函数find_max_iterative
int find_max_iterative(int arr[], int n) {
    int max_val = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] > max_val)
            max_val = arr[i];
    }
    return max_val;
}

/* <42> */
// 定义函数find_max
int find_max(int arr[], int n) {
    if(n == 1)
        return arr[0];
    else
        return max(arr[n-1], find_max(arr, n-1));
}

/* <43> */
// 定义函数sum_recursive
int sum_recursive(int n) {
    if(n == 0)
        return 0;
    else
        return n + sum_recursive(n - 1);
}


/* <43> */
// 定义函数sum_while
int sum_while(int n) {
    int sum = 0;
    while(n >= 0) {
        sum += n;
        n--;
    }
    return sum;
}

/* <45> */
// 定义函数sum_for
int sum_for(int n) {
    int sum = 0;
    for(int i = 0; i <= n; i++) {
        sum += i;
    }
    return sum;
}

/* <46> */
// 定义函数week_plans
void week_plans(Weekday day) {
    switch(day) {
        case Mon:
            cout << "专注学习" << endl;
            break;
        case Tue:
            cout << "处理工作" << endl;
            break;
        case Wed:
            cout << "参加会议" << endl;
            break;
        case Thu:
            cout << "阅读书籍" << endl;
            break;
        case Fri:
            cout << "享受乐趣" << endl;
            break;
        case Sat:
            cout << "进行户外活动" << endl;
            break;
        case Sun:
            cout << "休息和放松" << endl;
            break;
        default:
            cout << "无效的日期" << endl;
            break;
    }
}

/* <47> */
// 定义函数hello
int hello() {
    static int count = 0; // 静态局部变量，用于记录函数被调用的次数
    cout << "hello " << myName << endl;
    count++;
    return count;
}

/* <48> */
// 定义函数grades
void grades(int n) {
    if(n >= 90) {
        cout << "A" << endl;
    } else if(n >= 80) {
        cout << "B" << endl;
    } else if(n >= 70) {
        cout << "C" << endl;
    } else if(n >= 60) {
        cout << "D" << endl;
    } else {
        cout << "F" << endl;
    }
}

/* <49> */
// 定义函数nine_roots
void nine_roots(int n) {
    // 保存cout原来的状态
    std::ios oldState(nullptr);
    oldState.copyfmt(std::cout);

    // 设置cout的输出宽度和精度属性
    std::cout << std::fixed << std::setprecision(3) << std::setw(10);

    // 打印九个数字的平方根
    for(int i = 0; i < 9; i++) {
        std::cout << std::sqrt(n + i);
        if((i + 1) % 3 == 0) {
            std::cout << std::endl;
        } else {
            std::cout << " ";
        }
    }

    // 重置cout的输出格式到函数调用前的状态
    std::cout.copyfmt(oldState);
}

/* <50> */
// Version 1: 接收两个整型参数，并返回两个参数的和.
int together(int a, int b) {
    return a + b;
}

// Version 2: 接收两个C格式的字符串参数 (即字符指针), 并以两个字符串的拼接内容作为返回值.
char* together(char* str1, char* str2) {
    char* result = new char[strlen(str1) + strlen(str2) + 1]; // +1 for the null-terminator
    strcpy(result, str1);
    strcat(result, str2);
    return result;
}

// Version 3: 接收两个C++格式的字符串参数(即String类型的对象)，并返回一个新的字符串对象，该字符串是两个参数字符串的拼接.
string together(string str1, string str2) {
    return str1 + str2;
}