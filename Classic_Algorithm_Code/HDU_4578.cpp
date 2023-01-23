#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include<assert.h>
#define lson rt<<1
#define rson rt<<1|1
#define lowbit(x) (x)&(-(x))
using namespace std;
typedef long long LL;
static const int INF = 0x3f3f3f3f;
static const int N = (int)1e5 + 7;
static const int mod = 10007;
static int n, q;
static int ar[N];

struct lp {
	int l, r;
	LL sum1, sum2, sum3, d;
	LL lazy1, lazy2, lazy3;
}cw[N << 2];

//pushdown先乘除后加减
//加法 lazy1 lazy2 乘法
void push_up(int rt) {
	cw[rt].sum1 = (cw[lson].sum1 + cw[rson].sum1) % mod;
	cw[rt].sum2 = (cw[lson].sum2 + cw[rson].sum2) % mod;
	cw[rt].sum3 = (cw[lson].sum3 + cw[rson].sum3) % mod;
}

void build(int l, int r, int rt) {
	int m = (l + r) >> 1;
	cw[rt].l = l; cw[rt].r = r;
	cw[rt].d = r - l + 1;
	cw[rt].sum1 = cw[rt].sum2 = cw[rt].sum3 = 0;
	cw[rt].lazy1 = cw[rt].lazy3 = 0;
	cw[rt].lazy2 = 1;
	if (l == r) { return; }
	build(l, m, lson); build(m + 1, r, rson);
	push_up(rt);
}

//pushdown先乘除后加减
void push_down(int rt) {
	if (cw[rt].lazy3) {
		LL tmp = cw[rt].lazy3 * cw[rt].lazy3 % mod * cw[rt].lazy3 % mod;
		cw[lson].lazy1 = cw[rson].lazy1 = 0;
		cw[lson].lazy2 = cw[rson].lazy2 = 1;
		cw[lson].lazy3 = cw[rson].lazy3 = cw[rt].lazy3;

		cw[lson].sum3 = cw[lson].d * tmp % mod;
		cw[rson].sum3 = cw[rson].d * tmp % mod;

		cw[lson].sum2 = cw[lson].d * cw[rt].lazy3 % mod * cw[rt].lazy3 % mod;
		cw[rson].sum2 = cw[rson].d * cw[rt].lazy3 % mod * cw[rt].lazy3 % mod;

		cw[lson].sum1 = cw[lson].d * cw[rt].lazy3 % mod;
		cw[rson].sum1 = cw[rson].d * cw[rt].lazy3 % mod;


		cw[rt].lazy3 = 0;
	}
	if (cw[rt].lazy1 != 0 || cw[rt].lazy2 != 1) {
		LL add = cw[rt].lazy1, mul = cw[rt].lazy2;
		LL l1 = cw[lson].sum1, l2 = cw[lson].sum2, l3 = cw[lson].sum3;
		LL r1 = cw[rson].sum1, r2 = cw[rson].sum2, r3 = cw[rson].sum3;
		LL tmp = mul * mul % mod * mul % mod;

		cw[lson].lazy1 = (cw[lson].lazy1 * mul % mod + add) % mod;
		cw[rson].lazy1 = (cw[rson].lazy1 * mul % mod + add) % mod;
		cw[lson].lazy2 = cw[lson].lazy2 * mul % mod;
		cw[rson].lazy2 = cw[rson].lazy2 * mul % mod;

		cw[lson].sum3 = (cw[lson].sum3 * tmp % mod + add * add % mod * add % mod * cw[lson].d % mod + 3 * cw[lson].sum2 * mul % mod * mul % mod * add % mod + 3 * cw[lson].sum1 * mul % mod * add % mod * add % mod) % mod;
		cw[rson].sum3 = (cw[rson].sum3 * tmp % mod + add * add % mod * add % mod * cw[rson].d % mod + 3 * cw[rson].sum2 * mul % mod * mul % mod * add % mod + 3 * cw[rson].sum1 * mul % mod * add % mod * add % mod) % mod;

		cw[lson].sum2 = (cw[lson].sum2 * mul % mod * mul % mod + add * add % mod * cw[lson].d % mod + 2 * mul * add * cw[lson].sum1) % mod;
		cw[rson].sum2 = (cw[rson].sum2 * mul % mod * mul % mod + add * add % mod * cw[rson].d % mod + 2 * mul * add * cw[rson].sum1) % mod;

		cw[lson].sum1 = (cw[lson].sum1 * mul + add * cw[lson].d) % mod;
		cw[rson].sum1 = (cw[rson].sum1 * mul + add * cw[rson].d) % mod;

		cw[rt].lazy1 = 0; cw[rt].lazy2 = 1;
	}
}

//op==1 加法, op==2 乘法, op==3 改变值
void update(int L, int R, int op, int z, int rt) {
	int l = cw[rt].l, r = cw[rt].r, mid = (l + r) >> 1;
	if (cw[rt].l > R || cw[rt].r < L)return;
	if (L <= l && r <= R) {
		LL l1 = cw[rt].sum1, l2 = cw[rt].sum2;
		if (op == 1) {//加法
			cw[rt].lazy1 = (z + cw[rt].lazy1) % mod;
			cw[rt].sum3 = (cw[rt].sum3 + (z * z % mod) * z % mod * cw[rt].d % mod + 3 * z * (cw[rt].sum2 + (cw[rt].sum1 * z) % mod) % mod) % mod;
			cw[rt].sum2 = (cw[rt].sum2 + cw[rt].d * z % mod * z % mod + 2 * z * cw[rt].sum1 % mod) % mod;
			cw[rt].sum1 = (cw[rt].sum1 + cw[rt].d * z % mod) % mod;
		}
		else if (op == 2) {//乘法
			cw[rt].lazy1 = cw[rt].lazy1 * z % mod;
			cw[rt].lazy2 = cw[rt].lazy2 * z % mod;
			cw[rt].sum1 = cw[rt].sum1 * z % mod;
			cw[rt].sum2 = (cw[rt].sum2 * z % mod) * z % mod;
			cw[rt].sum3 = ((cw[rt].sum3 * z % mod) * z % mod) * z % mod;
		}
		else {
			cw[rt].lazy1 = 0; cw[rt].lazy2 = 1;
			cw[rt].lazy3 = z;
			cw[rt].sum3 = cw[rt].d * z % mod * z % mod * z % mod;
			cw[rt].sum2 = cw[rt].d * z % mod * z % mod;
			cw[rt].sum1 = cw[rt].d * z % mod;
		}
		return;
	}
	if (cw[rt].l == cw[rt].r)return;
	push_down(rt);
	if (L > mid)update(L, R, op, z, rson);
	else if (R <= mid)update(L, R, op, z, lson);
	else {
		update(L, mid, op, z, lson);
		update(mid + 1, R, op, z, rson);
	}
	push_up(rt);
}

LL query(int L, int R, int op, int rt) {
	int l = cw[rt].l, r = cw[rt].r, mid = (l + r) >> 1;
	if (L <= l && r <= R) {
		if (op == 1)return cw[rt].sum1;
		else if (op == 2)return cw[rt].sum2;
		return cw[rt].sum3;
	}
	if (cw[rt].l == cw[rt].r)return 0;
	push_down(rt);
	LL sum = 0;
	if (L > mid) sum = query(L, R, op, rson);
	else if (R <= mid) sum = query(L, R, op, lson);
	else {
		sum = query(L, mid, op, lson);
		sum += query(mid + 1, R, op, rson);
	}
	return (sum % mod);
}

int main_HDU_4578() {
	while (~scanf("%d%d", &n, &q) && (n + q)) {
		build(1, n, 1);
		while (q--) {
			int op, l, r, z;
			scanf("%d%d%d%d", &op, &l, &r, &z);
			if (op <= 3) {
				z %= mod;
				update(l, r, op, z, 1);
			}
			else {
				printf("%lld\n", query(l, r, z, 1));
			}
		}
	}
	return 0;
}
