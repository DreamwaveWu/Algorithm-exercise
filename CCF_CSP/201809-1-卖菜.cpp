#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n;
	int x[1005];
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x[i]);
	}
	for (int i = 1; i <= n; i++) {
		if (i != 1 && i != n) {
			printf("%d ", (x[i - 1] + x[i] + x[i + 1]) / 3);
		} else if (i == 1)	printf("%d ", (x[1] + x[2]) / 2);
		else printf("%d", (x[n - 1] + x[n]) / 2);
	}

	return 0;
}
