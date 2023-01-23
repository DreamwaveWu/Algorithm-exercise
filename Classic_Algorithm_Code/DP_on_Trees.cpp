#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

/*
-------- 【 树 形 D P 】 --------
（洛谷 P2015) https://www.luogu.com.cn/problem/P2015

dp[u][j] 表示以节点 u 为根的子树上留 j 条边时的最多苹果数量

树形DP的特征：
	按照子树的顺序进行递推，在递推第 i 棵子树时，只基于前 i-1 棵子树的情况及第 i 棵子树的dfs情况。
	只有在递推到最后一棵子树时，才可以综合全局得到最终结果。

	且需要注意记录 father 防止回溯。
*/

static const int N = 200;
struct node {
	int v, w;
	node(int v = 0, int w = 0) :v(v), w(w) {}
};
static std::vector<node> edge[N];
static int dp[N][N], sum[N];
static int n, q;


void dfs_DP_on_Trees(int u, int father) {
	for (int i = 0; i < edge[u].size(); i++) {
		int v = edge[u][i].v, w = edge[u][i].w;
		if (v == father)	continue;
		dfs_DP_on_Trees(v, u);
		sum[u] += sum[v] + 1;
		for (int j = sum[u]; j >= 0; j--) {
			for (int k = 0; k <= j - 1; k++) {
				dp[u][j] = std::max(dp[u][j], dp[u][j - k - 1] + dp[v][k] + w);
			}
		}
	}
}


void main_DP_on_Trees() {
	scanf("%d%d", &n, &q);
	for (int i = 1; i < n; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		edge[u].push_back(node(v, w));
		edge[v].push_back(node(u, w));
	}
	dfs_DP_on_Trees(1, 0);
	printf("%d\n", dp[1][q]);
}