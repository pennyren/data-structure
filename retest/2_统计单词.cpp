#include <stdio.h>
// 用char str[]字符数组存入字符串
// str本身为地址，所以scanf("%s", str);
// scanf输入字符串，从第一个非空白开始，字符串遇到第一个空白字符为止(直接利用这个性质计算每个单词字母个数)
// gets(字符数组名)可输入包含空白字符串
// 再声明指针，p = str,才再可以使用p++
int main() {
    char str[100];
    while (scanf("%s", str) != EOF) {
        int count = 0;
        char *p = str;
        while (*p != '.' && *p != '\0') {
            count++; p++;
        }
        *p == '.' ? printf("%d\n", count) : printf("%d ", count);
    }
    return 0;
}
