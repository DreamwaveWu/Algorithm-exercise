#include<bits/stdc++.h>
using namespace std;

/*
这道题可以暴力解决。
对于原图中的每一个点，对其横纵坐标+S范围内的点进行逐一搜索，只有与小地图一一对应时才符合要求。
搜索剪枝：
（1）大地图的 S * S 范围内，树的数量超过小地图的数量，停止搜索。
（2）大地图的 S * S 范围内，任意一棵树与小地图不对应，停止搜索。

*/

int main() {
	int n, L, S;
	int a[1005][2];
	int s[55][55];
	memset(a, 0, sizeof(a));
	memset(s, 0, sizeof(s));
	scanf("%d%d%d", &n, &L, &S);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &a[i][0], &a[i][1]);
	}
	int cb = 0;
	for (int i = S; i >= 0; i--) {
		for (int j = 0; j <= S; j++) {
			scanf("%d", &s[i][j]);
			if (s[i][j] == 1)	cb++;
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {	// 每一个大图中的点
		if (a[i][0] + S > L || a[i][1] + S > L)	continue;
		int ca = 0;
		bool flag = false;
		for (int j = 0; j < n; j++) {
			int x = a[j][0] - a[i][0], y = a[j][1] - a[i][1];
			if (x < 0 || y < 0 || x > S || y > S)		continue;
			ca++;
			if (ca > cb || s[x][y] == 0) {
				flag = true;
				break;
			}

		}
		if (flag || ca != cb)	continue;
		ans++;
	}
	printf("%d", ans);
	return 0;
}
