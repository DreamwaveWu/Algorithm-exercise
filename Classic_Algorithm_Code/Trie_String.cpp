#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

/*
-------- 【 前 缀 字 典 树 】 --------
（洛谷 P2580）https://www.luogu.com.cn/problem/solution/P2580
*/


static const int N = 800000;
struct node__Trie_String {
	bool repeat;	// 是否重复点名
	int son[26];	// 26个字母
	int num;		// 字符串出现次数
}t[N];
static int cnt = 1;

void Insert_Trie_Strin(char* s) {
	int now = 0;
	for (int i = 0; s[i]; i++) {
		int ch = s[i] - 'a';
		if (t[now].son[ch] == 0) {
			t[now].son[ch] = cnt++;
		}
		now = t[now].son[ch];
	}
	t[now].num++;
}


int Find_Trie_Strin(char* s) {
	int now = 0;
	for (int i = 0; s[i]; i++) {
		int ch = s[i] - 'a';
		if (t[now].son[ch] == 0)	return 3;
		now = t[now].son[ch];
	}
	if (t[now].num == 0)	return 3;
	if (!t[now].repeat) {
		t[now].repeat = true;
		return 1;
	}
}

void main_Trie_String() {
	char s[51];
	int n;
	std::cin >> n;
	while (n--) { scanf("%s", s); Insert_Trie_Strin(s); }
	int m;	scanf("%d", &m);
	while (m--) {
		scanf("%s", s);
		int r = Find_Trie_Strin(s);
		if (r == 1)	puts("OK");
		else if (r == 2)	puts("REPEAT");
		else if (r == 3)	puts("WRONG");
	}
}