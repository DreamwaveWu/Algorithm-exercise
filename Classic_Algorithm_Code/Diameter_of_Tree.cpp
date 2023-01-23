#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

/*
------- 树的直径 --------
	dp[u] 表示以 u 为根节点的子树上，从 u 出发能到达的最远路径长度，这个路径的终点是叶节点。
	f[u] 表示经过 u 的最长路径长度。
	f[u] = max{ dp[u]+dp[v_i]+edge(u,v_i) }
			其中 dp[u] 不包括 v_i 这棵子树
*/



static const int N = 1000;
static struct edge { int to, w; };
static std::vector<edge> e[N];	// 邻接链表
static int dp[N];
static int maxlen = 0;	// 初值为 0
static bool vis[N];


void dfs_Diameter_of_Tree(int u) {
	vis[u] = true;
	for (int i = 0; i < e[u].size(); i++) {	// u 的邻接点
		int v = e[u][i].to, w = e[u][i].w;
		if (vis[v])		continue;
		dfs_Diameter_of_Tree(v);
		maxlen = std::max(maxlen, dp[u] + dp[v] + w);	// 先更新 maxlen
							//	此时 dp[u] 不包含子树 v
		dp[u] = std::max(dp[u], dp[v] + w);				// 再更新 dp[u]
	}
}

void main_Diameter_of_Tree() {
	int n;
	std::cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b, w;
		std::cin >> a >> b >> w;
		e[a].push_back({ b,w });
		e[b].push_back({ a,w });
		dfs_Diameter_of_Tree(1);
		std::cout << maxlen << std::endl;
	}
}