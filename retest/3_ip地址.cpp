#include <stdio.h>
int main() {
    int n, ip[100][4];
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf("%d.%d.%d.%d", &ip[i][0], &ip[i][1], &ip[i][2], &ip[i][3]);
        }
        for (int i = 0; i < n; i++) {
            int isNotFormal = 0;
            for (int j = 0; j < 4; j++) {
                if (ip[i][j] < 0 || ip[i][j] > 255) isNotFormal = 1;
            }
            isNotFormal ? printf("No!\n") : printf("Yes!\n");
        }
    }
}
