#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

int* build_next(char* s) {
	size_t m = strlen(s), j = 0;
	int* N = new int[m];
	int t = N[0] = -1;
	while (j < m - 1) {
		if (t < 0 || s[j] == s[t]) {
			j++; t++;
			N[j] = (s[j] != s[t]) ? t : N[t];
		}
		else {
			t = N[t];
		}
	}
	return N;
}

int match(char* s, char* t) {
	int* next = build_next(t);
	int n = (int)strlen(s), i = 0;
	int m = (int)strlen(t), j = 0;
	while ((j < m) && (i < n)) {
		if (j < 0 || s[i] == t[j]) {
			i++; j++;
		}
		else {
			j = next[j];
		}
	}
	delete[] next;
	return i - j;
}


void main_KMP() {
	char s[1000], t[1000];
	std::cin >> s >> t;
	int result = match(s, t);
	std::cout << result;
}