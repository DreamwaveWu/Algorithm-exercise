#include<bits/stdc++.h>


/*
这道题使用差分数组。
对于每一个输入的 t 和 c，只要在 [t-k,t-(c-1)-k] 内做了核酸，就符合。这就形成了一个区间。
对于每一个查询 q ，输出的就是在这个点上区间的数量。
*/


using namespace std;
int a[200005];	// 注意范围
int main() {
	int n, m, k;
	memset(a, 0, sizeof(a));
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; i++) {
		int t, c;
		scanf("%d%d", &t, &c);
		a[t - c - k + 1 >= 0 ? t - c - k + 1 : 0] += 1;		// 特别注意小于 0 时的处理
		a[t - k + 1 >= 0 ? t - k + 1 : 0] -= 1;
	}
	for (int i = 1; i < 200005; i++) {
		a[i] += a[i - 1];
	}
	for (int i = 0; i < m; i++) {
		int t;
		scanf("%d", &t);
		printf("%d\n", a[t]);
	}
	return 0;
}
