#include<bits/stdc++.h>
using namespace std;


int main() {
	int n;
	long long max = 0, min = 0;
	int now, old = 0;
	scanf("%d",&n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &now);
		if (now == old)	{
			max += old;
			min += 0;
		} else {
			max += now;
			min += now;
		}
		old = now;
	}
	std::cout << max << std::endl << min;

	return 0;
}
