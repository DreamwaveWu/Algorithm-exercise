#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

/*

（洛谷 P3376) https://www.luogu.com.cn/problem/P3376
*/

using namespace std;
#define ll long long
static const ll INF = 1e9;
static int n, m, s, t;
static const int N = 250, M = 11000;              //M定义为边的两倍：双向边
static int cnt = 1, head[N];                     //链式前向星
struct { int from, to, nex, w; } e[M];


void add_ISAP(int u, int v, int w) {
	cnt++;
	e[cnt].from = u;
	e[cnt].to = v;
	e[cnt].w = w;
	e[cnt].nex = head[u];
	head[u] = cnt;
}


static int now[M], pre[M]; //pre[]用于记录路径，pre[i]是路径上点i(的存储位置)的前一个点(的存储位置)
static int dep[M], gap[M]; //dep[i]: 点i的高度；gap[i]:高度为i的点的数量


void bfs_ISAP() {                         //用BFS确定各顶点到汇点的距离
	memset(gap, 0, sizeof(gap));     //初始化间隙数组
	memset(dep, 0, sizeof(dep));    //所有点的高度初始为0
	dep[t] = 1;                    //汇点t的高度是1，其他点的高度都大于1
	queue<int> Q;    Q.push(t);
	while (!Q.empty()) {
		int u = Q.front();    Q.pop();
		gap[dep[u]]++;             //间隙数组：计算高度为dep[u]的结点个数
		for (int i = head[u]; i > 0; i = e[i].nex) {
			int v = e[i].to;       //v是u的邻居点
			if (e[i ^ 1].w && dep[v] == 0) {   //反向边不用处理；高度不等于0的已经处理过了
				dep[v] = dep[u] + 1;
				Q.push(v);
			}
		}
	}
}
ll Augment_ISAP() {               //沿着增广路径更新残留网络
	ll v = t, flow = INF;
	while (v != s) {         //找这个路径的流量
		int u = pre[v];     //u是v向源点s方向回退的上一个点，相当于DFS的回溯 
		if (e[u].w < flow)  flow = e[u].w;      //路径上的最小容量就是这个路径的流量
		v = e[u].from;      //更新v，继续回退
	}
	v = t;
	while (v != s) {         //更新残留网络
		int u = pre[v];      //向源点s方向回退
		e[u].w -= flow;    //正向边
		e[u ^ 1].w += flow;  //反向边。用到了奇偶边的技巧
		v = e[u].from;     //更新v，继续回退
	}
	return flow;           //返回这个路径的流量
}


void ISAP() {
	bfs_ISAP();                //用bfs()求每个点到汇点的距离（高度）
	ll flow = 0;          //计算最大流 
	int u = s;	        //从源点s开始找增广路径
	memcpy(now, head, sizeof(head));  //当前弧优化。now是head的拷贝
	while (dep[s] <= n) {                //最大距离（高度）是n 
		if (u == t) {                    //找到了一条增广路径
			flow += Augment_ISAP();        //更新残留网络，更新流量
			u = s;                    //回到s，重新开始找一条增广路径
		}
		bool ok = 0;                   //用于判断是否能顺利往下走
		for (int i = now[u]; i; i = e[i].nex) {   //在u的邻居中确定路径的下一个点
			int v = e[i].to;                //v是u的邻居点
			if (e[i].w && dep[v] + 1 == dep[u]) { //沿着高度递减的方向找下一个点
				ok = 1;              //顺利找到了路径的下一个点
				pre[v] = i;          //记录路径
				now[u] = i;          //记录当前弧，下一次跳过它
				u = v;               //u更新为路径的下一个点v
				break;               //退出for，回到while循环，继续找路径的下一个点
			}
		}
		if (!ok) {        //路径走不下去了，需要更新u的高度重新走
			if (!--gap[dep[u]]) break;  //u的下一个深度的点没有了，断层了，退出while
			int mindep = n + 10;         //mindep用于计算u的邻居点的最小高度。初值比n大就行
			for (int i = head[u]; i; i = e[i].nex) {   //在u的邻居中找最小的高度
				int v = e[i].to;
				if (dep[v] < mindep && e[i].w)
					mindep = dep[v];
			}
			dep[u] = mindep + 1; //更新u的高度，改为比v大1，从而能够生成一条路径，继续往后走
			gap[dep[u]]++;            //更新间隙数组：高度为dep[u]的结点个数加1
			now[u] = head[u];         //记录当前弧
			if (u != s) u = e[pre[u]].from;     //回退一步，相当于DFS的回溯
		}
	}
	printf("%ld", flow);               //打印最大流
}


void main_MFP_ISAP() {
	scanf("%d%d%d%d", &n, &m, &s, &t);
	for (int i = 1; i <= m; ++i) {
		int u, v, w;   scanf("%d%d%d", &u, &v, &w);
		add_ISAP(u, v, w);  add_ISAP(v, u, 0);         //反向边的初始容量是0
	}
	ISAP();
}