#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>


/*
	带有路径压缩的并查集算法
*/


static const int N = 1000;
static int fa[N], d[N];

void init_UF() { for (int i = 0; i < N; i++)	fa[i] = i; }

int find_UF(int x) {
	if (x != fa[x])		fa[x] = find_UF(fa[x]);
	return fa[x];
}

//  find 的非递归版本
int find_non_recursion(int x) {
	int r = x, i = x, j;
	while (fa[r] != r)		r = fa[r];	// root 根结点
	while (i != r) {
		j = fa[i];
		fa[i] = r;	// 直接与根结点相连
		i = j;
	}
	return r;
}

void Union_UF(int x, int y) {
	int a = find_UF(x), b = find_UF(y);
	if (a != b)		fa[b] = a;	// 右连左
}





/*
* **********************
	以下为带权值的并查集
* **********************
*/


void init_UF_weight() {
	for (int i = 0; i <= N; i++) {
		fa[i] = i;
		d[i] = 0;
	}

}
int find_UF_weight(int x) {
	if (x != fa[x]) {
		int tmp = fa[x];	 	// 记录父结点 tmp
		fa[x] = find_UF_weight(fa[x]);	// 路径压缩，最后返回的是根结点
		d[x] += d[tmp];			// 权值更新
	}
	return fa[x];
}

void Union_UF_weight(int x, int y, int s) {	// s 是 x 和 y 之间的权值
	int parent_x = find_UF_weight(x);
	int parent_y = find_UF_weight(y);
	if (parent_x != parent_y) {
		fa[parent_x] = parent_y;
		d[parent_x] = d[parent_y] - d[parent_x] + s;
	}
}


void main_Union_Find() {

}