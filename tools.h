// tools.h是与tools.cpp对应的头⽂件
/* <8> */
// 声明变量
#define TITLE_LEN 80
const int NAME_LEN = 50;

/* <11> */
// 声明一个结构体Book
typedef struct {
    char title[TITLE_LEN];      // 书籍标题
    char authors[NAME_LEN];     // 作者名字
    double price;               // 书籍价格
    union id {
        int library_id;
        char isbn[100];
    } u;
    
} Book;

/* <11> */
// 声明一个枚举类型  Weekday
typedef enum {Mon, Tue, Wed, Thu, Fri, Sat, Sun} Weekday;

/* <12> */
// 声明一个枚举类型  Month
typedef enum {Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec} Month;

/* <13> */
// 声明一个结构体  Date
typedef struct {
    unsigned int year;
    Month month;
    Weekday weekday;
} Date;