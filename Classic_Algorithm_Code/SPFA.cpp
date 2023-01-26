#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>


static const int N = 1000, M = 100000;
static int n, m;
static int pre[N];
static int head[N], cnt;
struct { int to, next, w; } edge[M];

void init() {
	for (int i = 0; i < N; i++)		head[i] = -1;
	for (int i = 0; i < M; i++)		edge[i].next = -1;
	cnt = 0;
}
void addEdge(int u, int v, int w) {
	edge[cnt].to = v; edge[cnt].w = w; edge[cnt].next = head[u]; head[u] = cnt++;
}

static int dis[N];
static bool inq[N];
static int Neg[N];

int spfa(int s) {
	memset(Neg, 0, sizeof(Neg));
	Neg[s] = 1;
	for (int i = 1; i <= n; i++) { dis[i] = 0x3f3f3f3f; inq[i] = false; }
	dis[s] = 0;
	std::queue<int> Q;
	Q.push(s);
	inq[s] = true;
	while (!Q.empty()) {
		int u = Q.front();
		Q.pop();
		inq[u] = false;
		for (int i = head[u]; ~i; i = edge[i].next) {
			int v = edge[i].to, w = edge[i].w;
			if (dis[u] + w < dis[v]) {
				dis[v] = dis[u] + w;
				pre[v] = u;
				if (!inq[v]) {
					Q.push(v);
					inq[v] = true;
					Neg[v]++;
					if (Neg[v] > n)	return -1;
				}
			}
		}
	}
	return 0;
}

void print_path_SPFA(int s, int t) {            //打印从s到t的最短路
	if (s == t) { printf("%d ", s); return; }  //打印起点
	print_path_SPFA(s, pre[t]);                 //先打印前一个点
	printf("%d ", t);                      //后打印当前点。最后打印的是终点t
}


void main_SPFA() {
	while (~scanf("%d%d", &n, &m)) {
		init();      //前向星初始化
		if (n == 0 && m == 0) return;
		while (m--) {
			int u, v, w; scanf("%d%d%d", &u, &v, &w);
			addEdge(u, v, w); addEdge(v, u, w);  //双向边
		}
		spfa(1);  //计算起点1到其他所有点的最短路
		printf("%d\n", dis[n]);  //打印从1到n的最短距离
	  //printf("path:"); print_path_SPFA(1,n); printf("\n"); //如有需要，打印从s到t的路径
	}
}