#include <bits/stdc++.h>
using namespace std;

typedef vector<long double> vi; 
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
int m, n;
int fun(int l){

}
long double solve(){
	cint(b); cint(l); cint(n);
	vvi arr(l + 2, vi()); 
	arr[0].pb(0);
	ff(i,1,l + 2) ff(j,0, sz(arr[i-1])+i+1) arr[i].pb(0);
	arr[0][0] = 750 * b;

	vector<int> sum(1000, 0);
	ff(i, 0, 1000) sum[i] = i;
	ff(i,0,1000) sum[i] += sum[i-1];


	queue<ii> Q;
	Q.push({0,0});
	int lev = 0, num = 0;
	while(!Q.empty()){
		ii x = Q.front(); Q.pop();
		lev = x.fi, num = x.se;
		if(lev >= l) break;
		double excess = (arr[lev][num] - 250) / 3;
		// cout << lev << " " << num << " " << excess << endl;
		if(excess > 0) arr[lev][num] = 250;

		int temp = lower_bound(all(sum), num + 1) - sum.begin() ;
		// cout << lev << " " << num << " " << excess << " " << temp << endl;
		if(excess > 0){
			arr[lev+1][num] += excess;
			arr[lev+1][num + temp] += excess;
			arr[lev+1][num + temp + 1] += excess;
			Q.push({lev+1, num});
			Q.push({lev+1, num + temp});
			Q.push({lev+1, num + temp + 1});
		}
	}
	return arr[l-1][n-1];
	// cout << arr[l-1][n-1] << endl;

}

int main(){
	std::ios::sync_with_stdio(false);
	cout.precision(12);
	cout << fixed << endl;
	fr; 
	int t; cin >> t;
	vvi arr(402, vi());
	for(int tt = 1; tt <= t; tt++){
		print(tt, solve());
	}

	return 0;
}
