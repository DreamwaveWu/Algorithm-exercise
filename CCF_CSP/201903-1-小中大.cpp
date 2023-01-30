#include<bits/stdc++.h>
using namespace std;

/*
fixed << setprecision(1) 是保留一位小数的意思
注意原生的除法会直接抹掉小数部分。
*/


int main() {
	int n;
	long long a, m, b, tmp;
	scanf("%d", &n);
	int mid = n == 1 ? 1 : n / 2;
	bool flag = (n % 2 == 0), flag_d = false;
	double m_d = 0;
	for (int i = 1; i <= n; i++) {
		if (i == 1)	scanf("%lld", &a);
		else if (i == n)	scanf("%lld", &b);
		else if (flag && i == mid)	scanf("%lld", &m);
		else if (flag && i == mid + 1)	{
			scanf("%lld", &tmp);
			m += tmp;
			if (m % 2 != 0) {
				flag_d = true;
				m_d = (double)m / 2.0;
			} else {
				m /= 2;
			}
		} else if (!flag && i == mid + 1)	scanf("%lld", &m);
		else	scanf("%lld", &tmp);
	}
	if (a > b) {
		if (flag_d) {
			cout << a << " " << fixed << setprecision(1) << m_d << " " << b;
		} else printf("%lld %lld %lld", a, m, b);
	} else {
		if (flag_d)  {
			cout << b << " " << fixed << setprecision(1) << m_d << " " << a;
		} else printf("%lld %lld %lld", b, m, a);
	}
	return 0;
}


/*
3
-1 2 4

4
-2 -1 3 4

4
-2 -1 4 5
*/
