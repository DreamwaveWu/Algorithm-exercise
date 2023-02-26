#include<bits/stdc++.h>
using namespace std;


/*
left：从左至右判断
right：从右至左判断. 需要特备注意的是，一个任务可能被后续多个任务依赖，
        需要在各最晚天数中取最小值.
*/

int main() {
	int n, m;
	int rely[400], days[400];
	int left[400], right[400];
	bool flag = false;
	memset(right, 0, sizeof(right));
	memset(rely, 0, sizeof(rely));
	memset(days, 0, sizeof(days));
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &rely[i]);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &days[i]);
	}
	for (int i = 1; i <= n; i++) {
		if (rely[i] == 0) {
			left[i] = 1;
		} else {
			left[i] = left[rely[i]] + days[rely[i]];
		}
		flag |= (left[i] + days[i] > m + 1);
	}
	for (int i = n; i >= 1; i--) {
		if (right[i] == 0) {
			right[i] = m - days[i] + 1;
		}
		if (rely[i] != 0) {
			right[rely[i]] = right[rely[i]] == 0 ? right[i] - days[rely[i]] : min(right[rely[i]], right[i] - days[rely[i]]);
		}

	}
	for (int i = 1; i <= n; i++) {
		printf("%d ", left[i]);
	}
	if (!flag) {
		printf("\n");
		for (int i = 1; i <= n; i++) {
			printf("%d ", right[i]);
		}
	}

	return 0;
}
