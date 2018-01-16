#include <stdio.h>
#include <stdlib.h>

//c中不能返回数组，也不能返回数组名，除非使用malloc
//类型转换，字符转为整数，其为对应ASCII码
//数组中二进制为低位到高位
int *decToBinary(int num) {
    int *bin = (int *)malloc(sizeof(int) * 8);
    int i = 0, c = 0;
    while (num > 0) {
        int val = num % 2;
        bin[i++] = val;
        num = num / 2;
        if (val == 1) c++;
    }
    while (i < 8) {
        bin[i++] = 0;
    }
    if ((c % 2) == 0) bin[7] = 1;
    return bin;
}

//字符的8位(ascii=>bin)表示中1的个数，如果1的个数为偶数，就把最高位置1.
int main() {
    char str[100];
    while (scanf("%s", str) != EOF) {
        char *p = str;
        while (*p) {
            int *bin = decToBinary(*p);
            bin = bin + 7;
            for (int i = 0; i < 8; i++) {
                printf("%d", *bin--);
            }
            printf("\n");
            p++;
        }
    }
    return 0;
}
