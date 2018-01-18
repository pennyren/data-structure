#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct LNode {
    char num[1000];
    struct LNode *next;
} LNode, *LinkList;

int cmp(char a[], char b[]) {
    int al = strlen(a), bl = strlen(b);
    char *p = a, *q = b;
    if (al != bl) {
        return al > bl;
    } else {
        while (*p) {
            if (*p == *q) {
                p++; q++;
            } else {
                return (*p - '0') > (*q - '0');
            }
        }
        return 0;
    }
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        LinkList L = (LinkList)malloc(sizeof(LNode));
        L->next = NULL;
        LNode *p = L->next, *q = L;

        while (n--) {
            LNode *node = (LNode*)malloc(sizeof(LNode));
            scanf("%s", node->num);
            while (p && cmp(node->num, p->num)) {
                p = p->next;
                q = q->next;
            }
            node->next = p;
            q->next = node;
            p = L->next;
            q = L;
        }

         while (p) {
            printf("%s\n", p->num);
            p = p->next;
        }
    }
    return 0;
}
