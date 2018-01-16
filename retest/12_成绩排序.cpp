#include <stdio.h>
#include <string.h>

// Multiple Columns Sort

// strlen(strName)
// strcat(arrName, str)
// strcmp(str1, str2) >0 =0 <0
typedef struct {
    char name[100];
    int age;
    int score;
} Student;

int cmp(Student a, Student b) {
    if (a.score != b.score) {
        return  a.score > b.score;
    } else if (strcmp(a.name, b.name) != 0) {
        return strcmp(a.name, b.name) > 0;
    } else {
        return a.age > b.age;
    }
}

void insertSort(Student stu[], int n) {
    int i, j;
    for (i = 1; i < n; i++) {
        if (cmp(stu[i - 1], stu[i])) {
            Student temp = stu[i];
            for (j = i - 1; (cmp(stu[j], temp) && j >= 0); j--) {
                stu[j + 1] = stu[j];
            }
            //由于多一次j--
            stu[j + 1] = temp;
        }
    }
}

int main() {
    int n;
    Student stu[1000];

    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf("%s %d %d", &stu[i].name, &stu[i].age, &stu[i].score);
        }

        insertSort(stu, n);

        for (int i = 0; i < n; i++) {
            printf("%s %d %d\n", stu[i].name, stu[i].age, stu[i].score);
        }
    }
}
