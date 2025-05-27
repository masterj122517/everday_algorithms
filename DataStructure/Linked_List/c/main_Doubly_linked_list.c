#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct linkedList
{
    Node* head;
} linkedList;

linkedList* createList()
{
    linkedList* list = malloc(sizeof(linkedList));
    list->head = NULL;
    return list;
}

void push_front(linkedList* list, int value)
{
    Node* newNode = malloc(sizeof(Node));
    newNode->value = value;
    newNode->prev = NULL;
    newNode->next = list->head;
    if (list->head)
        list->head->prev = newNode;
    list->head = newNode;
}

void push_back(linkedList* list, int value)
{
    Node* newNode = malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    if (list->head == NULL) {
        newNode->prev = NULL;
        list->head = newNode;
        return;
    }
    Node* curr = list->head;
    while (curr->next)
        curr = curr->next;
    curr->next = newNode;
    newNode->prev = curr;
}

void delete_value(linkedList* list, int value)
{
    Node* curr = list->head;
    while (curr && curr->value != value)
        curr = curr->next;
    if (!curr)
        return;
    if (curr->prev)
        curr->prev->next = curr->next;
    else
        list->head = curr->next;
    if (curr->next)
        curr->next->prev = curr->prev;
    free(curr);
}

void print_forward(linkedList* list)
{
    Node* curr = list->head;
    printf("Forward: ");
    while (curr) {
        printf("%d ", curr->value);
        curr = curr->next;
    }
    printf("\n");
}

void print_backward(linkedList* list)
{
    Node* curr = list->head;
    if (!curr)
        return;
    while (curr->next)
        curr = curr->next;
    printf("Backward: ");
    while (curr) {
        printf("%d ", curr->value);
        curr = curr->prev;
    }
    printf("\n");
}

void free_list(linkedList* list)
{
    Node* curr = list->head;
    while (curr) {
        Node* temp = curr;
        curr = curr->next;
        free(temp);
    }
    free(list);
}

int main()
{
    linkedList* list = createList();

    push_front(list, 10);
    push_front(list, 20);
    push_back(list, 30);
    push_back(list, 40);

    print_forward(list); // Forward: 20 10 30 40
    print_backward(list); // Backward: 40 30 10 20

    delete_value(list, 10);
    print_forward(list); // Forward: 20 30 40

    free_list(list);
    return 0;
}
