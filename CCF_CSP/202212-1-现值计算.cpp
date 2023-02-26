#include<bits/stdc++.h>
using namespace std;


int main() {
	int n;
	double p;
	scanf("%d%lf", &n, &p);

	double ans;

	scanf("%lf", &ans);
	for (int i = 1; i <= n; i++) {
		double x;
		scanf("%lf", &x);
		ans += x * pow(1 + p, -i);
	}
	printf("%f", ans);

	return 0;
}
