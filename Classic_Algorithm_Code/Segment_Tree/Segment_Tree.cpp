#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

/*
-------------- < 线段树 > ---------------
			 Segment  Tree

【基本功能】区间最值问题、区间和问题
【时间复杂度】O(nlogn)

● 线段树可以理解为：“分治 + 二叉树 + Lazy-Tag”

● 线段树的基本特征：
（1）用分治法自顶向下建立，每次分治，左右子树各一半。
（2）每个节点都表示一个“线段”区间，非叶子节点包含多个元素，叶子节点只有一个元素。
（3）除了最后一层，其它层都是满的。
（4）每个节点的值，代表了以它为根的子树上所有节点的值（区间和、最值等等）。

● 考察每个线段[L,R]：
（1）L=R，它是一个叶结点
（2）L < R，左儿子区间为 [L,M]，右儿子区间为[M+1,R]，其中 M=(L+R)/2

● 【 构 造 】
（1）可以直接用数组表示二叉树，需要 N*4 的空间
（2）ls = p<<1、rs = p<<1|1，也即 p*2、p*2+1
（3）build()采用递归，递归左儿子、右儿子之后，调用push_up()从下往上传递区间的值

● 【 查 询 】
（1）查询区间最值：每个节点上的数字对应子树（含自身）的最值。递归查询子区间。
（2）查询区间和：每个节点上的数据对应这课子树（含自身）的和。
（3）区间查询方式：
	（3.1）[L,R] 完全覆盖了当前节点的范围，直接返回当前节点的值
	（3.2）[L,R] 与当前节点部分重叠，计算 M，分别递归搜索左右子节点

● 【 修 改 】
（1）update() 只深入到完全覆盖的区间节点，并打上 tag 标记
（2）遇到冲突时才调用传递函数 push_down()，将 tag 标记传递给左右子树

● 【 模 板 题 】
（洛谷 P3372） https://www.luogu.com.cn/problem/P3372
（洛谷 P3373） https://www.luogu.com.cn/problem/P3373
*/

typedef long long type;
static const type N = 1000;
static type a[N];
static type tree[N << 2];
static type tag[N << 2];
type ls(type p) { return p << 1; }
type rs(type p) { return p << 1 | 1; }

void push_up(type p) {	// 从下向上传递区间的值
	tree[p] = tree[ls(p)] + tree[rs(p)];
	// tree[p] = std::min(tree[ls(p)], tree[rs(p)]);
}

void build(type p, type pl, type pr) {
	// 建树，节点为 p，它指向区间 [pl,pr]
	tag[p] = 0;		// 初始化 Lazy-Tag 标记
	if (pl == pr) { tree[p] = a[pl]; return; }	// 递归处理到叶子节点
	type mid = (pl + pr) >> 1;		// 分治：折半 M
	build(ls(p), pl, mid);			// 递归左儿子
	build(rs(p), mid + 1, pr);		// 递归右儿子
	push_up(p);		// 根据儿子的值更新自己的值
}

void addtag(type p, type pl, type pr, type d) {
	// 给本节点打上 tag 标记，并更新本节点的值
	tag[p] += d;
	tree[p] += d * (pr - pl + 1);
}

void push_down(type p, type pl, type pr) {	// 将 tag 传递给子树
	if (tag[p]) {
		type mid = (pl + pr) >> 1;
		addtag(ls(p), pl, mid, tag[p]);		// 左子树
		addtag(rs(p), mid + 1, pr, tag[p]);	// 右子树
		tag[p] = 0;		// 清零自身的 tag
	}
}

/**
 * @brief
 * @param L	 区间修改左端点，在递归时不改变
 * @param R  区间修改右端点，在递归时不改变
 * @param p  当前处理的节点 p
 * @param pl 当前处理的节点的区间左端点
 * @param pr 当前处理的节点的区间右端点
 * @param d  区间修改的值（默认为增加d）
*/
void update(type L, type R, type p, type pl, type pr, type d) {
	if (L <= pl && R >= pr) {
		addtag(p, pl, pr, d);
		return;
	}
	push_down(p, pl, pr);	// 递归之前进行 down
	type mid = (pl + pr) >> 1;
	if (L <= mid)		update(L, R, ls(p), pl, mid, d);
	if (R > mid)		update(L, R, rs(p), mid + 1, pr, d);
	push_up(p);				// 递归之后进行 up
}

type query(type L, type R, type p, type pl, type pr) {
	// 查询 [L,R] ，p 是当前节点，pl、pr 是当前节点 p 表示的线段区间
	if (L <= pl && R >= pr)	return tree[p];	// 完全覆盖，直接返回
	push_down(p, pl, pr);					// 不能覆盖，递归子树
	type res = 0;
	type mid = (pl + pr) >> 1;
	if (L <= mid)	res += query(L, R, ls(p), pl, mid);
	if (R > mid)	res += query(L, R, rs(p), mid + 1, pr);
	return res;
}


void main_Segment_Tree() {
	// 洛谷 P3372，已通过评测
	type n, m;
	scanf("%lld%lld", &n, &m);
	for (type i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	build(1, 1, n);		// 建树
	while (m--) {
		type q, L, R, d;
		scanf("%lld", &q);
		if (q == 1) {
			scanf("%lld%lld%lld", &L, &R, &d);
			update(L, R, 1, 1, n, d);
		}
		else {
			scanf("%lld%lld", &L, &R);
			printf("%lld\n", query(L, R, 1, 1, n));
		}
	}
}