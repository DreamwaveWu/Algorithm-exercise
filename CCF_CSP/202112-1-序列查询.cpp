#include<bits/stdc++.h>
using namespace std;

/*
找规律：f(i) 就是数组元素的下标（加1），长度就是相邻数组元素的差值。

*/


int main() {
	int n, N;
	int a[205];
	scanf("%d%d", &n, &N);
	for (int i = 0; i < n; i++)	scanf("%d", &a[i]);
	long long ans = 0;
	for (int i = 1; i < n; i++) {
		ans += i * (a[i] - a[i - 1]);
	}
	ans += n * (N - a[n - 1]);
	printf("%lld", ans);
	return 0;
}
