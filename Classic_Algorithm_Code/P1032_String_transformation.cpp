#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

/*
【双向广度搜索】
（洛谷 P1032） https://www.luogu.com.cn/problem/P1032
*/

using namespace std;
static const int N = 6;
static int n;
static string a[N], b[N];


int extend_P1032(queue <string>& q,
	map <string, int>& da, map <string, int>& db, string a[], string b[]) {
	string t = q.front();	// 队首
	q.pop();
	if (da[t] > 10) return 11;	// 超过限制，剪枝
	for (int i = 0; i < t.size(); i++)	// 暴力匹配
		for (int j = 0; j < n; j++)
			if (t.substr(i, a[j].size()) == a[j]) {	 // 匹配成功
				string state = t.substr(0, i) + b[j] + t.substr(i + a[j].size());	// 转换后的串
				if (db.count(state))   return da[t] + 1 + db[state];	// 双向相遇
				if (da.count(state))   continue;	// 已搜索过
				// 抵达此地，意味着第一次被搜索到
				da[state] = da[t] + 1;	// 记录次数
				q.push(state);			// 入队
			}
	// 抵达此处，说明经过此次变换，未相遇，需要继续搜索
	return -1;
}


int bfs_P1032(string A, string B) {
	queue <string> qa, qb;		// 正向队列 与 逆向队列
	map <string, int> da, db;	// 记录字符串替换所需的次数
	qa.push(A), da[A] = 0;
	qb.push(B), db[B] = 0;
	while (qa.size() && qb.size()) {	// 先扩展较小的队列
		int t;
		if (qa.size() < qb.size())    t = extend_P1032(qa, da, db, a, b);
		else						  t = extend_P1032(qb, db, da, b, a);
		if (t != -1)    return  t;
	}
	// 抵达此处，说明 t 大于10
	return 11;
}



void main_P1032_String_transformation() {
	string A, B;
	cin >> A >> B;
	// 注：需要 Ctrl+Z 结束输入！
	while (cin >> a[n] >> b[n])    n++;
	int step = bfs_P1032(A, B);
	if (step > 10)     puts("NO ANSWER!");
	else               printf("%d\n", step);
}