#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

static int G[510][510];
static int match[510], reserve_boy[510];     //匹配结果在match[]中
static int n, m;

bool dfs_Hungarian(int x) {                      //找一个增广路径，即给女孩x找一个配对男孩
	for (int i = 1; i <= m; i++)
		if (!reserve_boy[i] && G[x][i]) {
			reserve_boy[i] = 1;      // 预定男孩i，准备分给女孩x
			if (!match[i] || dfs_Hungarian(match[i])) {
				//有两种情况：(1)如果男孩i还没配对，就分给女孩x；
				//            (2)如果男孩i已经配对，尝试用dfs()更换原配女孩，以腾出位置给女孩x
				match[i] = x; //配对成功；如果原来有配对，更换成功。现在男孩i属于女孩x
				return true;
			}
		}
	return false;      //女孩x没有喜欢的男孩，或者更换不成功
}


void main_Hungarian() {
	int e; scanf("%d%d%d", &n, &m, &e);
	while (e--) { int a, b; scanf("%d%d", &a, &b); G[a][b] = 1; }   //矩阵存图
	int sum = 0;
	for (int i = 1; i <= n; i++) {         //为每个女孩找配对
		memset(reserve_boy, 0, sizeof(reserve_boy));
		if (dfs_Hungarian(i))  sum++; //第i个女孩配对成功，这个配对后面可能更换，但是保证她能配对
	}
	printf("%d\n", sum);

}