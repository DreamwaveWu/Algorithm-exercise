#include<bits/stdc++.h>
using namespace std;

/*
深刻教训！！！
最后输出的是每一个位置摆放的钥匙的 w
不是每一个 w 摆放的位置！！！

*/


struct t {
	int w;
	int s;
	int e;
} t1[1005], t2[1005];

bool cmp1(t a, t b) {
	return (a.s != b.s) ? a.s < b.s : a.w < b.w;
}

bool cmp2(t a, t b) {
	return (a.e != b.e) ? a.e < b.e : a.w < b.w;
}

map<int, int> mp;

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= k; i++) {
		scanf("%d%d%d", &t1[i].w, &t1[i].s, &t1[i].e);
		t2[i].w = t1[i].w;
		t2[i].s = t1[i].s;
		t2[i].e = t1[i].s + t1[i].e;
	}
	for (int i = 1; i <= n; i++)	mp[i] = i;
	sort(t1 + 1, t1 + 1 + k, cmp1);
	sort(t2 + 1, t2 + 1 + k, cmp2);
	int i1 = 1, i2 = 1;
	priority_queue< int, vector<int>, greater<int> > empty;		// 小根堆
	while (i1 <= k && i2 <= k) {
		while (i1 <= k && t1[i1].s < t2[i2].e) {
			empty.push(mp[t1[i1].w]);	// 借钥匙产生的空位
			i1++;
		}
		while (i2 <= k && (i1 == k + 1 || t2[i2].e <= t1[i1].s)) {	// 注意等号：先还后借
			int x = empty.top();
			empty.pop();
			mp[t2[i2].w] = x;
			i2++;
		}
	}
	map<int, int> mp2;
	for (int i = 1; i <= n; i++) {
		mp2[mp[i]] = i;
	}
	for (int i = 1; i <= n; i++) {
		printf("%d ", mp2[i]);
	}
	return 0;
}

/*
5 2
4 3 3
2 2 7
*/
