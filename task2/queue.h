// Task5: 基于循环数组实现数据队列（ArrQueue）功能

class ArrQueue
{
private:
    static const int ARR_MAX = 1000; ///< 队列对象的最大容量
    int arr[ARR_MAX]; ///< 各个数据项的整型数组
    int size; ///< 当前数据项的个数
    int front; ///< 最早进入数据队列的数据项的索引位置,当数据队列为空时,该数据成员的值应为-1
    int end; ///< 最后进入数据队列的数据项的索引位置,当数据队列为空时,该数据成员的值应为-1
public:

    // 缺省构造函数
    ArrQueue() : size(0), front(-1), end(-1) {};

    // 析构函数
    ~ArrQueue() {};

    /**
     * @brief 入队函数，用于在数据队列的尾部（即arr(end) 位置）存入参数n 中传递的数据，并更新size 和end 以保持正确的队列状态
     * 
     * @param n 
     * @return true 成功
     * @return false 数据队列的容量已满
     */
    bool enqueue(int n);

    /**
     * @brief 出队函数，用于弹出数据队列的头部（即arr(front) 位置）并将其值保存到引用参数n 中，如操作成功，则更新size 和front 以保持正确的队列状态
     * 
     * @param n 
     * @return true 成功
     * @return false 队列中不包含任何元素
     */
    bool dequeue(int &n);

    bool is_full() const { return size == ARR_MAX; }

    bool is_empty() const { return size == 0; }

    int get_size() const { return size; }

    void print(void) const;

    /**
     * @brief 重载操作符+ ，使用该操作符可对参数n 指定的整数执行入队操作。入队操作后，将当前数据队列作为操作结果返回值，以便支持操作符+ 的链式操作；
     * 
     * @param n 
     * @return ArrQueue& 
     */
    ArrQueue & operator+(int n);

    /**
     * @brief 重载操作符- ，使用该操作符可对数据队列执行出队操作，并将弹出的队首元素存入引用参数n 中。出队操作后，将当前数据队列作为操作结果返回值，以便支持操作符- 的链式操作；
     * 
     * @param n 
     * @return ArrQueue& 
     */
    ArrQueue & operator-(int &n);

    /**
     * @brief 重载操作符<< ，使用该操作符可对数据队列中保存的数据内容进行打印输出，打印时对数据项不执行出队操作
     * 
     * @param os 
     * @param q 
     * @return std::ostream& 
     */
    friend std::ostream & operator<<(std::ostream &os, const ArrQueue &q);

    friend std::ostream & operator<<(std::ostream &os, const ArrQueue *q);
};

