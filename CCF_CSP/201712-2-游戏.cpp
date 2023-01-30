#include<bits/stdc++.h>
using namespace std;

/*
千万不要用 bool v[1005] = { true }; 的方式初始化！
千万不要用 bool v[1005] = { true }; 的方式初始化！
千万不要用 bool v[1005] = { true }; 的方式初始化！
*/


int main() {
	bool v[1005];
	memset(v, true, sizeof(v));
	int n, k;
	scanf("%d%d", &n, &k);
	int cnt = n;
	int x = 1, i = 0;	// x 是数， i 是小朋友
	while (cnt > 1) {
		while (!v[i]) {
			i = (i + 1) % n;
		}
		if (x % k == 0 || x % 10 == k)	{
			v[i] = false;
			cnt--;
		}
		x++;
		i = (i + 1) % n;
	}
	for (int i = 0; i < n; i++) {
		if (v[i]) {
			printf("%d", i + 1);
			break;
		}
	}
	return 0;
}
