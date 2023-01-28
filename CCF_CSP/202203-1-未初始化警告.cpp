#include<bits/stdc++.h>
using namespace std;


/*
本题直接使用 map 即可，注意常数 a0 的处理。
*/


int main() {
	unordered_map<int, int> map;
	int n, k, ans = 0;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < k; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		if (b != 0 && (map.find(b) == map.end() || map[b] == 0)) ans++;
		map[a] = 1;
	}
	printf("%d", ans);
	return 0;
}
