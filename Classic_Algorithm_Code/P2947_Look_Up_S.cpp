#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
/*
	约翰的 $N(1\le N\le10 ^ 5)$ 头奶牛站成一排，
		奶牛 $i$ 的身高是 $H_i(1\le H_i\le10 ^ 6)$。
	现在，每只奶牛都在向右看齐。
	对于奶牛 $i$，
		如果奶牛 $j$ 满足 $i < j$ 且 $H_i < H_j$，
		我们可以说奶牛 $i$ 可以仰望奶牛 $j$。
	求出每只奶牛离她最近的仰望对象。

	如果没有仰望对象，输出 0。
*/

/*
*	【 单调栈 】
	从后向前遍历奶牛，并用一个栈保存从低到高的奶牛。栈底最高，栈顶最矮。
	每头奶牛的仰望对象是它底下的那头奶牛。在当前奶牛未入队时，那头奶牛就是栈顶。
*/


void main_P2947_Look_Up_S() {
	int h[1000], ans[1000];
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)		scanf("%d", &h[i]);
	std::stack<int> st;
	for (int i = n; i >= 1; i--) {
		while (!st.empty() && h[i] >= h[st.top()])	st.pop();
		if (st.empty())	ans[i] = 0;
		else			ans[i] = st.top();
		st.push(i);
	}
	for (int i = 1; i <= n; i++) {
		printf("%d\n", ans[i]);
	}
}