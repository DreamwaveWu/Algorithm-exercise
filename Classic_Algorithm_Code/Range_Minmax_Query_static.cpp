#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

/*
【静态RMQ问题：静态区间最值查询】
【ST算法】	O(nlogn)
（洛谷P2880) https://www.luogu.com.cn/problem/P2880
	dp[s][k]表示左端点为 s，区间长度为 2^k 的区间的最值

	dp[s][k] = min(dp[s][k-1], dp[s+(1<<(k-1))][k-1]
		ans  = min(dp[L][k], dp[R-(1<<k)+1][k]) k = log_2(len)
												  = log_2(R-L+1)
*/

void RMQ_init(int* log, int dp_max[][22], int dp_min[][22], int* a, const int& N, int n) {
	log[0] = -1;
	for (int i = 1; i <= N; i++)		log[i] = log[i >> 1] + 1;
	for (int i = 1; i <= n; i++) {		// 初始化区间长度为 1 的值
		dp_min[i][0] = a[i];
		dp_max[i][0] = a[i];
	}
	int p = log[n];
	for (int k = 1; k <= p; k++) {		// 先算小区间，再算大区间，最大区间长度为 log2(n)
		for (int s = 1; s + (1 << k) <= n + 1; s++) {
			dp_min[s][k] = std::min(dp_min[s][k - 1], dp_min[s + (1 << (k - 1))][k - 1]);
			dp_max[s][k] = std::max(dp_max[s][k - 1], dp_max[s + (1 << (k - 1))][k - 1]);
		}
	}
}

int RMQ_query(int* log, int dp_max[][22], int dp_min[][22], int L, int R) {
	int k = log[R - L + 1];
	int x = std::max(dp_max[L][k], dp_max[R - (1 << k) + 1][k]);
	int y = std::min(dp_min[L][k], dp_min[R - (1 << k) + 1][k]);
	return x - y;
}

void main_Range_Minmax_Query_static() {
	const int N = 500;
	int n, m;
	int a[N], dp_max[N][22], dp_min[N][22];
	int LOG[N+1];

	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)		scanf("%d", &a[i]);
	RMQ_init(LOG, dp_max, dp_min, a, N, n);
	for (int i = 1; i <= m; i++) {
		int L, R;
		scanf("%d%d", &L, &R);
		printf("%d\n", RMQ_query(LOG, dp_max, dp_min, L, R));
	}
}