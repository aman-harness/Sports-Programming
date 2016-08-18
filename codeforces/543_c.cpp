#include <bits/stdc++.h>

using namespace std;
typedef vector<long long> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii;
#define ll long long  
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
#define mp make_pair
#define si(n) scanf("%d",&n)
#define slli(n) scanf("%lld",&n);
#define ss(n) scanf("%s",n);
#define input(s, n) for(int i=0;i<n;i++)cin >> s[i];
#define ff(i, f, t) for(int i=f;i<t;i++)
#define cint(x) int x; cin >> x;
#define dbgg(x) ff(i,0,sz(x)){ff(j,0,sz(x[0])) cout << " " << x[i][j]; cout << endl;}

int main(){
	#ifdef LOCAL
	freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	#endif
	std::ios::sync_with_stdio(false);
	cint(n); cint(m); cint(b); cint(mod);
	vi arr(n, 0);
	sort(all(arr));
	input(arr, n);

	vvi dp(m + 1, vi(b + 1, 0));
	dp[0][0] = 1;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			// if(!i & !j) continue;
			for(int k = 0; k <= b; k++){
				if(k + arr[i] <= b) {
					dp[j + 1][k + arr[i]] += dp[j][k] % mod;
					dp[j + 1][k + arr[i]] %= mod;
				}
				else break;
			}
		}
	}
	ll sum = 0; ff(i, 0, b + 1) sum += dp[m][i] % mod;
	// dbgg(dp);
	cout << sum % mod << endl;
	return 0;
}
