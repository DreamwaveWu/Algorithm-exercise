#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

/*
【多重背包——二进制拆分优化】
（洛谷 P1776) https://www.luogu.com.cn/problem/P1776

二进制拆分优化的本质是减少物品数量，把最内层循环从 k 次降低到 log k 次
*/



static const int N = 100010;
static int n, C, dp[N];
static int w[N], c[N], m[N], new_w[N], new_c[N], new_m[N];
static int new_n;

void main_Multiple_backpack() {
	std::cin >> n >> C;
	for (int i = 1; i <= n; i++)	std::cin >> w[i] >> c[i] >> m[i];
	int new_n = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m[i]; j <<= 1) {
			m[i] -= j;
			new_c[++new_n] = j * c[i];
			new_w[new_n] = j * w[i];
		}
		if (m[i]) {
			new_c[++new_n] = m[i] * c[i];
			new_w[new_n] = m[i] * w[i];
		}
	}
	for (int i = 1; i <= new_n; i++) {
		for (int j = C; j >= new_c[i]; j--) {
			dp[j] = std::max(dp[j], dp[j - new_c[i]] + new_w[i]);
		}
	}
	std::cout << dp[C] << std::endl;
}