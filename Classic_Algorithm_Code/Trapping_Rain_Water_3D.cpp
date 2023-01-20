#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

/*
【接雨水——3维】
（LeetCode 407）https://leetcode.cn/problems/trapping-rain-water-ii/
（POJ 2227)    https://vjudge.net/problem/POJ-2227
*/

using namespace std;

typedef pair<int, int> pii;

class Solution_Trapping_Rain_Water_3D {
public:
	int trapRainWater(vector<vector<int>>& heightMap) {
		if (heightMap.size() <= 2 || heightMap[0].size() <= 2) {
			return 0;
		}
		int m = heightMap.size();
		int n = heightMap[0].size();
		priority_queue<pii, vector<pii>, greater<pii>> pq;
		vector<vector<bool>> visit(m, vector<bool>(n, false));
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
					pq.push({ heightMap[i][j], i * n + j });
					visit[i][j] = true;
				}
			}
		}

		int res = 0;
		int dirs[] = { -1, 0, 1, 0, -1 };
		while (!pq.empty()) {
			pii curr = pq.top();
			pq.pop();
			for (int k = 0; k < 4; ++k) {
				int nx = curr.second / n + dirs[k];
				int ny = curr.second % n + dirs[k + 1];
				if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visit[nx][ny]) {
					if (heightMap[nx][ny] < curr.first) {
						res += curr.first - heightMap[nx][ny];
					}
					visit[nx][ny] = true;
					pq.push({ max(heightMap[nx][ny], curr.first), nx * n + ny });
				}
			}
		}

		return res;
	}
};



vector<vector<int>> h =
{
	{1,4,3,1,3,2},
	{3,2,1,3,2,4},
	{2,3,3,2,3,1}
};


void main_Trapping_Rain_Water_3D() {
	Solution_Trapping_Rain_Water_3D s = Solution_Trapping_Rain_Water_3D();
	cout << s.trapRainWater(h);
}