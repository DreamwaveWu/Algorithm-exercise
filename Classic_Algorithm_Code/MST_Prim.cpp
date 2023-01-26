#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>


static const int N = 5005, M = 2e5+1;
struct edge_Prim {
	int to, w;
	edge_Prim(int a, int b) { to = a, w = b; }
};
static std::vector<edge_Prim>G[M];
struct node_Prim {
	int id, dis;
	node_Prim(int a, int b) { id = a, dis = b; }
	bool operator <(const node_Prim& u) const { return dis > u.dis; }
};

static int n, m;
static bool done[N+1];

void prim(int s) {
	for (int i = 1; i <= N; i++)	done[i] = false;
	std::priority_queue<node_Prim> q;
	q.push(node_Prim(s, 0));
	int ans = 0;
	int cnt = 0;
	while (!q.empty()) {
		node_Prim u = q.top(); q.pop();
		if (done[u.id])		continue;
		done[u.id] = true;
		ans += u.dis;
		cnt++;
		for (int i = 0; i < G[u.id].size(); i++) {
			edge_Prim e = G[u.id][i];
			if (done[e.to])		continue;
			q.push(node_Prim(e.to, e.w));
		}
	}
	if (cnt == n)	std::cout << ans;
	else			std::cout << "orz";
}
 

void main_Prim() {
	std::cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int a, b, w;   std::cin >> a >> b >> w;
		G[a].push_back(edge_Prim(b, w));  G[b].push_back(edge_Prim(a, w));  //双向边
	}
	prim(1);
}