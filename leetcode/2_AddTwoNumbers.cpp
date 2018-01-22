/*
You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order and each of their nodes contain a single digit.
Add the two numbers and return it as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* createNode(struct ListNode *r, int val) {
    struct ListNode *p = (struct ListNode*)malloc(sizeof(struct ListNode));
    p->val = val;
    p->next = r->next;
    return p;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *l = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *r = l;
    int temp = 0;
    l->next = NULL;
    while (l1 && l2) {
        int sum = l1->val + l2->val + temp;
        temp = sum / 10;
        struct ListNode *p = createNode(r, sum % 10);
        r->next = p;
        r = p;
        l1 = l1->next;
        l2 = l2->next;       
    }

    while (l1) {
        int sum = l1->val + temp;
        temp = sum / 10;
        struct ListNode *p = createNode(r, sum % 10);
        r->next = p;
        r = p;
        l1 = l1->next;      
    }

    while (l2) {
        int sum = l2->val + temp;
        temp = sum / 10;
        struct ListNode *p = createNode(r, sum % 10);
        r->next = p;
        r = p;
        l2 = l2->next;      
    }

    if (temp != 0) {
        struct ListNode *p = createNode(r, temp % 10);
        r->next = p;
        r = p;
    }
    return l->next;   
}

struct ListNode* createList(int num) {
    struct ListNode *l = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *r = l;
    l->next = NULL;
    while (num > 0) {
        struct ListNode *p = createNode(r, num % 10);
        r->next = p;
        r = p;
        num = num / 10;
    }
    return l->next;
}

int main() {
    struct ListNode *l, *l1, *l2;
    l1 = createList(342);
    l2 = createList(465);
    l = addTwoNumbers(l1, l2);
    while (l) {
        l->next ? printf("%d -> ", l->val) : printf("%d\n", l->val);
        l = l->next;
    }
    return 0;
}