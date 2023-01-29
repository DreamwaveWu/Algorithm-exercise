#include<bits/stdc++.h>
using namespace std;


/*
注意两点：
（1）逗留是“连续”位于矩形内部，所以 cnt 要及时清零。
（2）设置两个 flag 防止重复计数。
*/

int main() {
	int n, k, t, xl, yd, xr, yu;
	scanf("%d%d%d%d%d%d%d", &n, &k, &t, &xl, &yd, &xr, &yu);
	int pass = 0, in = 0;
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		bool flag_pass = false, flag_in = false;
		for (int j = 1; j <= t; j++) {
			int x, y;
			scanf("%d%d", &x, &y);
			if (x >= xl && x <= xr && y >= yd && y <= yu) {
				cnt++;
				if (!flag_pass) {
					pass++;
					flag_pass = true;
				}
				if (cnt == k && !flag_in) {
					in++;
					flag_in = true;
				}
			} else {
				cnt = 0;
			}
		}
	}
	printf("%d\n%d", pass, in);

	return 0;
}
