#include <bits/stdc++.h>
using namespace std;

#define ll long long

typedef vector<ll> vi; 
typedef vector<vi> vvi; 
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
  
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

int solve(){
	ll n, l1, r1, a, b, c1, c2, m;
	cin >> n >> l1 >> r1 >> a >> b >> c1 >> c2 >> m;
	std::vector<ii> ret;
	// ret.pb({l1, r1});
	n  =3;
	ret.pb({1, 8});
	ret.pb({9, 9});
	ret.pb({8, 88});
	// ret.pb({3, 8});
	// ret.pb({2, 888});
	// ret.pb({5, 888});
	// ret.pb({l1, r1});

	// ff(i, 0, n-1){
	// 	ii lst = ret.back();
	// 	ll new_x = (a * lst.fi + b * lst.se + c1) % m;
	// 	ll new_y = (a * lst.se + b * lst.fi + c2) % m;
	// 	ret.pb({min(new_x, new_y), max(new_x, new_y)});
	// 	// cout << new_x << " " << new_y << endl;
	// }
	sort(all(ret));
	ll maxi = INT_MAX;
	ff(i,0,n){
		ll cnt = 0;
		ll maxx = -1;
		ff(j,0,n){
			if(i == j) continue;
			if(ret[j].se - max(maxx,ret[j].fi) >= 0){
				if(maxx >= ret[j].fi)
					cnt += ret[j].se - maxx);
				else
					cnt += ret[j].se - max(maxx,ret[j].fi) + 1;
				maxx = max(maxx,ret[j].se);
			}
		}
		maxi = min(cnt, maxi);
	}
	return maxi;
}

int main(){
	std::ios::sync_with_stdio(false);
	fr;
	int t; cin >> t;
	for(int tt = 1; tt <= t; tt++){
		print(tt, solve());
	}
	return 0;
}
