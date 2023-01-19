#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

/*
滑动窗口 /【模板】单调队列 (洛谷 P1886)
【题目描述】
有一个长为 n 的序列 a，以及一个大小为 k 的窗口。
现在这个从左边开始向右滑动，每次滑动一个单位，求出每次滑动后窗口中的最大值和最小值。
*/

/*
（1）删头：如果队头的元素脱离了窗口，这个元素就没用了，去掉它
（2）去尾：如果新元素进队尾是，原队尾的存在破坏了队列的单调性，就弹出它

对本题中删头的说明：如果旧元素在即将离开窗口时仍在队列中，那么它一定是队头。
因此删去脱离窗口的元素时，只需考虑队头。
*/


void main_Sliding_window_extremum() {
	const int N = 1000;
	int a[N];
	std::deque<int> q;
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) {		// 最小值
		while (!q.empty() && a[i] < a[q.back()])		q.pop_back();	// 去尾
		q.push_back(i);
		if (i >= m) {	// 注意此处及下一行的等号
			while (!q.empty() && q.front() <= i - m)	q.pop_front();	// 删头
			printf("%d ", a[q.front()]);
		}
	}
	printf("\n");
	q.clear();
	for (int i = 1; i <= n; i++) {		// 最大值
		while (!q.empty() && a[i] > a[q.back()])		q.pop_back();
		q.push_back(i);
		if (i >= m) {
			while (!q.empty() && q.front() <= i - m)	q.pop_front();
			printf("%d ", a[q.front()]);
		}
	}
}