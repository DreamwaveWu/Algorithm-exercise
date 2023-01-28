#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define INF 0x3f3f3f3f

map<int, int> mp;       //映射回该作品的真正的ID
struct Cmp {
	bool operator()(const pair<ll, int>& a, const pair<ll, int>& b)const {
		if (a.first == b.first) return a.second < b.second;		// 这行不能少，但具体怎么写没有影响
		return a.first > b.first;
	}
};
int f[200010], p[200010];       //p[i]表示作品i真正的id。
int tot;
int finds(int x) {
	return f[x] == x ? x : finds(f[x]);
}
void unions(int x, int y) {		// 将 x 并入 y
	f[finds(x)] = finds(y);
}
ll n;
int m, q;
map<int, ll> cnt;                               //纪录每个作品的票数
set <pair<ll, pair<ll, int> > > seg;            //维护现有的段 <右端点,<左端点, 作品id> >
set <pair<ll, int>, Cmp> heap;                  //维护当前各个作品的得票数排名

int main() {
	cin >> n >> m >> q;
	tot = m;	// 这一行非常关键
	for (int i = 1; i <= max(2 * q, 2 * m); i++) {
		f[i] = p[i] = i;
	}
	for (int i = 1; i <= m; i++) mp[i] = i;
	cnt[0] = n;
	seg.insert(make_pair(n, make_pair(1, 0)));
	for (int _ = 0; _ < q; _++) {
		int op;
		int x, y, w;
		ll l, r;
		cin >> op;
		if (op == 1) {
			cin >> l >> r >> x;
			int rx = p[x];
			auto bg = seg.lower_bound(make_pair(l, make_pair(0, rx)));      //找到插入本次段落的起点bg和终点ed
			auto ed = seg.lower_bound(make_pair(r, make_pair(0, rx)));

			ll b;
			ll a;
			int c, rc;
			vector<pair<ll, pair<ll, int> > > add;
			for (auto it = bg; it != seg.end(); it++) {               //删除bg和ed之间的段(因为都被本次插入覆盖了)
				b = (*it).first;
				a = (*it).second.first;
				c = (*it).second.second;
				rc = finds(c);   //找到c真正所属的作品的id
//更新信息（先删除，再插入)
				heap.erase(make_pair(cnt[rc], rc));
				cnt[rc] -= (b - a + 1);
				if (rc && cnt[rc] > 0) {	// 0 可以不放入 heap 中
					heap.insert(make_pair(cnt[rc], rc));
				}
				if (it == ed) break;
			}

			// 下面两段可以与上面合并，分开写是为了使逻辑更清晰
			b = (*bg).first;
			a = (*bg).second.first;
			c = (*bg).second.second;
			rc = finds(c);
			if (a <= l - 1 && l <= b) {     //考虑因为开头没有覆盖完，而新增加的段
				heap.erase(make_pair(cnt[rc], rc));
				cnt[rc] += (l - a);
				if (rc && cnt[rc] > 0)
					heap.insert(make_pair(cnt[rc], rc));
				add.push_back(make_pair(l - 1, make_pair(a, rc)));
			}
			if (ed != seg.end()) {      //考虑结尾没有覆盖完，而新增加的段
				b = (*ed).first;
				a = (*ed).second.first;
				c = (*ed).second.second;
				rc = finds(c);
				if (a <= r && r + 1 <= b) {
					heap.erase(make_pair(cnt[rc], rc));
					cnt[rc] += (b - r);
					if (rc && cnt[rc] > 0)
						heap.insert(make_pair(cnt[rc], rc));
					add.push_back(make_pair(b, make_pair(r + 1, rc)));
				}
			}
			if (ed != seg.end()) ed = next(ed);		// 左闭右开
			seg.erase(bg, ed);						// 删除原有段，包括之前开头结尾的重叠部分
			for (auto ad : add) seg.insert(ad);		// 增加原有开头结尾的重叠部分
			seg.insert(make_pair(r, make_pair(l, rx)));		// 增加新增的一整段
			heap.erase(make_pair(cnt[rx], rx));
			cnt[rx] += (r - l + 1);
			heap.insert(make_pair(cnt[rx], rx));

		} else if (op == 2) {
			cin >> x >> w;
			heap.erase(make_pair(cnt[p[x]], p[x]));
			heap.erase(make_pair(cnt[p[w]], p[w]));
			cnt[p[w]] += cnt[p[x]];
			if (p[w]) heap.insert(make_pair(cnt[p[w]], p[w]));
			unions(p[x], p[w]);     //将x合并到w中
			p[x] = ++tot;           //给x一个新身份id（原来的已经被合并到w了，再用就会出错）
			mp[tot] = x;
		} else if (op == 3) {
			cin >> x >> y;
			swap(mp[p[x]], mp[p[y]]);
			swap(p[x], p[y]);
		} else if (op == 4) {
			cin >> w;
			w = p[w];
			cout << cnt[w] << '\n';
		} else {
			if (heap.size() == 0)     cout << 0 << '\n';
			else {
				int ans = 0;
				int ans_id = 0;
				for (auto it : heap) {
					if (it.first > ans) {
						ans = it.first;
						ans_id = mp[it.second];
					}
					if (it.first == ans && mp[it.second] < ans_id) ans_id = mp[it.second];
					if (ans > it.first) break;
				}
				cout << ans_id << '\n';
			}
		}
	}
	return 0;
}
