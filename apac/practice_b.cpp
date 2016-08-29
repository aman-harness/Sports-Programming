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
	fr; fo;
	int t; cin >> t; 
	for(int tt = 1; tt <= t; tt++){
		cint(n); ll arr[4][n]; cint(k);
		ff(i,0,4) ff(j,0,n) cin >> arr[i][j];
		vi con(n*n, 0), con2(n*n, 0);
		ff(i,0,n)ff(j,0,n) con[i*n + j] = arr[0][i] ^ arr[1][j] ^ k;
		ff(i,0,n)ff(j,0,n) con2[i*n + j] = arr[2][i] ^ arr[3][j];
		// dbg(con); cout << endl;
		// dbg(con2); cout << endl;
		sort(all(con2));
		ll count  = 0;
		ff(i,0,n*n) {
			int x = binary_search(all(con2), con[i]);
			if(x) x = upper_bound(all(con2), con[i]) - lower_bound(all(con2), con[i]);
			if(x) count+= x;
		}
		print(tt, count);
	}

	return 0;
}
