#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

/*
（HDU 2610)
	现在给你一个数字序列，包括n(<=1000)个整数，每个整数不大于2^31，
	你想要找到前P个不递减的子序列(如果总子序列W小于P，则只给出前W个子序列)。
	子序列的顺序是:一阶子序列的长度。二阶是每个整数在初始序列中所处位置的序列。
	例如，初始序列1,3,2，其合法子序列总数为5。按顺序为{1};{3};{2};{1,3};{1,2}。
	{1,3}优先于{1,2}，因为每个整数在初始序列中的位置序列都是{1,2}和{1,3}。

	（1）如果查找的是第一个元素 
		那么 从0开始到当前的位置看有没有出现过这个元素 出现过就pass
    （2）如果查找的不是第一个元素 
		那么 从查找的子序列当前位置的（前一个元素）对应原序列的位置一直到查到现在元素的位置看是否出现过

*/



static const int maxn = 1000 + 10;
static int order[maxn];    //存储输入序列 

static struct node {
	int pos, t;    //当前数字 t 对应序列 order 中的位置 pos 
}nt[maxn];

static int n, p;
static int len, count;      //当前长度和输出的序列个数 
static bool flag;           // 剪枝判断（若当前长度len没有一个满足解的，那么>len的肯定不满足了，故减掉）


void print_Sequence_one() {
	for (int i = 0; i < len - 1; i++)	printf("%d ", nt[i].t);
	printf("%d\n", nt[len - 1].t);
}


bool check_Sequence_one(int p1, int p2) {
	for (int i = p1; i < p2; i++) {
		if (order[i] == order[p2])	return false;
	}
	return true;
}

void dfs_Sequence_one(int deepth, int pos) {       //当前子序列中的元素个数deepth,及在order序列中的位置 
	if (count >= p)	return;		  // 只需输出前 p 个
	if (deepth == len) {		// 元素个数满足当前设定的序列长度
		print_Sequence_one();
		count++;
		flag = false;	// flag 重置
		return;
	}
	for (int i = pos; i < n; i++) {
		if (deepth == 0 && !check_Sequence_one(0, i))	continue;    //剪枝一，如果是当前元素都是子序列的第一个 
		if (deepth > 0 &&
			(!check_Sequence_one(nt[deepth-1].pos + 1, i)		// 剪枝二
				|| nt[deepth - 1].t > order[i]))	// 要满足非递减
			continue;      
		nt[deepth].pos = i;
		nt[deepth].t = order[i];
		dfs_Sequence_one(deepth + 1, i + 1);
	}
}

void main_Sequence_one() {
	while (scanf("%d%d", &n, &p) == 2) {
		if (n == 0) break;
		for (int i = 0; i < n; i++)	scanf("%d", &order[i]);
		count = 0;
		for (int i = 0; i < n; i++) {	// 从小到大枚举序列长度
			len = i + 1;
			flag = true;
			dfs_Sequence_one(0, 0);
			if (flag)	break;  //剪枝,flag 为 true 说明没有任何一个长度为len的满足要求的序列
		}
		printf("\n");
	}
}