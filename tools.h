// tools.h是与tools.cpp对应的头⽂件
/* <8> */
// 声明变量
#include <string>
#define TITLE_LEN 80
const int NAME_LEN = 50;
using namespace std;

/* <11> */
// 声明一个结构体Book
typedef struct
{
    char title[TITLE_LEN];  // 书籍标题
    char authors[NAME_LEN]; // 作者名字
    double price;           // 书籍价格
    union id
    {
        int library_id;
        char isbn[100];
    } u;

} Book;

/* <11> */
// 声明一个枚举类型  Weekday
typedef enum
{
    Mon,
    Tue,
    Wed,
    Thu,
    Fri,
    Sat,
    Sun
} Weekday;

/* <12> */
// 声明一个枚举类型  Month
typedef enum
{
    Jan,
    Feb,
    Mar,
    Apr,
    May,
    Jun,
    Jul,
    Aug,
    Sep,
    Oct,
    Nov,
    Dec
} Month;

/* <13> */
// 声明一个结构体  Date
typedef struct
{
    unsigned int year;
    Month month;
    Weekday weekday;
} Date;

/**
 * @brief 获取名字
 *
 */
void get_my_name();


/**
 * @brief 翻转字符串
 * 
 * @param str 字符串
 */
void reverse_string(char *str);

/* <40> */
/**
 * @brief 
 * 
 * @param a 
 * @param b 
 * @return int
 */
inline int max(int a, int b) {
    return (a > b) ? a : b;
}

int find_max_iterative(int arr[], int n);

/**
 * @brief
 *
 * @param arr
 * @param n
 * @return int
 */
int find_max(int arr[], int n);

/* <43> */
// 定义函数sum_recursive
int sum_recursive(int n);

/* <43> */
// 定义函数sum_while
int sum_while(int n);

/* <45> */
// 定义函数sum_for
int sum_for(int n);

/* <46> */
// 定义函数week_plans
void week_plans(Weekday day);

/* <47> */
// 定义函数hello
int hello();

/* <48> */
// 定义函数grades
void grades(int n);

/* <49> */
// 定义函数nine_roots
void nine_roots(int n);

/* <50> */
// Version 1: 接收两个整型参数，并返回两个参数的和.
int together(int a, int b);

// Version 2: 接收两个C格式的字符串参数 (即字符指针), 并以两个字符串的拼接内容作为返回值.
char* together(char* str1, char* str2);

// Version 3: 接收两个C++格式的字符串参数(即String类型的对象)，并返回一个新的字符串对象，该字符串是两个参数字符串的拼接.
string together(string str1, string str2);