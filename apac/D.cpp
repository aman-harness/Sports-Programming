#include <cstdio>
#include <algorithm>

using std::max;

typedef long long i64;

int T, m, n, l[19], r[19];
int a[19][19], c[19][19];
i64 s[19][19];
i64 ans;

void dfs(int k, int num, int w, i64 sum) {
	if (num == 8) {
		if (ans < sum) ans = sum;
		return;
	}
	if (k >= n || w <= 0) return;
	if (n - k + num < 8) return;
	if (ans > sum + s[k][8 - num]) return;
	dfs(k + 1, num, w, sum);
	int cost = 0;
	for (int i = l[k]; i <= r[k]; ++i) {
		if (w < cost) break;
		dfs(k + 1, num + 1, w - cost, sum + a[k][i]);
		cost += c[k][i];
	}
}

int main() {
	freopen("input.txt","r",stdin);
	scanf("%d", &T);
	for (int tT = 1; tT <= T; ++tT) {
		scanf("%d%d", &m, &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d%d", r + i, l + i);
			for (int j = 1; j <= r[i]; ++j)
				scanf("%d", a[i] + j);
			for (int j = 1; j < r[i]; ++j)
				scanf("%d", c[i] + j);
		}
		for (int i = n - 1; ~i; --i)
			for (int j = 1; j <= 8; ++j)
				s[i][j] = max(s[i + 1][j], s[i + 1][j - 1] + a[i][r[i]]);
		ans = 0;
		dfs(0, 0, m, 0);
		printf("Case #%d: %lld\n", tT, ans);
	}
	return 0;
}
