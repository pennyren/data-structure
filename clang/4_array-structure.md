## 一维数组

**声明**

```c
//c1必须为整型常量，不可以为变量
int arrName[c1];
int score[10];
```

**引用**

数组只能引用单个数组元素，不能整个数组。每个数组元素相当于一个普通变量。引用时其下标可以是常量、变量或表达式，但必须是整型数。

```c
//第一个
score[0]

//最后一个元素
score[-1]
score[9]

//赋值
int i = 1;
scorce[i] = 7;
```

**初始化**

```c
//初值个数与数组长度相等，可以省略数组长度，其大小可以由初值个数确定。
int score[3] = {2, 5, 1};
int score[] = {2, 5, 1};

//初值个数小于数组大小，后面元素自动补值为0
int score[5] = {2, 4, 1};

//所有初始为0
int score[10] = {0}
```

## 二维数组

```c
//定义
int ice[5][7];

//引用
ice[0][2];

//初始化，部分赋初值
//结果为1 0 0 2 3 0 0 0 0
int a[3][3] = {{1}, {2, 3}};

//可省略第一维长度。第二位则不可以。这样C可自动确定第一唯长度。
int a[][2] = {1, 2, 3, 4};
```

## 字符数组

```c
//用字符为字符数组赋初值
char word[4] = {'t', 'r', 'e', 'e'};

//用字符串给字符数组赋初值，注意其大小有所不同。
char word[5] = "tree";

//字符串初始时，字符少于数组个数，则多余元素赋值为'\0'。反之报错。
char word[10] = "tree";
```

**字符数组输入输出**

```c
//c语言中数组名代表数组的首地址，因此不使用&。
//scanf不包含空白符，在输入中会自动截取空白字符前面的值。
scanf("%s", word);
//gets包含空白符
gets(word);


printf("%s", word);
puts(word);
```

**字符串处理函数**

```c
#include <sting.h>

//字符串长度函数，返回实际字符数
strlen(word);

//字符串复制函数，将字符2所有字符一个一个复制到字符1中，直到遇到第一个结束标志'\0'。实现了对字符数组的整体赋值。
//若使用word1 = word2会报错。它试图修改word1的地址，这是不被允许的。
//使用前保证数组1长度大于数组2
strcpy(word1, word2);

//指定复制字符数
strncpy(word1, word2, 3);

//字符连接函数，取消字符1的结束标志'\0'，把字符2拼接到字符1后，并把结果存在字符1数组中，所以必须保证字符1数组足够大。
strcat(word1, word2);

//字符比较函数，从左至右进行字符的ASCII码值比较，直到出现不同字符或结束标志'\0'。相等返回0，字符1 > 字符2 返回正数，反之，负数。
strcmp(word1, word2);
```

## 结构

结构是一个或多个变量的集合，与数组不同，结构中的变量可能为不同的类型。

```c
//定义。student为结构类型名
struct student {
	int sex;
	int birthday;
	double height;
};
//定义并声明变量
struct student {
	int sex;
	int birthday;
	double height;
} stu1, stu2;

//访问
scanf("%d", &stu1.sex);
stu1.birthday;

//初始化
struct point {
	int x;
	int y;
}
struct point pt = {32, 20};

//结构数组
struct student stu[20];
printf("%s", stu[1].name);
```