#include<bits/stdc++.h>
using namespace std;

/*
定义结构体，最后排序。
*/


struct p {
	int id;
	long long dis;
} ps[205];

bool cmp(p a, p b) {
	return (a.dis != b.dis) ? a.dis < b.dis : a.id < b.id;
}

int main() {
	int n, X, Y;
	scanf("%d%d%d", &n, &X, &Y);
	int x, y;
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &x, &y);
		ps[i].id = i;
		ps[i].dis = (X - x) * (X - x) + (Y - y) * (Y - y);
	}
	sort(ps + 1, ps + 1 + n, cmp);
	printf("%d\n%d\n%d", ps[1].id, ps[2].id, ps[3].id);
	return 0;
}
