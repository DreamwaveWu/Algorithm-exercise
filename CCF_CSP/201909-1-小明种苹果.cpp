#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


/*
3 3
73 -8 -6 -4
76 -5 -10 -8
80 -6 -15 0

2 2
10 -3 -1
15 -4 0
*/

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	ll maxc = 0, maxn = 0, all = 0;
	for (int i = 1; i <= n; i++) {
		ll origin, cnt=0;
		scanf("%lld", &origin);
		for (int j = 1; j <= m; j++) {
			ll sub;
			scanf("%lld", &sub);
			cnt += sub;
		}
		all += origin + cnt;
		if (-cnt > maxc) {
			maxc = -cnt;
			maxn = i;
		}
	}
	printf("%lld %lld %lld", all, maxn, maxc);

	return 0;
}
