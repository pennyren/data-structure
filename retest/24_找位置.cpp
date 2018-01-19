#include <stdio.h>
#include <string.h>

typedef struct {
    char el;
    int index[100];
} Position;

int main() {
    char str[100];
    while (scanf("%s", str) != EOF) {
        Position pos[100] = {{'-', {-1}}}; //只初始位置1
        int i = 0, j, k, len = strlen(str);
        while (i < len) {
            for (j = 0; j < 100; j++) {
                if (pos[j].el == str[i]) {
                    for (k = 0; k < 100; k++) {
                        if (pos[j].index[k] == -1) {
                            pos[j].index[k] = i;
                            pos[j].index[k + 1] = -1;
                            break;
                        }
                    }
                    break;
                }

                if (pos[j].el == '-') {
                    pos[j].el = str[i];
                    pos[j].index[0] = i;
                    pos[j].index[1] = -1;
                    pos[j + 1].el = '-';
                    pos[j + 1].index[0] = -1;
                    break;
                }
            }
            i++;
        }


        i = 0;
        while (pos[i].el != '-') {
            j = 0;
            if (pos[i].index[1] != -1) {
                while (pos[i].index[j] != -1) {
                    pos[i].index[j + 1] == -1 ? printf("%c:%d\n", pos[i].el, pos[i].index[j]) : printf("%c:%d,", pos[i].el, pos[i].index[j]);
                    j++;
                }
            }
            i++;
        }
    }
    return 0;
}
