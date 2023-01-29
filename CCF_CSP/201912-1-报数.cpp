#include<bits/stdc++.h>
using namespace std;


/*
（1）如何判断含有数字 7
（2）注意是统计跳过的次数
*/


bool find(int x) {
	while (x > 0) {
		if (x % 10 == 7)	return true;
		x /= 10;
	}
	return false;
}

int main() {
	int n, a[4];
	memset(a, 0, sizeof(a));
	scanf("%d", &n);
	int cnt = 0, i = 1, pos = 0;
	while (cnt < n) {
		while (i % 7 == 0 || find(i)) {
			i++;
			a[pos] += 1;
			pos = (pos + 1) % 4;
		}
		pos = (pos + 1) % 4;
		cnt++;
		i++;
	}
	printf("%d\n%d\n%d\n%d", a[0], a[1], a[2], a[3]);

	return 0;
}
