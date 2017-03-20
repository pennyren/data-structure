## 数据类型

数据类型是数据的基本属性，描述的是数据的存储格式和运算规则。不同的数据类型在内存中所需的存储空间大小、存储格式均有所不同。C语言提供的数据类型包括。

* 基本数据类型：整型、浮点、字符。
* 构造类型：数组、结构、联合、枚举，它是用户自定义的类型，可以由基本数据类型或其他构造类型构造而成。
* 指针类型：具有特殊及重要的作用，用来表示变量在内存中的地址，它提供了动态处理变量的能力，是C的精髓。
* 空类型：它用作函数的返回类型，表示函数不返回任何值，也用作指针的基本类型，描述指向任何数据的指针。

**预备知识**

内存是以字节为单位的连续的存储空间，每个内存单元(`byte`)有一个唯一的编号，即地址。一个字节为8位(`bit`)，也就是8个二进制组成。

计算机内表示数值，以最高位作为符号位，`0为正数`，`1为负数`。

* 原码：最高位作为符号位来表示数的符号，其余各位代表数值本身的绝对值。
* 反码：正数的反码与原码相同，负数则符号位不变，其余各位取反。
* 补码：正数的补码与原码相同，负数则符号位不变，其余各位取反，最后加一。

由于原码、反码表示0的方法不唯一，而补码是唯一的，现在计算机通常都是以**补码**形式存放数。

**整型**

* `int`普通整型，VC++ 6.0环境所占内存空间4byte。
* `short`短整型，VC++ 6.0环境所占内存空间2byte。
* `long`长整型，VC++ 6.0环境所占内存空间4byte。

根据整型值是否带有符号位可分为带符号位和不带符号位的整型值，无符号用`unsigned`，有符号用`signed`，默认为有符号数。若指定为无符号型，存储单元全部二进制位用作存放数本身，而不包括符号。

**浮点型**

* `float`单精度浮点数，4byte。
* `double`双精度浮点数，8byte。
* `long double`长双精度浮点数，16byte。

**字符型**

`char`字符型，1byte。它也包括有符号与无符号型。

## 常量

常量在程序执行过程中其值不能改变，C中有整型常量、浮点型常量、字符型常量、字符串常量和符号常量。

**整型常量**

* 十进制 `12, -19`。
* 八进制 `027`，通常它是一个无符号数。
* 十六进制 `0x3f`，通常用来表示地址，也是无符号数。

整常量的类型可以用后缀来指定，`u`表示是无符号型，`89u`，`0xd8u`。`l`表示长整型，`0x23fl`。`lu`则表示无符号长整型，`6789lu`。

**浮点型常量**

* 十进制 `3.32, .89`。
* 指数 它由基数(十进制小数)、阶码标志`e`、指数(只能为整数可以带符号)组成。如`3.5e3, 6.5e-2`。

规范化指数形式是指基数部分，小数点左边有且只有一位非零数字，345.23规范化为`3.5478e2`。
如果浮点数常量不带后缀，它是双精度型，带有`f`表示单精度，`l`则为长双精度。
浮点型数据在内存中是按照指数形式存储的。其被分为`数符+小数部分+指符+指数`存储。

**字符型常量**

字符型常量是用单引号括起来的一个字符，如`'a'`。除了这种类型字符常量外，还包括转义字符，以`\`开头的字符序列。转义字符包含以下三种。

* 简单转义字符，它是具有特殊控制功能字符，如`'\n'`换行。
* 八进制转义字符，如`'\071'`，它代表ASCII码值(十进制)为57的数字9。
* 十六进制转义字符，如`'\xfe'`，代表ASCII码值(十进制)为254的图形字符。

字符型在内存中存储并不是把字符本身放到内存单元，而是将ASCII码值存放在内存单元，以二进制形式存储。也就是说它与整数的存储形式类似。

**字符串常量**

字符串常量用双引号括起来的零个或多个字符组成的序列，如`"Hello"`。C编译器在存储字符串常量时自动在其末尾加上`'\0'`(ASCII码为0的NULL字符)作为字符串结束标志。所以`"Hello"`为6个字节。

C语言没有专门的字符串变量，如果想将字符串存放在变量中，必须使用字符数组。

**符号常量**

C中常量出现的形式，一是直接使用给定值如`area = 3.14*r*r`。3.14就是直接形式的常量，称为**无名常量**，另一种是以标识符来代替常量的出现，也就称为**符号常量**

```c
const float PI = 3.14;
```

用`const`声明，其值不能被改变，否则报错，所以定义时必须初始化。符号常量的名称通常用大写字母表示。

## 变量

变量是在程序执行中其值可改变的量。定义包括变量名以及数据类型。在程序同一部分不允许对同一变量做重复定义，编译会报错。

```c
int i, j, k = 50;
float score;
```
C语言中变量必须先定义后使用，以便编译程序给其分配内存单元，否则报错。

通常把变量所占存储空间的首字节地址称为变了地址，变量名与内存中特定单元的地址联系在一起，在机器内部对变量值的存取是通过各自的地址进行的。所以变量名实际是一个符号地址，它指出了变量在内存中存放的位置，而变量值就是相应内存单元中存放的数据。

## 运算符和表达式

表达式是用运算符与圆括号将操作数连接起来的式子。

**运算符**

* `/` 两整数相除，结果仍为整数，商向下取整。20/3为6
* `%` 求余运算符，两个操作数必须为整数，结果的符号与%左边的操作数符号相同，45%-8为5。
* 关系运算符如`== !=`，关系表达式的值为逻辑值，真用1表示，假用0表示。
* 逻辑运算符`! && ||`，0为假，非0为真，!取反。&& ||为短路操作。
* 位运算符`& | ~ ^`，二进制的与，或，非，取反，异或。异或规则为如果两个相应的二进制位相同，该位结果为0，否则为1。位逻辑运算是针对二进制位的，而逻辑运算是针对整个表达式。
* 移位运算符`<< >>`，双目运算符，要求运行分量都是整型。移位表达式为(移位对象 << 移位位数)。<<左移n位相当实现被移对象乘2的n次方功能。右移则除以2的n次方。
* `,`运算符，它的优先级最低，低于=赋值。逗号运算符将多个表达式分割开来，并从左到右依次计算，并将最后的值作为整个逗号表达式的值。`i = (j = 30, 5 * 30)`i结果为150。

* `&`和`*`运算符互为逆运算，&取出地址，*为取出所指单元的内容。
* `sizeof`，计算某种类型变量所占字节数`sizeof(name)`。
* `()`强制类型转换符，如`(double)i`将变量i强制转换为double类型。

## 类型转换

**自动类型转换**

转换原则，为两个运算对象的计算结果尽可能提供多的存储空间。
如表达式中有char、short类型，运算前需转换为int，float转换为double。

当运算符两端的数据类型不一致时，运算前先将类型等级低的数据转换成等级较高的。称为保值转换。

**强制转换**

`(int) (x+y)`，进行强制转换时，得到的是一个所需类型的中间变量，原来的变量类型不变。

**赋值中转换**

若赋值运算符两侧的数据类型不一致，则需要将右侧转变成左边变量类型。
* 浮点赋给整型，舍弃浮点型小数部分。
* double赋给float，将截取其前7位有效数字。
* 整数间的数据转换，按存储单元中的存储形式直接传递。

## 数据输入输出

C中没有提供专门的I/O语句，而是通过函数调用来实现。

**字符IO**

```c
//字符输出
char c = 'a';
putchar(c);
putchar('a');

//字符输入
char b;
b = getchar();
```

**格式IO**

* `printf(格式控制串, 参数1, 参数2, ...)`
格式控制串用双引号括起来的字符串，它包括格式说明 = (% + 格式字符)。如"%d"，作用是将输出的数据转换为指定的格式输出。参数可以是表达式。其中格式字符包括

 * d十进制整型，o八进制，x十六进制，u无符号。
 * f浮点数，e指数形式浮点数。
 * c一个字符，s字符串。

其余格式控制串的字符原样输出。

* `scanf(格式控制, 参数1, 参数2, ...)`

参数指明输入数据所要放置的地址，所以出现在参数位置上的变量名前要加`&`运算符。如`scanf("a=%d, b=%d", &a, &b)`。格式控制中的普通字符是什么样，也必须照该原样输入。