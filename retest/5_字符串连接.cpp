#include <stdio.h>

int main() {
    char origin[200], add[100];
    while (scanf("%s %s", origin, add) != EOF) {
        char *p = origin, *q = add;
        while (*p) {
            p++;
        }
        while (*q) {
            *p = *q;
            p++;
            q++;
        }
        *p = '\0';
        printf("%s\n", origin);
    }
    return 0;
}
