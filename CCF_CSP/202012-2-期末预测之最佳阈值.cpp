#include<bits/stdc++.h>
using namespace std;
#define MAXN 10000
#define ll long long

/*
定义结构体。先无脑录入，再排序。
使用前缀和数组，统计 1 的个数。
对于每一个 y ，其 1 的个数就是总共的 res = 1 减去 小于 y 的 res = 1 的个数
其 0 的个数就是小于 y 的样本的总个数 减去 小于 y 的 res = 0 的个数
*/

struct node {
	int y;
	int result;
} stu[100005];


int s[100005];
bool cmp(struct node a, struct node b) {
	return (a.y != b.y ) ? a.y < b.y : a.result < b.result;
}


int main() {
	int m;
	cin >> m;
	for (int i = 1; i <= m; i++) {
		cin >> stu[i].y >> stu[i].result;
	}
	sort(stu + 1, stu + 1 + m, cmp);
	s[0] = 0;
	for (int i = 1; i <= m; i++) {
		s[i] = s[i - 1] + stu[i].result;	// 统计 1 的前缀和
	}
	int maxn = 0, cnt = 0, y_max;
	int i = 1 ;
	while (i <= m) {	// 需要注意的是，每一次统计的 y 都是 stu[i-1].y
		cnt = s[m] - s[i - 1] + i - 1 - s[i - 1];  // 统计 1 的 个数 和 0 的个数 
		if (maxn <= cnt) {
			maxn = cnt;
			y_max = stu[i].y;
		}
		while (i < m && stu[i].y == stu[i + 1].y)	{	// 跳到下一个 y，注意此时的 y 已经考虑过了
			i++;
		}
		if (i == m) break;
		i++;
	}
	cout << y_max << endl;
	return 0;
}
