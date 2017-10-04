#include <stdio.h>
#include "utils.h"

void del(LinkList &L, int el);
void reverse(LinkList &L);
int inverseSearch(LinkList L, int k);
void unique(LinkList &L, int n);
LinkList split(LinkList &L);

LinkList merge(LinkList &La, LinkList &Lb);
void reversePrint(LinkList &L);


int main() {
	LinkList L = createList();

    //1 3 5 -3 4 2 9 3 2 5 6 7 -1
	printf("Origin: ");
	printList(L, listLength(L));

	printf("Delete Element 3: ");
	del(L, 3);
	printList(L, listLength(L));

	printf("Reverse: ");
	reverse(L);
	printList(L, listLength(L));

	printf("Inverse Position 2 element: %d\n", inverseSearch(L, 2));

	printf("Unique: ");
	unique(L, listLength(L));
	printList(L, listLength(L));

	printf("Split:\n");
	LinkList La = split(L);
	printList(La, listLength(La));
	printList(L, listLength(L));

    return 0;
}

//删除链表中元素
void del(LinkList &L, int el) {
	LNode *pre = L, *p = L->next, *q;
	while(p) {
		if (p->data == el) {
			q = p; //暂存删除节点
            p = p->next; //断开节点
			pre->next = p;
			free(q);
		} else {
			pre = p;
			p = p->next;
		}
	}
}

//使用递归，栈
void reversePrint(LinkList &L) {
	if (L->next) {
		reversePrint(L->next);
	}
	printf("%d ", L->data);
}

//直接指针反转
void reverse(LinkList &L) {
    LNode *pre, *p = L->next, *r = p->next;
    p->next = NULL; //处理第一个节点
    while (r) {
        pre = p; //p,r前移
        p = r;
        r = r->next;

        p->next = pre; //指针反转
    }
    L->next = p; //处理最后一个节点
}

//链表逆置，摘取节点再用头插法。
void _reverse(LinkList &L) {
    LNode *p = L->next, *r;
    L->next = NULL;
    while (p) {
        r = p->next; //暂存后继
        p->next = L->next; //头插法
        L->next = p;
        p = r;
    }
}

//查找倒数第k个位置节点，一次遍历。
//初始p,q同时指向第一个节点，p移动第k个位置后，p,q同时往后移，直到p移到最后一个位置，q所指节点即为倒数第k个节点。
int inverseSearch(LinkList L, int k) {
    LNode *p = L->next, *q = p; //同时指向第一个节点。
    int count = 0;
    while (p) {
        if (count < k) {
            count++;
        } else {
            q = q->next;
        }
        p = p->next;
    }

    //范围超出边际,false
    return (count < k) ? false : q->data;
}

//拆分，C={a1,b1,a2,b2,..,an,bn},带头结点hc,拆分为A={a1,a2,...,an},B={bn,..,b2,b1}
//观察有2n个元素，即偶数个。B表采用头插法,A使用尾插法
LinkList split(LinkList &L) {
    LinkList B = (LinkList)malloc(sizeof(LNode)); //初始化B表表头
    B->next = NULL;
    LNode *p = L->next, *q;
    LNode *r = L;

    while (p) {
        r->next = p; //尾插A
        r = p;

        p = p->next;
        q = p->next; //新的开始

        p->next = B->next; //头插B
        B->next = p;
        p = q;
    }
    r->next = NULL; //A尾节点置空
    return B;
}

//两链表A和B，元素都递增排列，将A与B交集存于A中
//归并扫描，只有同时出现在两集合中的元素才链接到结果表中且仅保留一个，其余节点全部释放，当一个表遍历完毕，释放另一个表。
//典型的双指针法
LinkList merge(LinkList &La, LinkList &Lb) {
    LNode *pa = La->next;
    LNode *pb = Lb->next;
    LNode *pc = La, *q; //结果集尾插，保存释放节点
    while (pa && pb) {
        if (pa->data == pb->data) { //交集并入结果集
            pc->next = pa; //并入Lc
            pc = pa;

            pa = pa->next; //节点后移，释放q
            q = pb;
            pb = pb->next;
            free(q);
        } else if (pa->data < pb->data) { //释放节点值小的一个
            q = pa;
            pa = pa->next;
            free(q);
        } else {
            q = pb;
            pb = pb->next;
            free(q);
        }
    }
    while (pa) { //B遍历完，A未完
        q = pa;
        pa = pa->next;
        free(q);
    }
    while (pb) {
        q = pb;
        pb = pb->next;
        free(q);
    }
    pc->next = NULL;
    free(Lb);
    return La;
}



//要求删除列表中元素绝对值相同的节点，只保留第一个
//每个节点绝对值最大值为n
//用空间换取时间，用check[|data|]来对节点计数，初始化为0.
//辅助数组大小为n+1,依次扫描表中节点，同时检测check[|data]的值
//如果为0，则保留该节点，并check[|data|] = 1；否则从表中删除该节点。
void unique(LinkList &L, int n) {
    int *check = (int *)malloc(sizeof(int) * (n + 1));
    for (int i = 0; i < n + 1; i++) {
        check[i] = 0;
    }
    LNode *pre = L, *p = L->next, *q;
    while (p) {
        int el = p->data > 0 ? p->data : -p->data;
        q = p->next;
        if (check[el]) {
            pre->next = q;
            free(p);
        } else {
            pre = p;
            check[el] = 1;
        }
        p = q;
    }
    free(check);
}
