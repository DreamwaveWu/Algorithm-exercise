#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	int a[1005];
	double bar = 0.0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		bar += (double) a[i];
	}
	bar /= n;
	double d = 0.0;
	for (int i = 0; i < n; i++) {
		d += (a[i] - bar) * (a[i] - bar);
	}
	d /= n;
	d = sqrt(d);
	for (int i = 0; i < n; i++) {
		printf("%f\n", (a[i] - bar) / d);
	}
	
	return 0;
}
