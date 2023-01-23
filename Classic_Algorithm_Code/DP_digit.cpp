#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

/*
-------- 【 数 位 统 计 D P 】 --------
（洛谷 P2602）https://www.luogu.com.cn/problem/P2602
*/

/*
（1）dp[pos][sum]表示：最后 pos 位不限范围、前面 now 的个数为 sum 时，数字 now 的总个数。
（2）lead 表示是否有前导0。
（3）limit 表示是否有数位限制。

*/



typedef long long ll;
static const int N = 15;
static ll dp[N][N];
static int num[N], now;

/**
 * @brief 
 * @param pos	 正在分析从右往左数的第 pos 位
 * @param sum	 前面的 now 的个数
 * @param lead	 是否有前导0
 * @param limit  是否有数位限制
 * @return 
*/
ll dfs_DP_digit(int pos, int sum, bool lead, bool limit) {
	ll ans = 0;		// 存储最终结果
	if (pos == 0)	return sum;		//	递归到 0 位数。最后有0位、前面2的个数为sum时，数字2的总个数为sum。
	if (!lead && !limit && dp[pos][sum] != -1)
		return dp[pos][sum];
	int up = (limit ? num[pos] : 9);	// 当前位置的最大值。只有在存在数位限制时，up与输入有关。
	for (int i = 0; i <= up; i++) {
		if (i == 0 && lead)
			ans += dfs_DP_digit(pos - 1, sum, true, limit && i == up);
		else if (i == now)
			ans += dfs_DP_digit(pos - 1, sum + 1, false, limit && i == up);
		else if (i != now)
			ans += dfs_DP_digit(pos - 1, sum, false, limit && i == up);
	}
	if (!lead && !limit)	dp[pos][sum] = ans;
	return ans;
}


ll solve_DP_digit(ll x) {
	int len = 0;
	while (x) {
		num[++len] = x % 10;
		x /= 10;
	}
	memset(dp, -1, sizeof(dp));
	return dfs_DP_digit(len, 0, true, true);
}


void main_DP_digit() {
	ll a, b;
	std::cin >> a >> b;
	for (int i = 0; i < 10; i++) {
		now = i;
		std::cout << solve_DP_digit(b) - solve_DP_digit(a - 1) << " ";
	}
}