
// 宏展开的意思就是在预处理阶段把值换掉

#include <stdio.h>
#define MAX(a, b) ((a > b) ? (a) : (b)) // 这个是纯纯文本替换，不会创建变量什么的

#define LOG(x)            \
    do {                  \
        printf("LOG: ");  \
        printf("%d ", x); \
        printf("\n");     \
    } while (0)

#define DEBUG

#ifdef DEBUG
#undef DEBUG
#define DBG_PRINT(x) printf("DEBUG: %s\n", x)
#else
#define DBG_PRINT(x)
#endif

#define VAR(name) my_##name

#define TO_STRING(x) #x // # 是把传进来的参数变成字符串

// #define TO_STRING(x) #x
// 这一行是宏双层嵌套，如果没有这一层，那就回返回是"VAL"而不是"123"
// #define EXPAND_AND_STRINGIFY(x) TO_STRING(x)

// #define VAL 123

// EXPAND_AND_STRINGIFY(VAL) // 结果是 "123"
// 变参宏
#define PRINT(fmt, ...) \  
    printf(fmt, __VA_ARGS__) // __VA_ARGS__ 是一个预处理器保留名字，代表传给宏的「可变参数列表」。✅
                             // __VA_ARGS__ 代表什么？
                             // 它就代表你在使用宏时，“...”部分传进来的所有参数。

int main()
{
    DBG_PRINT("Loading....");
    int VAR(hello) = 10; // == int my_hello = 10;
    const char* name = TO_STRING(hello);
    printf("%s", name);
    PRINT("hello%s", TO_STRING(hello));
}
