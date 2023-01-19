#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

/*
【二维差分】
（洛谷P3397)https://www.luogu.com.cn/problem/P3397
  D[i][j] = a[i][j] - a[i-1][j] - a[i][j-1]+ a[i-1][j-1]
  技巧：不定义 a[][]， 在 D[][] 上通过递推计算 a[][]
*/

static int D[5000][5000];

void main_2D_difference() {
	int n, m;
	scanf("%d%d", &n, &m);
	while (m--) {
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		D[x1][y1] += 1;
		D[x1][y2 + 1] -= 1;
		D[x2 + 1][y1] -= 1;
		D[x2 + 1][y2 + 1] += 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			D[i][j] += D[i - 1][j] + D[i][j - 1] - D[i - 1][j - 1];
			printf("%d ", D[i][j]);
		}
		printf("\n");
	}
}