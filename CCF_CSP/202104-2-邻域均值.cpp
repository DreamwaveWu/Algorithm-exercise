#include<bits/stdc++.h>
using namespace std;

int x[605][605], s[605][605];


/*
使用二维差分数组。
注意：横纵坐标均从 1 开始， n 结束。
由于通过差分数组计算面积，会使得 x1 和 y1 比方形的左上角坐标小 1 单位。
从 1 开始是为了使差分数组的 0 坐标为 0，方便运算。

*/


int main() {
	int n, L, r, t;

	memset(x, 0, sizeof(x));
	memset(s, 0, sizeof(s));
	scanf("%d%d%d%d", &n, &L, &r, &t);
	for (int i = 1; i <= n; i++) {
		for (int j = 1 ; j <= n; j++) {
			scanf("%d", &x[i][j]);
			s[i][j] = x[i][j];
			if (i == 0 && j == 0) continue;
			else if (i == 0)	s[0][j] += s[0][j - 1];
			else if (j == 0)	s[i][0] += s[i - 1][0];
			else	s[i][j] = x[i][j] + s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
		}
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int x1, x2, y1, y2;
			x1 = (i - r - 1 <= 0) ? 0 : i - r - 1;
			x2 = (i + r > n) ? n : i + r;
			y1 = (j - r - 1 <= 0) ? 0 : j - r - 1;
			y2 = (j + r > n) ? n  : j + r;
			int sum = (x2 - x1) * (y2 - y1);
			if (t * sum >= (s[x2][y2] - s[x1][y2] - s[x2][y1] + s[x1][y1]))	cnt++;
		}
	}
	printf("%d", cnt);
	return 0;
}
