#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>



/**
 * @brief 原始字符串 --> 增广字符串
*/
void change(char* str, char* S, int n) {
	n = strlen(str);
	int k = 0;
	S[k++] = '$';	// 开始
	S[k++] = '#';	// 第一个字符之前也要有
	for (int i = 0; i < n; i++) {
		S[k++] = str[i];
		S[k++] = '#';
	}
	S[k++] = '&';	// 注意此处首尾不同，这是为了避免 while 越界
	n = k;	// n = strlen(S);
}


void Manacher(int* P, char* S, int n) {
	int R = 0;	// rightest position in P[0] ~ P[i-1] 
	int C = 0;	// center position   in P[0] ~ P[i-1]
	for (int i = 1; i < n; i++) {
		if (i < R) {
			P[i] = std::min(P[(C << 1) - i], P[C] + C - i);	// P[2C-i] or w=C+P[C]-i
		}
		else {
			P[i] = 1;	// i >= R, 只能初始化为 1
		}
		while (S[i + P[i]] == S[i - P[i]])	P[i]++;		// 暴力法扩充
		if (P[i] + i > R) {
			R = P[i] + i;
			C = i;			// update R and C
		}
	}
}

void main_Manacher() {
	const int N = 1000000;
	int n=0;
	int P[N << 1];	// 以 S[i] 为中心的回文半径
	char str[N];	// 原始字符串
	char S[N << 1];	// 增广字符串
	scanf("%s", str);
	change(str, S, n);
	Manacher(P, S, n);
	int ans = 1;	// default answer : 0
	for (int i = 0; i < n; i++) {
		ans = std::max(ans, P[i]);	// max(P[i])
	}
	printf("%d", ans - 1);	// ans = max(P[i]) - 1
}