#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

/*
-------- 【 状 态 压 缩 D P 】 --------
（以最短 Hamilton 路径为例）
（AcWing 91） https://www.acwing.com/problem/content/93/
（洛谷 P1433) https://www.luogu.com.cn/problem/P1433
*/


/*
dp[S][j]表示从起点0出发，经过S中的所有点，到达终点j时的最短路径（j必须在S中）
dp[S][j] = min{dp[S-j][k] + dist(k,j)}, k \in S-j
*/

static int n, dp[1 << 20][21];
static int dist[21][21];

void main_DP_on_Subsets() {
	// 本代码中，起点为点0，对应的S=1
	memset(dp, 0x3f, sizeof(dp));	// 初始化为最大值
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &dist[i][j]);
		}
	}
	dp[1][0] = 0;	// S=1,j=0,表示集合中只有点0，且起点和终点都是点0
	for (int S = 1; S < (1 << n); S++) {	// S 的最大值为 (1<<n)-1
		for (int j = 0; j < n; j++) {	// 枚举终点
			if ((S >> j) & 1) {		// j 必须在 S 中
				for (int k = 0; k < n; k++) {	// 枚举中间点
					if ((S ^ (1 << j)) >> k & 1) {	// k 必须在 S 中
						dp[S][j] = std::min(dp[S][j], dp[S ^ (1 << j)][k]+dist[k][j]);
					}
				}
			}
		}
	}
	std::cout << dp[(1 << n) - 1][n - 1];
}