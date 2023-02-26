#include<bits/stdc++.h>
using namespace std;

int main() {
	int q[9][9], m[9][9], m2[9][9];
	double m3[9][9];
	memset(m, 0, sizeof(m));
	memset(m3, 0, sizeof(m3));
	for (int i = 1; i <= 8; i++) {
		for (int j = 1; j <= 8; j++) {
			scanf("%d", &q[i][j]);
		}
	}
	int n, t;
	scanf("%d%d", &n, &t);
	int line = 1, index = 1;
	int count = 0;
	while (true) {

		int x;
		scanf("%d", &x);
		count++;
		int i, j;
		i = (line < 8) ? (line - index + 1) : (8 - index + 1);
		j = line + 1 - i;
		m[i][j] = x;
	//	printf("i = %d  j = %d  x = %d\n", i, j, x);
		if ((line % 2 == 0 && index == 1) || (line % 2 != 0 && (index == line || index + line == 16))) {
			index = (line % 2 == 0) ? 1 : (line < 8 ? line + 1 : 15 - line);
			line++;
		} else {
			index = (line % 2 == 0) ? index - 1 : index + 1;
		}
		if (count == n)	break;
	}
	for (int i = 1; i <= 8; i++) {
		for (int j = 1; j <= 8; j++) {
			m2[i][j] = m[i][j] * q[i][j];
		}
	}
	double pai = acos(-1) / 8;
	for (int i = 1; i <= 8; i++) {
		for (int j = 1; j <= 8; j++) {
			for (int u = 1; u <= 8; u++) {
				double au = u == 1 ? sqrt(0.5) : 1.0;
				for (int v = 1; v <= 8; v++) {
					double av = v == 1 ? sqrt(0.5) : 1.0;
					m3[i][j] += au * av * m2[u][v] * cos(pai * (i - 0.5) * (u - 1)) * cos(pai * (j - 0.5) * (v - 1));
				}
			}
			m3[i][j] *= 0.25;
			m3[i][j] += 128;
			m3[i][j] = round(m3[i][j]);
			m3[i][j] = m3[i][j] > 255 ? 255 : m3[i][j];
			m3[i][j] = m3[i][j] < 0 ? 0 : m3[i][j];

		}
	}

	for (int i = 1; i <= 8; i++) {
		for (int j = 1; j <= 8; j++) {
			if (t == 0) {
				printf("%d ", m[i][j]);
			} else if (t == 1) {
				printf("%d ", m2[i][j]);
			} else {
				printf("%d ", (int)m3[i][j]);
			}
		}
		printf("\n");
	}
	return 0;
}
