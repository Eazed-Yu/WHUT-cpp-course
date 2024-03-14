// tools.h是与tools.cpp对应的头⽂件
#define TITLE_LEN 80
const int NAME_LEN = 50;

typedef struct {
    char title[TITLE_LEN];      // 书籍标题
    char authors[NAME_LEN];     // 作者名字
    double price;               // 书籍价格
    union id {
        int library_id;
        char isbn[100];
    } u;
    
} Book;

typedef enum {Mon, Tue, Wed, Thu, Fri, Sat, Sun} Weekday;

typedef enum {Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec} Month;

typedef struct {
    unsigned int year;
    Month month;
    Weekday weekday;
} Date;