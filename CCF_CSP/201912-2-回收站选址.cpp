#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
这道题可以认为是对 STL 熟练度的考察。
熟悉 map 和 set 的 遍历 及 搜索。
*/

map <ll, set<ll>> mp;

int main() {
	int n;
	ll x, y;
	scanf("%d", &n);
	int cnt[5] = {0};
	for (int i = 0; i < n; i++) {
		scanf("%lld%lld", &x, &y);
		mp[x].insert(y);
	}
	for (auto it : mp) {
		ll x = it.first;		// 每个横坐标 x
		set<ll> s = it.second;	// 对应的所有 纵坐标
		for (auto y : s) {
			if (s.find(y - 1) != s.end() && s.find(y + 1) != s.end()) {		// 正上方、正下方
				auto a = mp.find(x - 1), b = mp.find(x + 1);
				if (a != mp.end() && b != mp.end() && a->second.find(y) != a->second.end() && b->second.find(y) != b->second.end()) {
					// 正左方、正右方
					int count = 0;
					if (a->second.find(y + 1) != a->second.end())	count++;
					if (a->second.find(y - 1) != a->second.end())	count++;
					if (b->second.find(y + 1) != b->second.end())	count++;
					if (b->second.find(y - 1) != b->second.end())	count++;
					cnt[count]++;
				}
			}
		}
	}

	printf("%d\n%d\n%d\n%d\n%d", cnt[0], cnt[1], cnt[2], cnt[3], cnt[4]);


	return 0;
}



/*
7
1 2
2 1
0 0
1 1
1 0
2 0
0 1

11
9 10
10 10
11 10
12 10
13 10
11 9
11 8
12 9
10 9
10 11
12 11
*/
