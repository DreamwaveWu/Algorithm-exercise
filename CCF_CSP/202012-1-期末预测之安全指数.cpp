#include<bits/stdc++.h>
using namespace std;


/*
开 long long
*/


int main() {
	int n;
	scanf("%d", &n);
	long long w, s, ans = 0;
	for (int i = 0; i < n; i++) {
		scanf("%lld%lld", &w, &s);
		ans += (w * s);
	}
	ans = ans > 0 ? ans : 0;
	printf("%lld", ans);
	return 0;
}
