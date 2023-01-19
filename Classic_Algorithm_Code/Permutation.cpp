#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

/*
生成 n 的全排列、生成 n 中 任意 m 个数的排列
*/
static int a[20] = { 1,2,3,4,5,6,7,8,9,10,11,12,13 };	// 可根据需求修改
				// 此情况下，a[i] 可用 i+1 代替
static bool vis[20];
static int b[20];

void Permutation_DFS(int s, int  n, int t) {	// t 排列，此时已从左到右考察第 s 个位置（从0开始）
	if (s == t) {	// s 从 0 开始，当 s == t 时，已经考虑了 t 个位置
		for (int i = 0; i < t; i++) {
			printf("%d ", b[i]);
		}
		printf("\n");
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			vis[i] = true;
			b[s] = a[i];
			Permutation_DFS(s + 1, n, t);
			vis[i] = false;
		}
	}
}

void main_Permutation() {
	int n, t;
	std::cin >> n >> t;
	Permutation_DFS(0, n, t);
}