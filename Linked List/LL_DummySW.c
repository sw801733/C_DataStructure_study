#include <stdio.h>
#include <stdlib.h>




// ��� ������
typedef struct node {
    char data[3];
    struct node* next;
} node;

// ���� ����Ʈ ��Ÿ������
// head�� tail ,size�� ����ؼ� �����Ͽ� ��������� ���Ḯ��Ʈ�� ������ ���ϰ� �Ѵ�.
// tail�̶�� ������带 ���� ������ ��带 �Ź� �����Ͽ� ������ ��带 ����� �� �����ϴ�.
typedef struct LinkedList {
    node* head; // �Ӹ� ���
    node* tail; // ���� ���
    int size; // ���Ḯ��Ʈ ũ��
} LinkedList;


/* ���� ��带 ������� ���� ��.
* LinkedList* new(){
    LinkedList * lk = (LinkedList*)malloc(sizeof(LinkedList));
    lk->head = NULL;
    lk->tail = NULL;
    lk->size = 0;
    puts("-------------------------------------------------------");
    printf("%40s\n", "Linked List Initiated.");
    puts("-------------------------------------------------------");
    return lk;
}
*/

// ���̳�带 ���� ���ο� ���Ḯ��Ʈ�� ������ ��
LinkedList* new(){
    LinkedList * lk = (LinkedList*)malloc(sizeof(LinkedList));
    lk->head = lk->tail = (node*)malloc(sizeof(node)); // ���� ��� ����
    lk->head->next = NULL; // ���� ��尡 NULL�� ����Ű���� �ʱ�ȭ
    lk->size = 0;
    puts("-------------------------------------------------------");
    printf("%40s\n", "Linked List Initiated.");
    puts("-------------------------------------------------------");
    return lk;
}

/* ���� ��带 ������� ���� ��.
* void add(LinkedList* lk, char data[]) {
    node* tmp = (node*)malloc(sizeof(node));
    strcpy(tmp->data, data);
    tmp->next = NULL;

    if (lk->head == NULL)
        lk->head = tmp;
    else
        lk->tail->next = tmp;
    lk->tail = tmp;
    ++lk->size;
}
*/

// add �Լ��� dummy Node�� ����ϱ� ������ �׻� head�� ����־
// head == NULL�̶�� ������ ���� �ʿ䰡 ����.
void add(LinkedList* lk, char data[]) {
    node* tmp = (node*)malloc(sizeof(node));
    strcpy(tmp->data, data);
    tmp->next = NULL;

    lk->tail->next = tmp;
    lk->tail = tmp;
    ++lk->size;
}

/* ���̳�带 ������� ���� ��.
*
* void insert(LinkedList* lk, int n, char data[]) {
    if (n == size(lk) + 1) // �� ���� �����Ѵٸ� �׳� add()�� ȣ���Ѵ�
        add(lk, data);
    else if (n < 1 || n > size(lk) + 1) // ����Ʈ ���� ���̶��
        printf("�ش� ��ġ(%d)�� ��带 ������ �� �����ϴ�.\n", n);
    else { // �� ���� �ƴ� ����Ʈ ���� ���� �ٸ� ���̶��
        node* tmp = (node*)malloc(sizeof(node));
        strcpy(tmp->data, data);

        if (n == 1) { // �׷��� ���� �� ���̶��
            tmp->next = lk->head; // head �����Ͱ� ����Ű�� �� ó�� ��带 tmp ������ ����
            lk->head = tmp; // head �����Ͱ� tmp�� ����Ű���� ����
        }
        else { // �� �յ� �ƴ϶��
            node* cur = lk->head;
            while (--n - 1) // �ݺ������� ���� ��ġ ���� ��忡 ����
                cur = cur->next;

            tmp->next = cur->next; // tmp�� ������ cur�� ���� ��带 ����
            cur->next = tmp; // cur�� ���� ��带 tmp�� ����
        }
        ++lk->size;
    }
}
*/

// ���̳�带 ����� �� insert�� �ѹ��� ó���ϴ� �Լ��� 
// head�� �׻� NULL�� ����Ű�� ������ head�� ���� ������ �ʿ䰡 ��� ������ �ܼ�������.
void insert(LinkedList* lk, int n, char data[]) {
    if (n == size(lk) + 1) // �� ���� �����Ѵٸ� �׳� add()�� ȣ���Ѵ�
        add(lk, data);
    else if (n < 1 || n > size(lk) + 1) // ����Ʈ ���� ���̶��
        printf("�ش� ��ġ(%d)�� ��带 ������ �� �����ϴ�.\n", n);
    else { // �� ���� �ƴ� ����Ʈ ���� ���� �ٸ� ���̶��
        node* tmp = (node*)malloc(sizeof(node));
        strcpy(tmp->data, data);

        node* cur = lk->head;
        while (--n) // �ݺ������� ���� ��ġ ���� ��忡 ����
            cur = cur->next;

        tmp->next = cur->next; // tmp�� ������ cur�� ���� ��带 ����
        cur->next = tmp; // cur�� ���� ��带 tmp�� ����
        ++lk->size;
    }
}


/* ���̳�带 ������� ���� ��
* void delete(LinkedList* lk, int n) {
    if (n < 1 || n > size(lk)) // ����Ʈ ���� ���̶��
        printf("�ش� ��ġ(%d)�� ��带 ������ �� �����ϴ�.\n", n);
    else { // ����Ʈ ���� ���̶��
        node* tmp;
        if (n == 1) { // �� �� ��带 �����ҰŶ��
            tmp = lk->head; // �� �� ��� �ּҸ� tmp�� ����
            lk->head = lk->head->next; // head �����Ͱ� �� �� ��� ������ ����Ű���� ����
            if (n == size(lk)) lk->tail = NULL; // ������ ���� ���� tail �����͸� NULL�� ����
        }
        else { // �� ���� �ƴ϶��
            node* cur = lk->head; // cur�� �� ó�� ���� �������
            int i = n;
            while (--i - 1) // ������ ��� �������� ã�ư���
                cur = cur->next;

            tmp = cur->next; // ������ ���� cur ������ ����̹Ƿ� �̸� tmp�� ����
            cur->next = cur->next->next; // cur�� next �����Ϳ� cur�� ���� ���� ��带 ����
            if (n == size(lk)) lk->tail = cur; // ���� ��� �����̸� tail �����͸� �����Ѵ�
        }
        free(tmp); // �����Ϸ��� ���� �޸𸮸� ������Ų��
        --lk->size;
    }
}

*/


void delete(LinkedList* lk, int n) {
    if (n < 1 || n > size(lk)) // ����Ʈ ���� ���̶��
        printf("�ش� ��ġ(%d)�� ��带 ������ �� �����ϴ�.\n", n);
    else { // ����Ʈ ���� ���̶��
        node* tmp;
        node* cur = lk->head; // cur�� �� ó�� ���� �������
        int i = n;
        while (--i) // ������ ��� �������� ã�ư���
            cur = cur->next;

        tmp = cur->next; // ������ ���� cur ������ ����̹Ƿ� �̸� tmp�� ����
        cur->next = cur->next->next; // cur�� next �����Ϳ� cur�� ���� ���� ��带 ����
        if (n == size(lk)) lk->tail = cur; // �� �� ��� �����̸� tail �����͸� �����Ѵ�

        free(tmp); // �����Ϸ��� ���� �޸𸮸� ������Ų��
        --lk->size;
    }
}

void print(LinkedList* lk) {
    node* cur = lk->head->next;
    printf("����Ʈ ����: ");
    if (cur != NULL) { // ������ ��� �����Ͱ� NULL�� ����Ű�� �ʴ´ٸ�
        for (;;) {
            printf("%s", cur->data);
            if (cur->next == NULL) { // ������ �����
                printf("\n"); // ���� ���
                break;
            }
            else printf(" -> "); // ������ ��尡 �ƴ϶�� ȭ��ǥ ���
            cur = cur->next;
        }
    }
    else puts("NO DATA"); // ������ ��� �����Ͱ� NULL�� ����Ų�ٸ�
}
