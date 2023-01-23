#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

/*
------ 倍增法求 LCA -------
（洛谷 P3379） https://www.luogu.com.cn/problem/P3379

	fa[x][i] = fa[fa[x][i - 1]][i - 1]

*/


static const int N = 500005;
static struct Edge { int to, next; }edge[2 * N];
static int head[2 * N];
static int cnt;

void init_LCA_binary_lifting() {	// 链式前向星 初始化
	for (int i = 0; i < 2 * N; i++) { edge[i].next = -1; head[i] = -1; }
	cnt = 0;
}

void addEdge_LCA_binary_lifting(int u, int v) {
	edge[cnt].to = v; edge[cnt].next = head[u]; head[u] = cnt++;
}

static int fa[N][20];
static int deep[N];		// 根节点的深度为 1


/**
 * @brief 求 x 的深度 deep[x] 和 fa[x][]，father 是 x 的父节点
*/
void dfs_LCA_binary_lifting(int x, int father) {
	deep[x] = deep[father] + 1;			// 首先，计算 x 的深度
	fa[x][0] = father;					// 首先，赋值 fa[x][0]
	for (int i = 1; (1 << i) <= deep[x]; i++) {
		// 计算 fa[x][]，需满足 2^i <= deep[x]
		fa[x][i] = fa[fa[x][i - 1]][i - 1];
	}
	for (int i = head[x]; ~i; i = edge[i].next) {
		if (edge[i].to != father) {
			dfs_LCA_binary_lifting(edge[i].to, x);
		}
	}
}


int LCA_binary_lifting(int x, int y) {
	if (deep[x] < deep[y])		std::swap(x, y);	// 让 x 位于更底层
	// 首先，把 x 和 y 提到相同的深度
	for (int i = 19; i >= 0; i--) {				// 先迈大步子，再小步走
		if (deep[x] - (1 << i) >= deep[y]) {	// 确保不会跳得比 y 高
			x = fa[x][i];
		}
	}
	if (x == y)		return x;		// y 就是 x 的祖先
	// 此时，y 不是 x 的祖先，二者同步往上跳，直到相遇
	for (int i = 19; i >= 0; i--) {
		if (fa[x][i] != fa[y][i]) {
			x = fa[x][i];
			y = fa[y][i];
		}
	}
	return fa[x][0];	// 跳到最后，x 位于 LCA 的下一层
}


void main_LCA_binary_lifting() {
	init_LCA_binary_lifting();
	int n, m, root;
	scanf("%d%d%d", &n, &m, &root);
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		addEdge_LCA_binary_lifting(u, v); addEdge_LCA_binary_lifting(v, u);
	}
	dfs_LCA_binary_lifting(root, 0);
	while (m--) {
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%d\n", LCA_binary_lifting(a, b));
	}
}