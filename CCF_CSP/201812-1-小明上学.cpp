#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll r, yellow, g;
	scanf("%lld%lld%lld", &r, &yellow, &g);
	int n;
	scanf("%d", &n);
	ll ans = 0;
	int x;
	long long y;
	for (int i = 0; i < n; i++) {
		scanf("%d%lld", &x, &y);
		if (x == 0)	ans += y;
		else if (x == 1)	ans += y;
		else if (x == 2) 	ans += (y + r);
	}
	printf("%lld",ans);
	return 0;
}
