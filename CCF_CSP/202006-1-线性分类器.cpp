#include<bits/stdc++.h>
using namespace std;

/*
（1）注意对字符的读取方法。
（2）注意判断直线分割的条件：相同符号。

*/

/*
9 3
1 1 A
1 0 A
1 -1 A
2 2 B
2 3 B
0 1 A
3 1 B
1 3 B
2 0 A
0 2 -3
-3 0 2
-3 1 1
*/

int a[1005][2];
int b[1005][2];

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	int ca = 0, cb = 0;
	for (int i = 0; i < n; i++) {
		int x, y;
		char type;
		scanf("%d%d %c", &x, &y, &type);
		if (type == 'A') {
			a[ca][0] = x;
			a[ca++][1] = y;
		} else {
			b[cb][0] = x;
			b[cb++][1] = y;
		}
	}

	for (int i = 0; i < m; i++) {
		int o1, o2, o3;
		scanf("%d%d%d", &o1, &o2, &o3);
		int flag = (o1 + o2 * a[0][0] + o3 * a[0][1]) > 0 ? 1 : -1;
		for (int i = 1; i < ca; i++) {
			if ((o1 + o2 * a[i][0] + o3 * a[i][1] )*flag < 0) {
				printf("No\n");
				flag = 0;
				break;
			}
		}
		if (flag == 0) {
			continue;
		}
		flag = -flag;
		for (int i = 0; i < cb; i++) {
			if ((o1 + o2 * b[i][0] + o3 * b[i][1])*flag < 0) {
				printf("No\n");
				flag = 0;
				break;
			}
		}
		if (flag != 0) {
			printf("Yes\n");
		}
	}

}
