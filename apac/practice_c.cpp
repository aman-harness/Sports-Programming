#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi; 
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
#define ff(i, f, t) for(int i=f;i<t;i++)
#define rep(i,n) for(ll i=0;i<n;i++)
#define cint(x) int x; cin >> x;

#define what_is(x) cerr << #x << " is " << x << endl;
#define dbg(x) ff(i,0,sz(x)) cout << x[i] << " ";
#define dbgg(x) ff(i,0,sz(x)){ff(j,0,sz(x[0])) cout << ff[i][j] << " "; cout << endl;}

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

int main(){
	std::ios::sync_with_stdio(false);
	cout.precision(17);
	cout << fixed << endl;
	fr; fo;
	int t; cin >> t;
	for(int tt = 1; tt <= t; tt++){
		int n, x, k, a, b, c;
		long double ret = 0;
		cin >> n >> x  >> k >> a >> b >> c;
		long double dp[n+1][2];
		ff(i,0,31){
			// ret = 0;
			ff(i,0,(n+1)) dp[i][0] = dp[i][1] = 0;
			int bit = (1 << i) & k;
			int temp = (1 << i) & x;
			if(temp) dp[0][1] = 1; else dp[0][0] = 1;
			ff(j,1,(n+1)){
				if(bit) {
					long double x = 0;
					x += (dp[j- 1][1] * a) / 100;
					x += (dp[j - 1][0] * c) / 100;
					x += ((dp[j-1][0]+dp[j-1][1]) * b) / 100;
					dp[j][1] += x;
					dp[j][0] += 1 - x;
				}
				else{
					long double x = 0;
					x += ((dp[j- 1][0] + dp[j- 1][1]) * a) / 100;
					x += (dp[j - 1][0] * c) / 100;
					x += ((dp[j-1][0]) * b) / 100;
					dp[j][0] += x;
					dp[j][1] += 1 - x; 
				}
				// cout << i << " " << dp[j][0] << " " << dp[j][1] << " " << bit<< endl;
			}
			ret += dp[n][1] * (1 << i);
 		}
		print(tt, ret);
	}

	return 0;
}
