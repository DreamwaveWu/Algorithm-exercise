#include <bits/stdc++.h>

/*
dp[i] 表示，在体积不超过 i 的前提下，书的最大价值。
也就是说，在所选择的书的价格之和不超过 i 的前提下，可以选择的书的最大价值之和。
*/

int dp[3000001];

int main() {
	int n, x, sum = 0, v;
	scanf("%d%d", &n, &x);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &v);
		sum += v;
		for (int j = sum; j >= v; j--) {
			dp[j] = std::max(dp[j], dp[j - v] + v);
		}
	}
	for (int i = x;; i++) {
		if (dp[i] >= x) {
			printf("%d", dp[i]);
			break;
		}
	}
	return 0;
}