#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

/*
【奇偶剪枝/奇偶判断】
（HDU 1010)

奇偶判断的本质是：
	方格棋盘内的任意两个点，
	它们的（曼哈顿距离）和任意（其它路径距离）的（奇偶性）必然一致
	因此这两个距离的差值 必为偶数
	如果给定两个点的位置，可以计算它们的曼哈顿距离
	再给定步数 T ，这就是其他路径距离
	二者作差，结果为奇数则剪枝

第二次剪枝：
	可行性剪枝。当前走了 k 步，当前位置离终点的曼哈顿距离为 s
	如果 k+s>t，那么必然无法抵达，剪枝
*/


static char mat[8][8], visit[8][8];
static int n, m, t;
static int flag;
static int a, b, c, d;
static int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
#define CHECK(xx,yy) (xx>=0&&xx<n&&yy>=0&&yy<m)

void DFS_Pruning_odd_even(int x, int y, int time) {
	// time 表示当前已走的步数
	if (flag)	return;		// 已确认可行，无需继续搜索路径
	if (mat[x][y] == 'D') {
		if (time == t)	flag = 1;	// 确认可行
		return;
	}
	if ((t - time - abs(c - x) - abs(d - y) < 0))	return;	// 第二次剪枝
	for (int i = 0; i < 4; i++) {
		int nx = x + dir[i][0], ny = y + dir[i][1];
		if (CHECK(nx, ny) && mat[nx][ny] != 'X' && !visit[nx][ny]) {
			visit[nx][ny] = 1;	// 对于需要回溯的 dfs ，vis 放在此处
			DFS_Pruning_odd_even(nx, ny, time + 1);
			visit[nx][ny] = 0;
		}
	}
	return;
}


void main_Pruning_odd_even() {
	while (~scanf("%d%d%d", &n, &m, &t)) {
		if (n == 0 && m == 0 && t == 0)	break;	// 输入结束
		for (int i = 0; i < n; i++) {	// 读入地图
			for (int j = 0; j < m; j++) {
				std::cin >> mat[i][j];
				if (mat[i][j] == 'S')	a = i, b = j;	// 起点
				if (mat[i][j] == 'D')	c = i, d = j;	// 终点
			}
		}
		memset(visit, 0, sizeof(visit));
		int tmp = t - std::abs(c - a) - std::abs(d - b);
		if ((tmp & 1)) {	// 奇偶判断
			puts("NO");
			continue;
		}
		flag = 0;	// 通过奇偶判断，进行搜索
		visit[a][b] = 1;
		DFS_Pruning_odd_even(a, b, 0);
		if (flag) puts("YES");
		else	  puts("NO");
	}
}