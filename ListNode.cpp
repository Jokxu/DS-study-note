#include<stdio.h>
#include<stdlib.h>
#define eletype int
//单向链表结点的定义
typedef struct ListNode
{
    eletype data;
    struct ListNode* next;
}ListNode;
//单向链表的定义
typedef struct LinkedList
{
    struct ListNode *head;
    size_t size;
}LinkedList;

//单向链表的创建
void LinkedListCreate(LinkedList* list){
    //初始化链表头为 NULL
    list->head = NULL;
    list->size = 0;
}
//单向链表的销毁
void LinkedListDestroy(LinkedList* list){
    //遍历链表，释放每个结点
    while (list->head)
    {
        ListNode* temp = list->head;
        list->head = list->head->next;
        free(temp);
    }
    list->size = 0;
}
//单向链表的元素插入
void LinkedListInsert(LinkedList* list, int i, eletype value){
    if(i < 0 || i > list->size){
        printf("Invalid index\n");
        return;
    }
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->data = value;
    if(i == 0){
        newNode->next = list->head;
        list->head = newNode;
    }else{
        ListNode* current = list->head;
        for(int j = 0; j < i - 1; j ++){
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    list->size++;
}
