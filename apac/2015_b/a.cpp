#include <bits/stdc++.h>
using namespace std;

typedef vector<long long> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii;
typedef vector<ii> vii;
#define ll long long  
#define sz(a) int((a).size()) 
#define mp make_pair
#define pb push_back 
#define fi first
#define se second
#define buli(x) (__builtin_popcountll(x))
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
#define input(s, n) for(int i=0;i<n;i++)cin >> s[i];
#define ff(i, f, t) for(ll i=f;i<t;i++)
#define rep(i,n) for(ll i=0;i<n;i++)
#define cint(x) int x; cin >> x;

#define what_is(x) cerr << #x << " is " << x << endl;
#define dbg(x) ff(i,0,sz(x)) cout << x[i] << " ";
#define dbgg(x) ff(i,0,sz(x)){ff(j,0,sz(x[0])) cout << x[i][j] << " "; cout << endl;}

#define print(cnt,x) cout<<"Case #"<<cnt<<": "<<x<<"\n";

#ifdef LOCAL
#define fr freopen("input.txt","r",stdin)
#define fo freopen("output.txt","w",stdout)
#else
#define fr 1
#define fo 1
#endif

#define inf 1e9
const double eps = 1e-7;
// int m, n;
#define MOD 1000000007


long long pow(int a, int b)
{
    long long x=1,y=a; 
    while(b > 0)
    {
        if(b%2 == 1)
        {
            x=(x*y);
            if(x>MOD) x%=MOD;
        }
        y = (y*y);
        if(y>MOD) y%=MOD; 
        b /= 2;
    }
    return x;
}

long long InverseEuler(int n)
{
    return pow(n,MOD-2);
}

long long C(int n, int r)
{
	// cout << n << " " << r  << endl;
    vector<long long> f(n + 1,1);
    for (int i=2; i<=n;i++)
        f[i]= (f[i-1]*i) % MOD;
    return (f[n]*((InverseEuler(f[r]) * InverseEuler(f[n-r])) % MOD)) % MOD;
}

int init(vvi &dp, int n,int m){
	ff(i,0,min(m,n)){
		dp[1][i] = 1;
	}
	return 0;
}

ll rec(int n, int m, vvi& dp){
	// cout << n << " "<< m << endl;
	if( (n == 1 && m >= n)) return 1;
	else if(m < n || m < 0 || n < 0	) return 0;
	else{
		if(dp[n][m]) return dp[n][m];
		else{
			ll maxi = m - n + 1;
			ll sum = 0;
			ff(i,1, maxi+1){
				ll temp = rec(n-1, m - i, dp) % MOD;
				// cout << "in " 	<< n << " " << m << endl;
				temp *= C(m, m-i) % MOD;
				sum += temp;
				sum %= MOD;
			}
			dp[n][m] = sum % MOD;
			return sum % MOD;
		}
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	fr;
	int t; cin >> t;
	for(int tt = 1; tt <= t; tt++){
		int n, m;
		cin >> n >> m;
		
		vvi dp(n + 1, vi(m + 1, 0));
		init(dp, n, m);
		// cout <<  << endl;
		print(tt, rec(n, m, dp));
		// dbgg(dp);  cout << endl;
	}

	return 0;
}
