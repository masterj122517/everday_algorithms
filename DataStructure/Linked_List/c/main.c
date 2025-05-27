#include <stdio.h>

#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node* next;
} Node;

typedef struct LinkedList
{
    Node* head;

} LinkedList;

LinkedList* createLinkedList()
{
    LinkedList* list = malloc(sizeof(LinkedList)); // 记住要分配这个List的内存
    list->head = NULL;
    return list;
}
// 在前面添加一个Node
void push_front(LinkedList* list, int val)
{

    Node* new_node = malloc(sizeof(Node)); // 注意，这个Node要分配内存
    new_node->value = val; // 先把值赋了
    new_node->next = list->head; // 把原本的head 变成next
    list->head = new_node; // 把new_node变成新的头
}
void push_backward(LinkedList* list, int val)
{
    Node* new_node = malloc(sizeof(Node));
    new_node->value = val;
    new_node->next = NULL;

    if (list->head == NULL) {
        list->head = new_node;
        return;
    }

    // 否则遍历到最后一个节点
    Node* current = list->head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = new_node;
}

int peak(LinkedList* list)
{
    if (list->head == NULL) {
        printf("The list is empty\n");
        return -1; // 这里一定要返回-1,不然程序会继续往下走
    }
    return list->head->value;
}
int is_empty(LinkedList* list) { return list->head == NULL; }

int pop_front(LinkedList* list)
{
    if (list->head == NULL) {
        printf("the list is empty");
        return -1; // 这里一定要返回-1,不然程序会继续往下走 导致错误 如果是else就没问题
    }
    else {
        Node* temp = list->head;
        int val = temp->value;
        list->head = temp->next;
        free(temp);
        return val;
    }
}

int pop_backward(LinkedList* list)
{
    // list是空的
    if (list->head == NULL) {
        printf("this list is empty");
        return -1; // 又尼玛忘记return -1了，这里一定要返回-1
    }
    // list 只有一个Node
    if (list->head->next == NULL) {
        // ------- 注意不能这样写，return就直接return了，根本不会执行free
        // return list->head->value;
        // free(list->head);

        // return list->head->value; 会立刻结束函数，后面的 free(list->head); 根本不会执行；

        // 所以你就有了内存泄漏：你返回值了，但并没有释放内存。
        // ---------------正确写法

        int val = list->head->value; // val 是stack，在退出函数的时候会自动free
        free(list->head);
        return val;
    }
    // list 有多个Node

    Node* prev = list->head;
    Node* current = list->head->next;
    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }
    int val = current->value;
    free(current);
    prev->next =
        NULL; // 标记为结束了，因为倒数一个没了，倒数第二个就是倒数第一个了 假如说没有变 10 20 30
              // --- 30 已经没了  10 20 --- 10 是head， next 指向20 , 20
              // 指向30，但是三十已经没了，但是20 指向30的地址还是原来的地址，所以free的时候就炸了
              // 释放内存(free) 不会把指针变成 NULL
              // 现在还是原来的地址，但那块内存已经被系统标记为“可回收了”，你不能再用它
              // 如果你再使用 后果是不确定的：可能
              // crash（段错误），也可能只是值变乱，甚至暂时还能用（这很危险！）

    return val; // 记住，return要放在最后，不然先return了就炸了,内存就泄露了
    // free(prev); // 不用free 这个，因为这个是倒数第二个
}

void free_list(LinkedList* list)
{
    while (!is_empty(list)) {
        pop_front(list);
    }
    free(list);
}
int main()
{

    LinkedList* list;
    list = createLinkedList();
    push_front(list, 30);
    push_front(list, 20);
    push_front(list, 10);
    printf("peak: %d\n", peak(list));
    printf("pop front %d\n", pop_front(list));
    printf("pop front %d\n", pop_front(list));
    printf("pop front %d\n", pop_front(list));
    // printf("pop backward %d", pop_backward(list));
    free_list(list);
}
