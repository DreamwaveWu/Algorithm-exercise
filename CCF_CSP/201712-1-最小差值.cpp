#include<bits/stdc++.h>
using namespace std;

/*
先读入再排序
*/


int main() {
	int n;
	scanf("%d", &n);
	int a[1005];
	int ans = 30000;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a + 1, a + 1 + n);
	for (int i = 2; i <= n; i++) {
		ans = std::min(ans, a[i] - a[i - 1]);
		if (ans == 0)	break;
	}
	printf("%d", ans);
	return 0;
}
