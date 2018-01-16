#include <stdio.h>
#include <string.h>
//计算两数相加很大转化为字符串处理，然后一位位输出。
//核心 int a = '9' - '0'，转化为数字型9
//'\0'与0的关系, 类型转换'\0' == 0。
int main() {
    char a[1001], b[1000];
    while (scanf("%s %s", a, b) != EOF) {
        int al = strlen(a), bl = strlen(b);
        int total = (al >= bl ? al : bl);
        int start = 0, end = total, temp = 0;
       
        while (al && bl) {
            int sum = (a[--al] - '0') + (b[--bl] - '0') + temp;
            a[end--] = sum % 10;
            temp = sum / 10;
        }

        while (al) {
            int sum = (a[--al] - '0') + temp;
            a[end--] = sum % 10;
            temp = sum / 10;
        }

        while (bl) {
            int sum = (b[--bl] - '0') + temp;
            a[end--] = sum % 10;
            temp = sum / 10;
        }

        if (temp == 0) {
            start = 1;
        } else {
            a[0] = temp;
            total++;
        }

        while (total--) {
            printf("%d", a[start++]);
        }
        printf("\n");
    }
    return 0;
}

