
#include <bits/stdc++.h>

using namespace std;
#define ll long long  
typedef vector< ll> vi; 
// typedef vector<vi> vector<vector<ll > >; 
typedef pair<int,int> ii;

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
#define cint(x) long long int x; cin >> x;


ll MOD = 1000000000;
#define REP(i,n) for (int i = 0; i < n; i++)

vector<vector<ll > > mul(vector<vector<ll > > A, vector<vector<ll > > B)
{
	int K = A.size();
    vector<vi> C(K, vector<ll >(K));
    REP(i, K) REP(j, K) REP(k, K)
        C[i][j] = (C[i][j] % MOD + ((A[i][k] % MOD) * (B[k][j] % MOD))% MOD) % MOD;
    return C;
}

// computes A ^ p
vector<vector<ll > > poww(vector<vector<ll > > A, long long p)
{
    if (p == 1)
        return A;
    if (p % 2)
        return mul(A, poww(A, p-1));
    vector<vector<ll > > X = poww(A, p/2);
    return mul(X, X);
}
vi ans;
int main(){
	std::ios::sync_with_stdio(false);
	freopen("input.txt","r",stdin);
	int t; cin >> t; 
	while(t--){
		int n; cin >> n; 
		vector<ll > b(n + 1, (ll)0); vector<ll > c(n + 1, (ll)0);
		vector<vector<ll > > dp(n + 1, b);
		// b[0] = 1;
		b[0] = 0; c[0] = 0;
		ff(i, 1, n+1) cin >> b[i]; 
		ff(i, 1, n + 1) cin >> c[i];
		cint(nn); 
		cint(m); 
		cin >> MOD;
		cout << MOD << endl;
		//  
		nn--;
		ll to = 0, from = 0;
		if(nn <= n){
			for(int i = 1 ; i <= nn; i++) from += b[i] % MOD;
		}
		else{
			ff(i, 0, n + 1) ff(j, 0, n+1) dp[i][j] = 0; dp[0][0] = 1;
			for(int i = 0; i < n + 1; i++) dp[n][i] = c[i];
			for(int i = 0; i < n; i++) dp[i][i + 1] = 1;
			vector<vector<long long> > ret = poww(dp, nn );

			// ff(i, 0, n + 1){
			// 	ff(j, 0, n+1) cout << dp[i][j] << " ";
			// 	cout << endl;
			// }
			// cout << "----\n";

			// ff(i, 0, n + 1){
			// 	ff(j, 0, n+1) cout << ret[i][j] << " ";
			// 	cout << endl;
			// }
			// cout << "----\n";

			ll sum = 0;
			ff(i, 0, n + 1){
				// cout << ret[0][i] << " " << b[i] << endl;
				sum += (ret[0][i] * b[i]) % MOD;
			}
			from = sum;
		}
		// cout << from<< endl;
		nn = m;
		if(nn <= n){
			for(int i = 1 ; i <= nn; i++) to += b[i] % MOD;
		}
		else{
			ff(i, 0, n + 1) ff(j, 0, n+1) dp[i][j] = 0; dp[0][0] = 1;
			for(int i = 0; i < n + 1; i++) dp[n][i] = c[i];
			for(int i = 0; i < n; i++) dp[i][i + 1] = 1;
			vector<vector<long long> > ret = poww(dp, nn );

			// ff(i, 0, n + 1){
			// 	ff(j, 0, n+1) cout << dp[i][j] << " ";
			// 	cout << endl;
			// }
			// cout << "----\n";

			// ff(i, 0, n + 1){
			// 	ff(j, 0, n+1) cout << ret[i][j] << " ";
			// 	cout << endl;
			// }
			// cout << "----\n";

			ll sum = 0;
			ff(i, 0, n + 1){
				// cout << ret[0][i] << " " << b[i] << endl;
				sum += (ret[0][i] * b[i]) % MOD;
			}
			to = sum;
		}
		// cout << to << endl;
		cout << (to - from + MOD) % MOD << endl;
		// if()
	}
	return 0;
}
