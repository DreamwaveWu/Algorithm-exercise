#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

/*
【三维差分】
	八个点需要修改：
	笛卡尔坐标系，正方体的左下点为原点，依次根据坐标更改八个顶点

https://www.lanqiao.cn/problems/180/learning/
*/

static const int N = 1000005;
static int A, B, C, n, m;
static int D[N];		//三维差分数组 压维
static int s[N];		//存储舰队生命值
static int x_1[N], y_1[N], z_1[N];		//存储三体人的打击范围
static int x_2[N], y_2[N], z_2[N];		//存储三体人的打击范围
static int d[N];		//存储伤害

//将三维坐标转换为一维
int num(int x, int y, int z) {
	if (x > A || y > B || z > C)return 0;
	return ((x - 1) * B + (y - 1)) * C + (z - 1) + 1;
}


bool check(int x) {
	for (int i = 1; i <= n; i++)D[i] = 0;
	for (int i = 1; i <= x; i++) {		// 空间想象力
		D[num(x_1[i], y_1[i], z_1[i])] += d[i];
		D[num(x_2[i] + 1, y_1[i], z_1[i])] -= d[i];
		D[num(x_1[i], y_2[i] + 1, z_1[i])] -= d[i];
		D[num(x_1[i], y_1[i], z_2[i] + 1)] -= d[i];
		D[num(x_2[i] + 1, y_2[i] + 1, z_1[i])] += d[i];
		D[num(x_2[i] + 1, y_1[i], z_2[i] + 1)] += d[i];
		D[num(x_1[i], y_2[i] + 1, z_2[i] + 1)] += d[i];
		D[num(x_2[i] + 1, y_2[i] + 1, z_2[i] + 1)] -= d[i];
	}
	//将x,y看为定轴 对z进行累加
	for (int i = 1; i <= A; i++) {
		for (int j = 1; j <= B; j++) {
			for (int k = 1; k <= C; k++) {
				D[num(i, j, k + 1)] += D[num(i, j, k)];
			}
		}
	}
	//将x,z看为定轴 对y进行累加
	for (int k = 1; k <= C; k++) {
		for (int i = 1; i <= A; i++) {
			for (int j = 1; j <= B; j++) {
				D[num(i, j + 1, k)] += D[num(i, j, k)];
			}
		}
	}
	//将y,z看为定轴 对x进行累加
	for (int j = 1; j <= B; j++) {
		for (int k = 1; k <= C; k++) {
			for (int i = 1; i <= A; i++) {
				D[num(i + 1, j, k)] += D[num(i, j, k)];
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (D[i] > s[i]) {
			return true;
		}
	}
	return false;
}


void main_3D_difference() {
	std::cin >> A >> B >> C >> m;
	n = A * B * C;
	for (int i = 1; i <= n; i++) std::cin >> s[i];
	for (int i = 1; i <= m; i++) {
		std::cin >> x_1[i] >> x_2[i] >> y_1[i] >> y_2[i] >> z_1[i] >> z_2[i] >> d[i];
	}
	int L = 1;
	int R = m;
	while (L < R) {
		int mid = (L + R) >> 1;		// 第 mid 轮攻击
		if (check(mid))R = mid;
		else L = mid + 1;
	}								// 终止于 L = R
	std::cout << L << std::endl;
}