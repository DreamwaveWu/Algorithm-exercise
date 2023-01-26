#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

/*
【求无向图的割点/割边】

在一个无向图中，从任意点开始做DFS，能访问到所有点，产生一棵“深度优先生成树”。
对无向图G求割点，和这棵生成树T有什么关系？
（1）T 的根节点 s 是 G 的割点，当且仅当 s 有两个或更多子结点
（2）T 的非根节点 u 是 G 的割点，当且仅当 u 存在一个子节点 v ，v 及其后代都没有回退边连回 u 的祖先

下面的例子：POJ 1144
*/


static const int N = 109;
static int low[N], num[N], dfn;
static bool iscut[N];
static std::vector<int> G[N];	// 邻接链表

void dfs_Graph_Cut_point(int u, int fa) {
	low[u] = num[u] = ++dfn;
	int child = 0;	// 统计孩子数目，为判断根节点是否为割点服务
	for (int i = 0; i < G[u].size(); i++) {
		int v = G[u][i];
		if (!num[v]) {
			child++;
			dfs_Graph_Cut_point(v, u);
			low[u] = std::min(low[v], low[u]);	// 更新自己的 low 值
			if (low[v] >= num[u] && u != 1)	iscut[u] = true;
		}
		else if (num[v] < num[u] && v != fa) {	// 回退边，注意到父节点的边不是回退边
			low[u] = std::min(low[u], num[v]);
		}
	}
	if (u == 1 && child >= 2)	iscut[1] = true;	// 特判根节点
}


void main_Graph_Cut_point() {
	int ans, n;
	while (scanf("%d", &n) != -1) {
		if (n == 0)  break;
		memset(low, 0, sizeof(low));
		memset(num, 0, sizeof(num));
		dfn = 0;
		for (int i = 0; i <= n; i++) G[i].clear();
		int a, b;
		while (scanf("%d", &a) && a)
			while (getchar() != '\n') {
				scanf("%d", &b);
				G[a].push_back(b); 	G[b].push_back(a);  //双向边
			}
		memset(iscut, false, sizeof(iscut));
		ans = 0;
		dfs_Graph_Cut_point(1, 1);
		for (int i = 1; i <= n; i++) ans += iscut[i];
		printf("%d\n", ans);
	}
}