#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

static const int N = 500005;
static int fa[N], head[N], cnt, head_query[N], cnt_query, ans[N];
static bool vis[N];
static struct Edge { int to, next, num; }edge[2 * N], query[2 * N];  //链式前向星


void init_LCA_Tarjan() {              //链式前向星：初始化
	for (int i = 0; i < 2 * N; ++i) {
		edge[i].next = -1;  head[i] = -1;
		query[i].next = -1; head_query[i] = -1;
	}
	cnt = 0; cnt_query = 0;
}


void addedge_LCA_Tarjan(int u, int v) {             //链式前向星：加边
	edge[cnt].to = v;
	edge[cnt].next = head[u];
	head[u] = cnt++;
}


void add_query_LCA_Tarjan(int x, int y, int num) { //num 第几个查询
	query[cnt_query].to = y;
	query[cnt_query].num = num;	   //第几个查询
	query[cnt_query].next = head_query[x];
	head_query[x] = cnt_query++;
}


int find_set_LCA_Tarjan(int x) {	                //并查集查询
	return fa[x] == x ? x : find_set_LCA_Tarjan(fa[x]);
}


void LCA_tarjan(int x) {                    //tarjan是一个DFS
	vis[x] = true;
	for (int i = head[x]; ~i; i = edge[i].next) {   // ~i可以写为i!=-1
		int y = edge[i].to;
		if (!vis[y]) {     //遍历子结点
			LCA_tarjan(y);
			fa[y] = x;      //合并并查集：把子结点y合并到父结点x上
		}
	}
	for (int i = head_query[x]; ~i; i = query[i].next) { //查询所有和x有询问关系的y
		int y = query[i].to;
		if (vis[y])                                   //如果to被访问过
			ans[query[i].num] = find_set_LCA_Tarjan(y);          //LCA就是find(y)
	}
}



void main_LCA_Tarjan() {
	init_LCA_Tarjan();
	memset(vis, 0, sizeof(vis));
	int n, m, root;  scanf("%d%d%d", &n, &m, &root);
	for (int i = 1; i < n; i++) {                //读n个结点
		fa[i] = i;                       //并查集初始化
		int u, v;   scanf("%d%d", &u, &v);
		addedge_LCA_Tarjan(u, v);  addedge_LCA_Tarjan(v, u);     //存边
	}
	fa[n] = n;                           //并查集的结点n
	for (int i = 1; i <= m; ++i) {        //读m个询问
		int a, b; scanf("%d%d", &a, &b);
		add_query_LCA_Tarjan(a, b, i); add_query_LCA_Tarjan(b, a, i);  //存查询
	}
	LCA_tarjan(root);
	for (int i = 1; i <= m; ++i)	printf("%d\n", ans[i]);
}