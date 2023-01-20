#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

/*
-------------- < 树 状 数 组 > ---------------
			 Binary Indexed Tree

【基本功能】查询前缀和、修改元素值
【时间复杂度】O(nlogn)
【典型应用】区间修改+单点查询、区间修改+区间查询、二维区间修改+区间查询、区间最值

*/


// ----------- 基本编码 begin ------------
static const int N = 1000;
#define lowbit(x) ((x)&(-x))
static int tree[N] = { 0 };

void update_BIT(int x, int add_val) {	// 单点修改 a[x]=a[x]+new_val
	while (x <= N) {
		tree[x] += add_val;	// 注意，单点修改是增值不是直接改值！
		x += lowbit(x);
	}
}

int sum_BIT(int x) {	// 查询前缀和：返回前缀和sum[x]
	int ans = 0;
	while (x > 0) {
		ans += tree[x];
		x -= lowbit(x);
	}
	return ans;
}
// ----------- 基本编码 end ------------




void main_Binary_Indexed_Tree() {

}