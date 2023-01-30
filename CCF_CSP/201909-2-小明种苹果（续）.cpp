#include<bits/stdc++.h>
using namespace std;


/*
注意读入的是负值，那么就不是减法而是加法。
设置 f1 ~ f3 来判断相邻三棵树的掉落情况。
设置 flag1、flag2 记录第一棵、第二棵，方便环形判断 E	。

*/


int main() {
	int n, m;
	bool f1, f2, f3, flag1 = false, flag2 = false;
	int d = 0, e = 0;
	scanf("%d", &n);
	long long t = 0;
	f1 = f2 = f3 = false;
	for (int i = 1; i <= n; i++) {
		f3 = false;
		scanf("%d", &m);
		long long x;
		scanf("%lld", &x);
		for (int j = 2; j <= m; j++) {
			long long num;
			scanf("%lld", &num);
			if (num <= 0) x += num;
			else {
				if (num < x && !f3) {
					f3 = true;
					d++;
					if (i == 1) flag1 = true;
					if (i == 2) flag2 = true;
				}
				x = num;
			}
		}
		t += x;
		if (i >= 3 && f1 == true && f2 == true && f3 == true)	e++;
		f1 = f2;
		f2 = f3;
	}
	if (f1 && f2 && flag1)	e++;
	if (f3 && flag1 && flag2)	e++;
	printf("%lld %d %d", t, d, e);

	return 0;
}


/*
4
4 74 -7 -12 -5
5 73 -8 -6 59 -4
5 76 -5 -10 60 -2
5 80 -6 -15 59 0


5
4 10 0 9 0
4 10 -2 7 0
2 10 0
4 10 -3 5 0
4 10 -1 8 0
*/