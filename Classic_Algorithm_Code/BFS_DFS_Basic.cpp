#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

/*
【连通性判断/岛屿计数问题】
https://www.lanqiao.cn/problems/178/learning/

上、下、左、有 4 个方向上连在一起的一片陆地组成一座岛屿
如果一块陆地像素与海洋相邻，它就会被淹没
计算有多少座岛屿会被完全淹没

在本题中，保证最外面一圈都是海洋
*/

/*
每搜索一个岛屿，都用 flag 标注该岛屿是否会被完全淹没
*/

static const int N = 1010;
static char map[N][N];
static int vis[N][N] = { 0 };
static int d[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int flag;


void Basic_DFS(int x, int y) {
	vis[x][y] = 1;
	if (flag == 0 && map[x][y + 1] == '#' && map[x][y - 1] == '#'
		&& map[x - 1][y] == '#' && map[x + 1][y] == '#') {
		flag = 1;	// 此岛屿不会被淹没
	}
	for (int i = 0; i < 4; i++) {
		int next_x = x + d[i][0], next_y = y + d[i][1];
		if (!vis[next_x][next_y] && map[next_x][next_y] == '#') {
			Basic_DFS(next_x, next_y);
		}
	}
}



void Basic_BFS(int x, int y) {
	std::queue<std::pair<int, int>> q;
	q.push({ x,y });
	vis[x][y] = 1;
	while (!q.empty()) {
		std::pair<int, int> t = q.front();
		q.pop();
		int tx = t.first, ty = t.second;
		if (flag == 0 && map[tx][ty + 1] == '#' && map[tx][ty - 1] == '#'
			&& map[tx - 1][ty] == '#' && map[tx + 1][ty] == '#') {
			flag = 1;
		}
		for (int i = 0; i < 4; i++) {
			int next_x = tx + d[i][0], next_y = ty + d[i][1];
			if (!vis[next_x][next_y] && map[next_x][next_y] == '#') {
				q.push({ next_x,next_y });
				vis[next_x][next_y] = 1;
			}
		}
	}
}





void main_BFS_DFS_Basic() {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> map[i];
	}
	int ans = 0;	// 统计被淹没的岛屿数量，即 flag == 0
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			if (map[i][j] == '#' && !vis[i][j]) {
				flag = 0;
				// Basic_DFS(i, j);
				Basic_BFS(i, j);
				if (flag == 0)		ans++;
			}
		}
	}
	std::cout << ans << std::endl;
}
