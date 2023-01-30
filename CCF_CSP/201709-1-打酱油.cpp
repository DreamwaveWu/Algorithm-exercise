#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	n /= 10;
	int cnt = 0;
	while (n > 0) {
		if (n >= 5) {
			n -= 5;
			cnt += 7;
		} else if (n >= 3) {
			n -= 3;
			cnt += 4;
		} else {
			cnt += n;
			n = 0;
		}
	}
	printf("%d",cnt);
	return 0;
}
