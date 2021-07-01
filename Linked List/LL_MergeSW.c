#include <stdio.h>
#include <stdlib.h>

// Merge Sort
typedef struct node {
    int data;
    struct node* next;
}ListNode;

// 1 3 7 8 list 1
// 2 5 6 9 list 2

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* head = (ListNode*)malloc(sizeof(ListNode)); // 병합하여 새로 만들 노드의 head 생성
    ListNode* pt = head;

    l1 = l1->next;
    l2 = l2->next;

    while (l1 != NULL && l2 != NULL) { // 두 개의 다른 노드 값을 비교해서 sort 하는 과정
        if (l1->data <= l2->data) { 
            pt->next = l1;
            l1 = l1->next;
        }
        else {
            pt->next = l2;
            l2 = l2->next;
        }
        pt = pt->next;
    }
    if (l1 != NULL)
        pt->next = l1; 
    if (l2 != NULL)
        pt->next = l2;
    return head;
}

void append(ListNode* l, int data) {
    ListNode* item = (ListNode*)malloc(sizeof(ListNode));
    item->data = data;
    item->next = NULL;

    ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
    temp = l;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = item;
}

void printList(ListNode* l) {
    while (l->next != NULL) {
        printf("%d ", l->next->data);
        l = l->next;
    }
    printf("\n");
}

int main() {
    ListNode* listA = (ListNode*)malloc(sizeof(ListNode));
    ListNode* listB = (ListNode*)malloc(sizeof(ListNode));
    listA->next = NULL;
    listB->next = NULL;

    append(listA, 2);
    append(listA, 6);
    append(listA, 9);
    append(listA, 10);
    printList(listA);

    append(listB, 1);
    append(listB, 5);
    append(listB, 7);
    append(listB, 8);
    append(listB, 11);
    printList(listB);

    ListNode* result = mergeTwoLists(listA, listB);
    printList(result);
}



