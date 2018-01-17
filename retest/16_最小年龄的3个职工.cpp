#include <stdio.h>
#include <string.h>

typedef struct {
    int num;
    char name[10];
    int age;

} Worker;

int cmp(Worker a, Worker b) {
    if (a.age != b.age) {
        return a.age > b.age;
    } else if (a.num != b.num) {
        return a.num > b.num;
    } else {
        return strcmp(a.name, b.name) > 0;
    }
}

int main() {
    int n, i, j;
    Worker wks[30];
    while (scanf("%d", &n) != EOF) {
        for (i = 0; i < n; i++) {
            scanf("%d %s %d", &wks[i].num, &wks[i].name, &wks[i].age);
        }

        for (i = 1; i < n; i++) {
            Worker wk = wks[i];
            for (j = i - 1; cmp(wks[j], wk) && j >= 0; j--) {
                wks[j + 1] = wks[j];
            }
            wks[j + 1] = wk;
        }

        for (i = 0; i < 3; i++) {
            printf("%d %s %d\n", wks[i].num, wks[i].name, wks[i].age);
        }
    }
    return 0;
}
