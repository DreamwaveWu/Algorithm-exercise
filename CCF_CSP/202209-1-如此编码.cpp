#include <bits/stdc++.h>

int main() {
	int n, m;
	int a[21];
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)	scanf("%d", &a[i]);
	int cold = 1, cnew = 1;
	int mod = 1;
	int ans= 0;
	for (int i = 1; i <= n; i++) {
		cnew *= a[i];
		mod = (m % cnew);
		printf("%d ", (mod - ans) / cold);
		ans = mod;
		cold = cnew;
	}
	return 0;
}