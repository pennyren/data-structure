## 线性表

一个线性表是n个数据元素的有限序列。复杂的线性表中，一个数据元素可以由若干个数据项(item)组成，此时常称数据元素为记录(record)，含大量记录的线性表又称文件(file)。线性表中相邻数据元素之间存在序偶关系(有序,成对,`<a,b> <b, a>不同`)。线性表可记为:

$$(a_1, ..., a_{i-1}, a_i, a_{i+1}, ..., a_n)$$

称$a_{i-1}$是$a_i$的直接前驱元素，$a_{i+1}$是$a_i$的直接后继元素。线性表中元素的个数n定义为线性表的长度，`n = 0`称为空表。称`i`为数据元素$a_i$的`位序`(注意：`i >= 1`)。

**ADT线性表定义**

```c
ADT List {
	initList(&L); //构造空的线性表L
	destroyList(&L); //销毁线性表L
	clearList(&L); //将L重置为空表
	listIsEmpty(L); //若L为空表返回TRUE，否则为FALSE
	listLength(L); //返回L数据元素个数
	getElem(L, i, &e); //用e返回L中的i个元素的值(i >= 1)
	locateElem(L, e, compare()); //返回L中第一个与e满足关系compare的数据元素位序，若不存在，则返回值为0。
	priorElem(L, curEl, &preEl); //用preEl返回当前元素的前驱，若为当前为第一个则操作失败。
	nextELem(L, curEl, &nextEl); //用nextELem返回当前元素的后继，若为当前为最后一个则操作失败。
	listInsert(&L, i, e); //在L中第i个位置前插入e(i >= 1)，L长度加一。
	listDelete(&L, i, &e); //删除L第i个数据元素，并用e返回其值，L长度减一。
	listTraverse(L, visit()); //依次对L每个元素调用visit()，一旦visit失败，则操作失败。
} ADT List
```

**合并线性表**

已知线性表LA和LB中数据元素非递减有序，将两者合并为新线性表LC，且LC仍非递减有序。

```c
int la[] = {3, 5, 8 11};
int lb[] = {2, 6, 8 ,9, 11, 15, 20};
//O(listLength(la) + listLength(lb))
void mergeList(List la, List lb, List &lc) {
	initList(lc);
	i = j = 1;
	k = 0; //lc计数
	laLen = listLength(la);
	lbLen = listLength(lb);
	while ((i <= laLen) && (j <= lbLen)) {
		getElem(la, i, ai);
		getElem(lb, j, bj);
		
		//如果要想相同元素只插入一个，只需用switch语句比较三种情况
		//在判断ai == bj时，只插入其中一个即可。
		//当前为相同元素也插入。
		if (ai <= bj) {
			listInsert(lc, ++k, ai);
			++i;
		} else {
			listInsert(lc, ++k, bj);
			++j;
		}
	}

	while (i <= laLen) {
		getElem(la, i++, ai);
		listInsert(lc, ++k, ai);
	}

	while (j <= lbLen) {
		getElem(lb, j++, bj);
		listInsert(lc, ++k, bj);
	}
}
```

## 线性表顺序表示和实现

线性表的顺序表示是指用一组地址连续的存储单元(字节为单位)依次存储线性表的数据元素。设线性表每个元素占用`l`个存储单元，并以所占第一个单元的存储地址作为数据元素的存储位置。线性表中第`i+1`个数据元素存储位置为$LOC(a_{i+1})$和第`i`个为$LOC(a_i)$。满足下述关系

$$LOC(a_{i+1}) = LOC(a_{i}) + l$$

一般来说线性表第`i`个元素的存储位置为

$$LOC(a_i) = LOC(a_1) + (i-1) \times l$$

$LOC(a_1)$是线性表第一个数据元素的存储位置，通常称作线性表的起始位置或`基地址`。这种线性表的顺序存储结构称为`顺序表`，也就是说，以元素在计算机内"物理位置相邻"来表示线性表中数据元素之间的逻辑关系。因此只要确定了存储线性表的起始位置，线性表中任一数据元素都可`随机存取`(数据的读取或写入所需时间与该数据所在位置无关，与之相反的则叫顺序存取)，所以线性表的顺序存储结构是一种随机存储的存储结构。

C高级语言中数组类型具有随机存储特性，因此，通常用数组来描述数据结构中的顺序存储结构。由于线性表长度可变，可用动态分配的一维数组。

**顺序存储结构**

```c
#define LIST_INIT_SIZE 100; //线性表初始数据元素个数
#define LIST_INCREMENT 10; //分配增量

typedef struct {
	ElemType *elem; //存储空间基址
	int length; //当前长度，表示已有数据元素个数
	int listsize; //顺序表当前分配的存储空间大小，代表可存储总的数据元素个数。
} SqList;
```

**顺序表初始化**

```c
status initSqList(SqList &L) {
	L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L.elem) exit(OVERFLOW); //存储分配失败
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	return ok;
}
```

**顺序表元素插入**

线性表的插入操作是指在线性表的第`i-1`个和第`i`个数据元素之间插入一个新元素(在第i个元素之前插入)，同时使长度为n的线性表变为长度为`n+1`的线性表。由于顺序表中逻辑相邻的数据元素在物理位置上也是相邻的，除非`i=n+1`，否则必须移动元素位置才能反映这个逻辑关系的变化。

```c
//在第i(1<=i<=n)个元素前插入一个元素，将i至n共有n-i+1个元素依次向后移一个位置
status instertSqList(SqList &L, int i, ElemType e) {
	//i合法值1<=i<=length+1
	if (i < 1 || i > L.length + 1) return error;
	//空间是否够用
	if (L.length >= L.listsize) {
		newbase = (ElemType *)realloc(L.elem, (L.listsize + LIST_INCREMENT) * sizeof(ElemType));
		if (!newbase) exit(OVERFLOW);
		L.elem = newbase;
		L.listsize += LIST_INCREMENT;
	}
	//获取插入位置
	q = &(L.elem[i - 1]);
	//向后移位
	for (p = &(L.elem[length - 1]); p >= q; p--) {
		*(p + 1) = * p;
	}
	//插入数据元素
	*q = e;
	L.length++;
	return ok;
}
```

**顺序表元素删除**

线性表的删除操作使长度为n的线性表变为`n-1`的线性表，删除操作需向前移位。

```c
//删除第i(1<=i<=n)个元素时需要从第i+1至n个元素依次向前移动一个位置。
status deleteSqList(SqList &L, int i, ElemType &e) {
	//i合法值1<=i<=length
	if (i < 1 || i > L.length) return error;
	//被删除元素位置
	p = &(L.elem[i - 1]);
	e = *p;
	//表尾元素位置
	q = L.elem + L.length - 1;
	for (p++; p <= q; p++) {
		*(p - 1) = *p;
	}
	L.length--;
	return ok;
}
```

插入和删除的时间复杂度为`O(n)`。

**顺序表中的查访**

```c
int locateElemSq(SqList L, ElemType e, status(*compare)(ElemType, ElemType)) {
	i = 1;//i初始值为第一个元素的位序
	p = L.elem;
	while (i <= L.length && !(*compare)(*p++, e)) ++i;
	if (i <= L.length) return i;
	else return 0;
}
```

时间复杂度为`O(L.length)`。

如果将La和Lb两个线性表进行合并，应先对线性表排序(快速排序)再合并，这样可以使合并过程不需要进行全局搜索(避免重复元素，此方法时间复杂度为`O(La.lenth * Lb.length)`)，从而使合并操作的时间复杂度是线性的，也就是`O(La.length + Lb.length)`。