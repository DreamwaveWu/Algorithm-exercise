#include<bits/stdc++.h>
using namespace std;

/*
使用 map 即可
为了优化，可以只存 a 的信息
	b 边读入边计算。

还需注意 map 的查找方式。

*/


/*
10 3 4
4 5
7 -3
10 1
1 10
4 20
5 30
7 40
*/

map<int, int> a;

int main() {
	int n, xa, xb;
	long long res = 0;
	scanf("%d%d%d", &n, &xa, &xb);
	
	for (int i = 0; i < xa; i++) {
		int index, value;
		scanf("%d%d", &index, &value);
		a[index] = value;
	}
	
	for (int i = 0; i < xb; i++) {
		int index, value;
		scanf("%d%d", &index, &value);
		auto it = a.find(index);
		if (it != a.end() )	res += it->second * value;
	}

	cout << res;

	return 0;
}
