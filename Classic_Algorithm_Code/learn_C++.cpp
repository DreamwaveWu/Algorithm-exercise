#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

void main_learn_C_plus_plus() {
	vector<int> a(10, 1);
	a[a.size() - 1] = 2;
	for (auto first = a.begin(); first != a.end(); ++first) {
		cout << *first << endl;
	}


	list<int> node(5, 1);
	list<int>::iterator it = node.begin();
	while (it != node.end()) {
		cout << *it++ << endl;
	}

}