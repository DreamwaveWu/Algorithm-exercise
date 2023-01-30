#include<bits/stdc++.h>
using namespace std;


/*
这道题需要深刻反省！！！！！！
*/



int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a, b;
		char x = ' ';
		vector<int> num;
		vector<char> op;

		for (int k = 0; k <= 3; k++) {
			scanf("%d", &a);
			num.push_back(a);
			if (num.size() > 1 && k != 0) {
				if (x == 'x' || x == '/') {
					a = num.back();
					num.pop_back();
					b = num.back();
					num.pop_back();
					if (x == 'x')	num.push_back(a * b);
					else			num.push_back(b / a);
				} else {
					op.push_back(x);
				}
			}
			if (k != 3)	scanf("%c", &x);
		}

		while (!op.empty()) {
			a = num.front();
			num.erase(num.begin());
			b = num.front();
			num.erase(num.begin());
			x = op.front();
			op.erase(op.begin());
			if (x == '+')	num.insert(num.begin(), a + b);
			else 			num.insert(num.begin(), a - b);
		}

		if (num.front() == 24) printf("Yes\n");
		else printf("No\n");
	}

	return 0;
}



/*
10
9+3+4x3
5+4x5x5
7-9-9+8
5x6/5x4
3+5+7+9
1x1+9-9
1x9-5/9
8/5+6x9
6x7-3x6
6x4+4/5
*/
