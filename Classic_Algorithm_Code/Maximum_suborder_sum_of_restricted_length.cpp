#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

/*
给定数组 n 和一个限制长度 m， 求一段长度不超过 m 的连续子序列，使它的和最大
*/

/*
（1）求前缀和
（2）找出两个差值不超过 m 的位置，使前缀和的差最大
（3）DP+单调队列。每分析一个元素，它只有两种情况可能构成答案：
				它本身、它减去队列中的最小元素
（4）去尾：把所有比新元素大的都去掉
	删头：队头超出 m 范围都去掉（注：这里也用到了性质——旧元素即离时仍在队中则必为队头）
*/

void main_Maximum_suborder_sum_of_restricted_length() {
	std::deque<int> dq;
	int s[10000];	// 原数组及前缀和，技巧，降低空间复杂度
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &s[i]);
	}
	for (int i = 1; i <= n; i++) {
		s[i] += s[i - 1];
	}
	int ans = (int)-1e8;	// 基础最值，注意是 -1e8 不是 -1，因为数组元素可能是负值
//	dq.push_back(0);
	for (int i = 1; i <= n; i++) {
		while (!dq.empty() && dq.front() < i - m) {	// 没有等号，因为窗口大小为 m+1
			dq.pop_front();	// 删头
		}
		if (dq.empty())	ans = std::max(ans, s[i]);
		else			ans = std::max(ans, s[i] - s[dq.front()]);
		while (!dq.empty() && s[i] <= s[dq.back()]) {
			dq.pop_back();	// 去尾
		}
		dq.push_back(i);
		/*
		* 为什么先删头后去尾？因为 s[i] 要先和队头比较、更新ans再入队
		*/
	}
	printf("%d\n", ans);
}