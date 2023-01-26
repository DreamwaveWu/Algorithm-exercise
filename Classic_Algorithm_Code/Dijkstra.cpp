#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>


static const int N = 1005, M = 10005;
struct edge_Dijkstra {
	int to, w;
	edge_Dijkstra(int a, int b) { to = a, w = b; }
};
static std::vector<edge_Dijkstra>G[M];
struct node_Dijkstra {
	int id, dis;
	node_Dijkstra(int a, int b) { id = a, dis = b; }
	bool operator <(const node_Dijkstra& u) const { return dis > u.dis; }
};

static int dist[N+1];
static bool done[N+1];

void dijkstra(int s) {
	for (int i = 0; i < N; i++) { dist[i] = 0x3f3f3f3f; done[i] = false; }
	dist[s] = 0;
	std::priority_queue<node_Dijkstra> q;
	q.push(node_Dijkstra(s, dist[s]));
	while (!q.empty()) {
		node_Dijkstra u = q.top();
		q.pop();
		if (done[u.id])		continue;
		done[u.id] = true;
		for (int i = 0; i < G[u.id].size(); i++) {
			edge_Dijkstra e = G[u.id][i];
			if (done[e.to])		continue;
			if (dist[e.to] > u.dis + e.w) {
				dist[e.to] = u.dis + e.w;
				q.push(node_Dijkstra(e.to, dist[e.to]));
			}
		}
	}
}


void main_Dijkstra() {
	int n, m;
	scanf("%d%d", &n, &m);
	while (m--) {
		int from, to, w;
		scanf("%d%d%d", &from, &to, &w);
		G[from].push_back(edge_Dijkstra(to, w));
	}
	int t;
	scanf("%d", &t);
	dijkstra(t);
}