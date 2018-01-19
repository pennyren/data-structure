## 基本结构

```c
#include <stdio.h>

void main() {
	printf("Hello World! \n")
}
```

为了顺利调用库函数`printf`，需嵌入`stdio.h`头文件，该头文件中定义了printf函数原型。

* `/*多行注释*/`
* `// 单行注释`

## 运行

在VC++ 6.0中，File -> 新建 -> 文件 -> C++ Source File。输入文件名保存文件后默认扩展名为`.cpp`，它是C++的扩展名，如果编写的是C程序，也可指定以文件扩展名`.c`来保存。

编译点击Compile按钮，也可使用快捷键Ctrl+F7，在编译连接过程中，VC++会生成一个工作区。

编译后运行，点击Execute，执行程序。