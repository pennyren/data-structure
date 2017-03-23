## I/O系统与流

c语言的I/O系统为编程者提供了一个与具体被访问的设备无关的统一接口，这个接口把输入输出的信息抽象为**流**。把具体的实际设备称为文件。流的类型包括

* 文本流 一行行字符，它是对一个个字符进行存取的。
* 二进制流 由一系列字节组成，使用中无字符的"翻译"过程。

计算机键盘和显示器上的操作通常称为控制台上的I/O操作。

## 文件

使用FILE型文件的程序，需嵌入`stdio.h`头文件，当一个流式文件被打开时，C编译程序自动建立该文件的FILE结构并返回一个指向FILE结构类型的指针。

**fopen**

若要访问一个文件，则必须用fopen函数预先打开。

```c
FILE *fp;
//filename为访问的文件名，mode确定如何使用该文件。
//r只读、w建立一个新文件，只可写不可读、a在已存在文件尾部添加
//r+可读可写、w+建立一个可读可写新文件、a+从文件当前位置开始往文件中添加内容，可同时读写文件
//上述打开方式可附加t或b字符，可指定按文本方式还是二进制方式打开。默认为文本。
fp = fopen(filename, mode);

//检测文件是否存在，不存在返回null，也就是0。
if (fp == NULL) {
	
}
```

**fclose**

```c
//关闭打开文件
fclose(fp)
```
## 用于文件的输入输出函数

**单字符输入输出**

`int getc(FILE *fp)`、`int putc(int ch, FILE *fp)`

```c
int c;
//从文本中读取字符，getc函数读到文件结尾返回EOF标记
while (c = getc(fp) != EOF) {
//putc操作成功返回写入文件的字符ASCII码，若错误返回EOF，也就是-1。
	putc(c, stdout);
}
```

使用`feof()`检查文件是否结束，文件拷贝方式如下。

```c
file *in, *out;
char c;
if (in = fopen(name, "rb") == null) {
	return;
}
if (out = fopen(name, "wb") == null) {
	return;
}
while (!feof(in)) {
	c = getc(in);
	putc(c, out);
}

fclose(in);
fclose(out);
```

**行输入输出**

从文件读出字符串`char *fgets(char *str, int length)`，从文件中写字符串`char *fputs(char *str, FILE *fp)`。

```c
#define size 80
char line[size];
//line为读出的数据要存放的地方，size表示一次读出字符串，一直读至换行符或第size-1个字符为止。
fgets(line, size, fp);
```
**数据块的输入输出**

```c
int fread(void *buffer, int size, int n, FILE *fp);
int fwrite(void *buffer, int size, int n, FILE *fp);
```
buffer是一个指向数据块存储区的指针，fread中buffer接受从文件中读取的数据。fwrite中，buffer中的数据向文件写入，读写的字段数用n表示(每个字段为size个字节)。**文件位置指示器随所读取的字符数增加。**它们返回实际已读写的字段个数。`ferror()`用来检测给定流中的文件错误，若有错返回非0，否则返回0。  

只要一个文件以二进制文件方式打开，fread和fwrite函数就可以读写任何类型的信息，这两函数用武之地在于读写数组或结构。

```c
int buffer[] = {100, 110, 120, 130, 140, 150};
FILE *fp;
if (fp = fopen("arrdata", "wb") == null) {
	return;
}
fwrite((char *)buffer, 2, 10, fp);
fcolse(fp);
```

## 文件随机访问

如果位置指针是按字节位置顺序移动，就是顺序读写。如果可以将位置指针按需要移动到指定位置，就实现了随机读写。随机读写关键就是控制文件的位置指针。
`int fseek(FILE *stream, long offset, int origin)`，它一般用于二进制文件。