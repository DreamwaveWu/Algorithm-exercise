#include<bits/stdc++.h>
using namespace std;


/*
使用map即可（用数组模拟）
*/


int main() {
	int n, m, L, x[260], t;
	memset(x, 0, sizeof(x));
	scanf("%d%d%d", &n, &m, &L);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &t);
			x[t]++;
		}
	}
	for (int i = 0; i < L; i++)	printf("%d ", x[i]);


	return 0;
}
