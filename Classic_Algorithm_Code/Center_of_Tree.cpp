#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

/*
------【树的重心】------

【性质（1）】某个点是树的重心 等价于 它的最大子树 不大于 整棵树大小的一半。
		// 说明：此处的“最大子树”，是将该点作为树的根。
		// 如果在 DFS 的过程中默认根不变，那么“最大子树”就要替换成“最大连通子块”	
【性质（2）】树至多有两个重心。如果树有两个重心，那么它们相邻。
		   此时树一定有偶数个节点，且可以被划分为两个大小相等的分支，每个分支各自包含一个重心。
【性质（3）】树中所有点到某个点的距离和中，到重心的距离和是最小的；
		   如果有两个重心，那么到它们的距离和一样。反过来，距离和最小的点一定是重心。
【性质（4）】往树上增加或减少一个叶子，
			如果原节点数是奇数，那么重心可能增加一个，原重心仍是重心；
			如果原节点数是偶数，重心可能减少一个，另一个重心仍是重心。
【性质（5）】把两棵树通过一条边相连得到一棵新的树，则新的重心在较大的一棵树一侧的连接点与原重心之间的简单路径上。
			如果两棵树大小一样，则重心就是两个连接点。
*/



static const int MAXN = 1000;
static struct { int to, next; }edges[MAXN];
static int head[MAXN];
static int n, sz[MAXN], mss[MAXN];
// n：总结点数（请从外部传入），sz：树的大小，mss：最大子树大小
static std::vector<int> ctr; // 存储重心，不超过两个


void dfs_Center_of_Tree(int p, int fa = 0) // 找重心
{
	sz[p] = 1;	// sz是以 p 为根结点的子树的大小，由于需要包含自身，此处需要 +1
	mss[p] = 0;	// mss[p] 是以 p 为划分点的 最大连通块的大小
				// 它分为两个部分：p 的子树（通过DFS计算）、另一边的连通块（通过减法计算）
	for (int i = head[p]; ~i; i = edges[i].next) {
		int to = edges[i].to;
		if (to != fa)	// 跳过父节点
		{
			dfs_Center_of_Tree(to, p);			// 首先递归子节点
			mss[p] = std::max(mss[p], sz[to]);	// 最大子树大小
			sz[p] += sz[to];	//	以 p 为根的子树的节点数量（含自身）
		}
	}
	mss[p] = std::max(mss[p], n - sz[p]);	// 最大子树 vs 另一边的连通块
	if (mss[p] <= n / 2) ctr.push_back(p);	// 重心的充分必要条件
}



void main_Center_of_Tree() {

}