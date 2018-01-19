#include <stdio.h>
// n阶台阶问题，递归关系f(n) = f(n-1) + f(n-2);
// 1.递推求解在于确定数列的递推关系 。
// 2. 采用递归时从现在向前面追溯，不用递归，从现在向后面预处理.先计算出F[n] = F[n-1] + F[n-2] 

int steps(int n) {
	if (n == 1) {
		return 1;
	} else if (n == 2) {
		return 2;
	} else {
		return steps(n - 1) + steps(n - 2);
	}
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        int record[n];
        record[0] = 1;
        record[1] = 2;
        for (int i = 2; i < n; i++) {
            record[i] = record[i - 1] + record[i - 2];
        }
        printf("%d\n", record[n-1]);
    }
}
