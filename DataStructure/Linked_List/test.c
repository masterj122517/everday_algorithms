#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    struct Node* next;
    int value;
} Node;

typedef struct linkedList
{
    Node* head;
} linkedList;

linkedList* createList()
{
    linkedList* list;
    list = malloc(sizeof(linkedList));
    list->head = NULL;

    return list;
}

void push_front(linkedList* list, int value)
{
    Node* newNode = malloc(sizeof(Node));
    newNode->value = value;
    if (list->head == NULL) {
        list->head = newNode;
    }
    else {
        newNode->next = list->head;
        list->head = newNode;
    }
}
int pop_front(linkedList* list)
{
    if (list->head == NULL) {
        printf("this list is empty");
        return -1;
    }
    else {
        Node* temp = list->head;
        list->head = temp->next;
        int value = temp->value;
        free(temp);
        return value;
    }
}
int is_empty(linkedList* list) { return list->head == NULL; }

void freeList(linkedList* list)
{
    while (!is_empty(list)) {
        pop_front(list);
    }
    free(list);
}

int main()
{
    linkedList* list;
    list = createList();
    push_front(list, 30);
    push_front(list, 20);
    push_front(list, 10);
    printf("pop front %d\n", pop_front(list));
    printf("pop front %d\n", pop_front(list));
    printf("pop front %d\n", pop_front(list));
    freeList(list);
}
