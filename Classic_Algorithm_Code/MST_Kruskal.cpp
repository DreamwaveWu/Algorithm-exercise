#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

static const int N = 5005, M = 2e5 + 1;
struct Edge_Kruskal { int u, v, w; }edge[M];
bool cmp_Kruskal(Edge_Kruskal a, Edge_Kruskal b) { return a.w < b.w; };
static int s[N];	// 并查集
static int n, m;

int find_set_Kruskal(int x) {
	if (x != s[x])	s[x] = find_set_Kruskal(s[x]);
	return s[x];
}

void kruskal() {
	std::sort(edge + 1, edge + m + 1, cmp_Kruskal);
	for (int i = 1; i <= n; i++)	s[i] = i;
	int ans = 0;
	int cnt = 0;
	for (int i = 1; i <= m; i++) {	// 从小到大遍历每一条边。全过程中边的数组是静态的。
		if (cnt == n - 1)	break;	// 直到已经确定 n-1 条边
		int x = find_set_Kruskal(edge[i].u);
		int y = find_set_Kruskal(edge[i].v);
		if (x == y)		continue;
		ans += edge[i].w;
		cnt++;
		s[x] = y;
	}
	if (cnt == n - 1)	std::cout << ans;
	else std::cout << "orz";	// 图不连通
}

void main_Kruskal() {
	std::cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		std::cin >> edge[i].u >> edge[i].v >> edge[i].w;
	}
	kruskal();
}