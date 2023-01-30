#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll r, y, g, all;
	scanf("%lld%lld%lld", &r, &y, &g);
	all = r + y + g;
	int n;
	scanf("%d", &n);
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		int index;
		ll value, tmp = 0;
		scanf("%d%lld", &index, &value);
		if (index == 0)	{
			ans += value;
			//printf("case 1 %lld\n", value);
			continue;
		} else if (index == 1) {
			tmp = (r - value + ans) % all;
		} else if (index == 3) {
			tmp = (r + g - value + ans) % all;
		} else {
			tmp = (all - value + ans) % all;
		}

		if (tmp <= r) {
			ans += (r - tmp);
			//printf("case 2 %lld\n", r - tmp);
		} else if (tmp > r + g) {
			ans += (r + all - tmp);
			//printf("case 3 %lld\n", r + all - tmp);
		}
	}
	printf("%lld", ans);

	return 0;
}
