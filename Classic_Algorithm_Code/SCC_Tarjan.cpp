#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>


static const int N = 10005;
static int cnt;
static int low[N], num[N], dfn;
static int scc[N];
static std::stack<int> stack;
static std::vector<int> G[N];	// 邻接链表



void dfs_SCC_Tarjan(int u) {
	stack.push(u);				// 每开始搜索一个点就立即入队
	low[u] = num[u] = ++dfn;		// 初始化
	for (int i = 0; i < G[u].size(); i++) {
		int v = G[u][i];
		if (!num[v]) {		// 未访问过的点，v是白色，继续dfs
			dfs_SCC_Tarjan(v);
			low[u] = std::min(low[v], low[u]);	// 更新自己的 low
		}
		else if (!scc[v]) {		// 回退边，v是灰色
			low[u] = std::min(low[u], num[v]);	// 更新自己的 low
		}
	}
	if (low[u] == num[u]) {		// 自己是这个 SCC 的入口点
		cnt++;					// 新找到一个 SCC ，进行编号
		while (1) {				// 将该 SCC 的点出栈
			int v = stack.top();
			stack.pop();
			scc[v] = cnt;
			if (v == u) {		// 直到自己最后一个出栈
				break;
			}
		}
	}
}



void main_SCC_Tarjan() {
	int n, m, u, v;
	while (scanf("%d%d", &n, &m), n != 0 || m != 0) {
		for (int i = 1; i <= n; i++) { G[i].clear(); }
		for (int i = 0; i < m; i++) {
			scanf("%d%d", &u, &v);
			G[u].push_back(v);
		}
		cnt = 0;	// SCC 序号
		dfn = 0;	// DFS 序号
		memset(scc, 0, sizeof(scc));
		memset(num, 0, sizeof(num));
		memset(low, 0, sizeof(low));
		for (int i = 1; i <= n; i++) {
			if (!num[i]) {
				dfs_SCC_Tarjan(i);
			}
		}
		printf("%s\n", cnt == 1 ? "Yes" : "No");
	}                                                                                                   
}