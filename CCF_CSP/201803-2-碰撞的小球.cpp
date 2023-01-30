#include<bits/stdc++.h>
using namespace std;

/*
在整个过程中，所有球的相对次序都是不变的。
因此先按照坐标排序，
每一个时刻对每一个球进行暴力模拟。
注意最后需要按照读入的顺序输出，
*/



struct node {
	int id;
	int x;	// 坐标
	int p;	// 方向，左 0 右 1
} a[105];

bool cmp1(node a, node b) {	  // 先按坐标排序
	return a.x < b.x;
}

bool cmp2(node a, node b) {		// 最后按 id 输出
	return a.id < b.id;
}

int main() {
	memset(a, 0, sizeof(a));
	int n, L, t;
	scanf("%d%d%d", &n, &L, &t);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i].x);
		a[i].id = i;
		a[i].p = 1;	// 左 0 右 1
	}
	sort(a + 1, a + 1 + n, cmp1);
	bool flag = false;		// flag 表示刚刚是否发生碰撞
	for (int i = 1; i <= t; i++) {
		flag = false;
		if (a[n].p == 1) {	// 单独分析最右边的球
			a[n].x += 1;
			if (a[n].x  == L) {
				a[n].p = 0;
			}
		} else {
			a[n].x -= 1;
			if (a[n - 1].x  == a[n].x  - 1 && a[n - 1].p == 1) {
				a[n].p = 1;
				a[n - 1].x  += 1;
				a[n - 1].p = 0;
				flag = true;
			}
		}
		for (int k = n - 1; k >= 2; k--) {
			if (a[k].p == 1) {
				a[k].x += 1;
				flag = false;
			} else if (a[k].p == 0 && !flag) {
				a[k].x -= 1;
				if (a[k - 1].x  == a[k].x  - 1 && a[k - 1].p == 1) {
					a[k].p = 1;
					a[k - 1].x  += 1;
					a[k - 1].p = 0;
					flag = true;
				}
			} else if (flag) {
				flag = false;
			}
		}
		if (!flag) {	// 单独分析最左边的球
			if (a[1].p == 1) {
				a[1].x  += 1;
			} else {
				a[1].x  -= 1;
				if (a[1].x  == 0) {
					a[1].p = 1;
				}
			}
		}

	}

	sort(a + 1, a + 1 + n, cmp2);
	for (int i = 1; i <= n; i++) {
		printf("%d ", a[i].x);
	}

	return 0;
}
