#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>


/*
---------- 【 四 边 形 优 化 】 ----------
【环形石子合并】
（洛谷 P1880) https://www.luogu.com.cn/problem/solution/P1880
*/


using namespace std;
static int cnt[210], s[210][210], dp[210][210], n, temp, te, dp2[210][210], maxn, minn;

void main_DP_quadrangle_inequality() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &cnt[i]);
		cnt[i] += cnt[i - 1];
		s[i][i] = i;
		s[i + n][i + n] = i + n;
	}
	for (int i = 1; i <= n; i++)
		cnt[i + n] = cnt[i] + cnt[n];
	for (int i = n * 2; i >= 1; i--)
		for (int j = i + 1; j <= n * 2; j++)	//参考第1点
		{
			temp = 0x7fffffff;
			dp2[i][j] = max(dp2[i + 1][j], dp2[i][j - 1]) + cnt[j] - cnt[i - 1]; //参考第2点
			for (int k = s[i][j - 1]; k <= s[i + 1][j]; k++)
			{
				if (temp > dp[i][k] + dp[k + 1][j] + cnt[j] - cnt[i - 1])
				{
					temp = dp[i][k] + dp[k + 1][j] + cnt[j] - cnt[i - 1];
					te = k;
				}
			}
			dp[i][j] = temp;
			s[i][j] = te;
		}
	minn = 0x7fffffff;
	for (int i = 1; i <= n; i++)
	{
		minn = min(minn, dp[i][i + n - 1]);
		maxn = max(maxn, dp2[i][i + n - 1]);
	}
	printf("%d\n%d", minn, maxn);
}