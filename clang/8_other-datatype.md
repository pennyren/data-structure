## 结构体特殊形式

**位域**

计算机语言中通常以字节单位表示的，但实际中常需按位来表示信息。c语言中允许定义具有可变长度位的结构成员。这种成员称为位域。通过位域可以方便的用成员名访问小于一个字节的存储区。

```c
struct device {
	unsigned active: 1;
	unsigned error: 2;
}
```

**结构嵌套**

```c
struct date {
	int month;
	int day;
	int year;
};

struct person {
	char name[10];
	int age;
	float wage;
	struct date payday;
} worker;
worker.payday.year = 1993;
```

## 联合

联合是与结构相类似的构造类型。区别在于联合类型变量所占内存空间不是各个成员所需存储空间字节数的总和，而是联合成员中需要存储空间最大的成员所要求的字节数。因为c规定联合的各个成员**共享一个公共存储空间，任何给定时刻只能允许一个成员驻留在联合中**。

```c
union data {
	char ch;
	short num;
	long lnum;
} value;

value.ch = 'a';
value.num = 32;
```

联合变量value是一个能在不同时刻合理的保存三种数据类型中的任何一种类型的变量。

## 枚举

列举一系列由用户自己确定的**有序标识**所定义的类型叫枚举类型。标识符名称代表一个数据值，其间有先后顺序，可进行比较，通常把标识符称为枚举类型元素。

```c
//称为color的枚举类型
enum color {black, blue, red, green, white};
//枚举变量col，它可以取也只能取枚举中任一个标识符。
enum color col;
col = blue;

//枚举实质是编译程序将枚举中的每个标识符按次序用它们所对应的整数型数代码来代替，第一个为0，二为1，依此类推。
printf("%d%d%d", black, blue, red);
```

## typedef

c语言允许用户使用关键字`typedef`，为已有类型定义一个**新名字**。

```c
//typedef 类型 定义名;
typedef int integer;
integer x, y;

//给结构类型struct birth_day改为定义名birthday
typedef struct {
	char name[10];
	int month;
	int day;
} birthday;
birthday student[100];
```

## 预处理功能

c语言预处理功能由预处理程序实现的。预处理程序负责分析和处理以`#`为首字符的**预处理控制行**。预处理控制行主要有宏替换、文件包含和条件编译。它的作用范围仅限于说明它的文件，超出那个文件就失去作用。

**宏替换**

```c
//字符串替换，定义一个宏标识符(宏替换名)，和一个字符串，在程序中每次遇到该标识符就用字符串替换
//标识符替换常量
#define TRUE 1
#define FALSE 0

//带参宏定义及宏调用，类似与函数，调用时返回宏的值。
//和函数区别在于，宏在程序预处理阶段进行简单的替换，因此无类型要求，可适用任何参数类型。
#define MAX(a, b) ((a > b) ? a : b)
MAX(10, 20)

//撤销宏定义
#undef MAX
```

**包含文件**

```c
#include "文件名"
#include <文件名>
```

include文件也可以用于包含外部变量和复杂数据类型的说明，所需要的类型仅需要在include文件中定义和命名一次。被包含的文件通常被称为头文件，并以`.h`作为后缀。其中include的文件名符合路径系统的查找过程。