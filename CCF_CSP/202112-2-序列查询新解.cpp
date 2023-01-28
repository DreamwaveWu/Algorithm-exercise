#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
本题仍然以f的取值分为两种情况：
（1）f比g全都小/大，此时不需要分段。只需要注意端点的残余即可。
（2）f比g小、等于、大，此时需要分段。不仅需要注意端点残余，还需要注意左右两段分开处理。
*/


int main() {
	ll n, N;
	ll a[100005];
	memset(a, 0, sizeof(a));
	scanf("%lld%lld", &n, &N);
	for (int i = 1; i <= n; i++)	scanf("%lld", &a[i]);
	a[n + 1] = N;
	ll r = N / (n + 1);
	ll ans = 0;
	for (int i = 0; i <= n; i++) {
		ll L = a[i], R = a[i + 1] - 1;	// 端点坐标
		ll gl = L / r, gr = R / r;	// g(i)
		if (i >= gr || i <= gl) {	// 无需分左右两段
			if (gl == gr)	ans += abs((i - gl) * (R - L + 1));
			else if (gr == gl + 1) {	// 只有端点残余
				ll p = gr * r;
				ans += abs((i - gl) * (p - L)) + abs((i - gr) * (R - p + 1));
			} else {
				ll p2 = gr * r, p1 = (gl + 1) * r;
				ans += abs((p1 - L) * (i - gl)) + abs((i - gr) * (R - p2 + 1));	// 端点残余
				ll left = gl + 1, right = gr - 1, len = right - left + 1;
				if (len != 0)	ans += abs((len * r) * i - ((left + right) * len / 2) * r);	// 中间部分
			}

		} else {
			ll equal = i * r;
			ll p1 = (gl + 1) * r, p2 = gr * r;
			ans += (i - gl) * (p1 - L) + (gr - i) * (R - p2 + 1);	// 端点残余

			ll left = gl + 1, right = i - 1, len = right - left + 1;	// 左部分
			if (len != 0)	ans += (equal - p1) * i - ((left + right) * len / 2) * r;

			left = i + 1, right = gr - 1, len = right - left + 1;		// 右部分
			if (len != 0)	ans +=  (((left + right) * len / 2) * r - (p2 - equal - r) * i);
		}
	}

	cout << ans;

	return 0;
}
