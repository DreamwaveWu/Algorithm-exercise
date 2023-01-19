#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

/*
  【 最大值最小化 】
https://leetcode.cn/problems/split-array-largest-sum/
给定一个非负整数数组 nums 和一个整数 m ，你需要将这个数组分成 m 个非空的连续子数组。
设计一个算法使得这 m 个子数组各自和的最大值最小。

【最小值最大化】见（洛谷P1824）进击的奶牛
https://www.luogu.com.cn/problem/P1824
*/

// 本解法已通过 leetcode 评测

int check(int* a, int x, int n) {
	int sum = 0;
	int count = 1;	// 注意初始值为 1
	for (int i = 1; i <= n; i++) {
		if (sum + a[i] > x) {
			sum = a[i];
			count++;
		}
		else {
			sum += a[i];
		}
	}
	return count;
}


void main_Max_min_split() {
	const int N = 100;
	int n, m, max = -1, sum = 0;
	scanf("%d%d", &n, &m);
	int a[N];
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		max = std::max(max, a[i]);
		sum += a[i];
	}
	int left = max, right = sum, mid;
	int ans = 0;
	while (left <= right) {
		mid = left + ((right - left) >> 1);
		int res = check(a, mid, n);
		if (res < m) {	// 区间数量少，说明每个区间的和多，应往小处搜
			right = mid;
		}
		else if (res > m) {	// 数量多，说明每个区间的和少，应往大处搜
			left = mid + 1;
		}
		else {		// 符合条件，记录答案，往更小处搜索
			ans = mid;
			right = mid;
		}
	}
	ans = (ans == 0) ? left : ans;
	std::cout << ans;
}