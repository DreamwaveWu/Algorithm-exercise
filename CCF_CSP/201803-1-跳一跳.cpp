#include<bits/stdc++.h>
using namespace std;

int main() {
	int x;
	int ans = 0;
	bool flag = true;
	int old = 0;
	while (true) {
		scanf("%d", &x);
		if (x == 0)	break;
		else if (x == 1)	{
			ans += 1;
			flag = true;
		} else if (x == 2) {
			if (flag) {
				ans += 2;
				flag = false;
				old = 2;
			} else {
				old += 2;
				ans += old;
			}
		}
	}

	printf("%d",ans);
	return 0;
}
