#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

/*
【接雨水——2维】
（LeetCode 42）https://leetcode.cn/problems/trapping-rain-water/
*/

/*
下标 i 处能接的雨水量由 leftMax[i] 和 rightMax[i] 中的最小值决定
如果 height[left] < height[right]，则必有 leftMax < rightMax，
如果 height[left] ≥ height[right]，则必有 leftMax ≥ rightMax
*/

void main_Trapping_Rain_Water_2D() {
	const int N = 100;
	int n, h[N];
	scanf("%d", &n);
	for (int i = 0; i < n; i++)		scanf("%d", &h[i]);
	int left = 1, right = n - 2, leftMax = h[0], rightMax = h[n - 1];
	int ans = 0;
	while (left < right) {
		leftMax = std::max(leftMax, h[left]);
		rightMax = std::max(rightMax, h[right]);
		if (h[left] < h[right]) {
			ans += leftMax - h[left++];
		}
		else {
			ans += rightMax - h[right--];
		}
	}
	std::cout << ans;
}