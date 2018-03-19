## 指针

定义及初始

```c
//指针变量类型是指针变量所指向的变量的类型，而不是自身类型。
int *p = 0;
```

p为**指针变量**，它是一个特殊变量，指针变量中存放的是指向被访问**目标变量**的地址。C规定目标变量可以用指针变量名前加上运算符`*`表示，即`*p`为目标变量。

在C/C++系统中唯一一个允许赋值给指针类型变量的是整数0，它不指向任何变量，初始化为0可防止其指向任何未知内存区域。

```c
int i = 23;
int *p1 = 0, *p2 = 0;
p1 = &i;
p2 = p1;

//间接存取目标变量值
*p1 = *p1 + 1;
```

## 指针和数组

由于数组在内存中是连续排放的，所以任何由数组下标完成的操作均可由指针实现。指向数组元素的指针称之为**数组指针**，它的执行效率更高。

```c
int a[3] = {0};

//地址等价，数组名是一个指向该数组的指针，是一个地址常量。
a == &a[0];
```

不同的数据类型，数组元素间的地址偏移量不同，如short为2，int为4。但在C语言中，无论何种类型数组，不必关心元素间地址的偏移量是多少，地址加1，就代表后一元素地址。

```C
printf("%d", *(a + 1));

//指针变量看成数组名。
p1 = a;
printf("%d", p1[1]);

//先引用元素，p再指向下一元素。
*p++;
//p先指向下一元素，并引用该元素。
*(++p);
//p当前指向元素值加1
(*p)++;
```

计算字符串长度。

```c
int strlen(char *s) {
	int c = 0;
	while (*(s + c)) c++;
	return c;
}
```

## 指针和结构数组

```c
//定义结构
struct info {
	short num;
	char name[5];
};

//声明结构类型变量
struct info myinfo;

//声明指向info结构的指针，p指向结构的第一个字节，*p就代表info。
struct info *p = &myinfo;

//访问结构成员
myinfo.num;
(*p).num;

//(*p)书写麻烦，所以用下述形式->，指向成员运算符。
p -> num;

//结构数组
struct info stu[10];
p = stu ++;
p -> num;
```

## 字符串指针

C中没有为字符串数据提供专门的变量来存储，而是通过**字符数组**来处理字符串，字符数组就是用来存放字符串数据的。
在C中字符串被定义为以**空字符**'\0'结尾的字符序列，其表示ASCII码为0。事实上，字符数组唯一用途是为字符串提供分配存储的空间。

```c
//字符串数据存放进字符数组的方式
char str[] = "hello world";

char str[11];
scanf("%s", str);
```

字符数组倒序

```c
void reverse(char *string) {
   int length, c;
   char *begin, *end, temp;
 
   length = strlen(string);
   begin = string;
   end = string;
 
   for (c = 0; c < length - 1; c++) end++;
 
   for (c = 0; c < length/2; c++) {        
      temp   = *end;
      *end   = *begin;
      *begin = temp;
 
      begin++;
      end--;
   }
}
```

如果不通过分配数组也可获得内存空间，我们可以通过一个指向第一个字符的指针来标记字符串开头，就像被存储在字符数组一样。以下字符串分配空间方式。

```c
//程序编译时分配字符串常量的存储空间。
char *p = "hello world";

//执行时动态分配字符存储空间。malloc开辟空间，并返回第一个字节的地址。它包含与头文件stdlib.h。
char *p = (char*)malloc(50);
```

## 指针数组

指针数组也是数组，其数组单元装的是指针，也就是内存单元地址，而这些指针必须指向同一种数据类型的变量。

```c
char str1[] = "China", str2[] = "America", str3[] = "German";
char *p[3] = {str1, str2, str3};

//str2字符串
printf("%s", p[1]);

//str3的第3个字符
printf("%c", *(p[2] + 3));
```

## 指向指针的指针

由于指针变量本身是一个变量，它被存储在计算机内存特定地址处，因此可以创建指向指针的指针。

```c
int a = 123;
int *p = &a;
int **p1 = &p;
```

声明和使用指向指针的指针被称为多重间接。对于多重间接的层数没有任何限制，但多余两层无任何好处，无疑是自找麻烦。