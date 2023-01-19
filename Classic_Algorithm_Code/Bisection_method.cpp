#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>


// a[0] ~ a[n-1]

/**
 * @brief 查找范围是 [0,n)
 * @return 查找 x 或 x 的后继，溢出返回 n
*/
int Bisection_method_succ(int* a, int n, int x) {
	int left = 0, right = n;
	while (left < right) {
		int mid = (left + right) >> 1;
		if (a[mid] > x)	right = mid;
		else			left = mid + 1;
	}
	return left;	// 终止于 left = right
	//return std::lower_bound(a, a + n, x) - a;
}

/**
 * @brief 查找范围是 [0,n)
 * @return 查找 x 或 x 的前驱，溢出返回 0
*/
int Bisection_method_pre(int* a, int n, int x) {
	int left = 0, right = n;
	while (left < right) {
		int mid = (left + right + 1) >> 1;
		if (a[mid] <= x)	left = mid;
		else				right = mid - 1;
	}
	return left;	// 终止于 left = right
	//return std::upper_bound(a, a + n, x) - a - 1;
}


void main_Bisection_method() {
	int a[100], n, x;
	for (int i = 0; i < 100; i++) {
		a[i] = i * 2;
	}
	n = 100;
	x = 5;
	printf("%d", Bisection_method_pre(a, n, x));
}