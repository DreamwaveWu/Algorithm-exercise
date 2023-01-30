#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
使用差分数组，统计 2 的个数。
注意“时刻”的概念，在前缀和数组中，x[i]=1 代表 i~i+1 的时间段有空，
所以是 x[b]-- 而不是 x[b+1]-- 。

*/


int x[1000005];

int main() {
	int n;
	int a, b;
	scanf("%d", &n);
	n += n;
	memset(x, 0, sizeof(x));
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &a, &b);
		x[a]++;
		x[b]--;
	}
	int cnt = 0;
	for (int i = 1; i <= 1000005; i++) {	// 注意是 i <= N , 不是 n
		x[i] += x[i - 1];
		if (x[i] == 2)	{
			cnt++;
		}
	}
	printf("%d", cnt);
	return 0;
}
