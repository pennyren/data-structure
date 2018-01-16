#include <stdio.h>
#include <stdlib.h>

typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *LinkList;

int main() {
    int n, num;
    while (scanf("%d", &n) != EOF) {
        LinkList L = (LinkList)malloc(sizeof(LNode));
        L->next = NULL;
        LNode *p = L->next, *q = L;
        for (int i = 0; i < n; i++) {
            scanf("%d", &num);
            LNode *node = (LNode*)malloc(sizeof(LNode));
            node->data = num;
            while (p && num > p->data) {
                p = p->next;
                q = q->next;
            }

            node->next = p;
            q->next = node;
            p = L->next;
            q = L;
        }
        while (p) {
            p->next == NULL ?  printf("%d\n", p->data) :  printf("%d ", p->data);
            p = p->next;
        }
    }
    return 0;
}
