#include <cstdio>
#include <map>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

const int N = 4001;
const int mod = 1000000007;

map<vector<int>, int> c;
char s[N];
int dp[N];
int n, m;

inline void update(int &a, long long b) {
	a = (a + b) % mod;
}

int main() {
	int t, tt;
	scanf("%d", &t);
	for (tt = 1; tt <= t; tt++) {
		scanf("%d%d", &n, &m);
		c.clear();
		for (int i = 0; i < n; i++) {
			vector<int> a(26);
			scanf("%s", s);
			for (int j = 0; s[j] != '\0'; j++) a[s[j] - 'a']++;
			c[a]++;
		}
		printf("Case #%d:", tt);
		for (int i = 0; i < m; i++) {
			scanf("%s", s);
			int ls = strlen(s);
			dp[0] = 1;
			for (int j = 0; j < ls; j++) {
				dp[j + 1] = 0;
				vector<int> a(26);
				for (int k = 0; k < 20 && j - k >= 0; k++) {
					a[s[j - k] - 'a']++;
					map<vector<int>, int>::iterator it = c.find(a);
					if (it != c.end()) update(dp[j + 1], (long long)dp[j - k] * it->second);
				}
			}
			printf(" %d", dp[ls]);
		}
		printf("\n");
	}
	return 0;
}