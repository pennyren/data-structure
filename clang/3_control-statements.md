## if条件

```c
//简单语句
if (x == y)
	z = 0;

if (a > b)
	z = 1;
else
	z = 3;

//复合语句
if (x == y) {
	z = 0;
	w = 10;
} else {
	z = 10;
	w = 0;
}

//多路判断
if () {
	
} else if () {
	
} else if () {
	
} else {
	
}
```

## switch多路开关

```c
switch (expression) {
	case c1:
		s1;
		break;
	case c2:
		s2;
		break;
	default:
		sn; 
		break;
}

//c1,c2为常量表达式，switch后面圆括号与case后的值都必须是整型或字符型，不允许浮点型。
```

## 循环语句

```c
do {
	
} while (expression);

while (expression) {
	
}

for (exp1; exp2; exp3) {
	
}
```

## goto语句

```c
//无条件跳转语句 goto 标识符; 应该限制使用。
loop: if (num <= 10) {
	num++;
	goto loop;
}
```