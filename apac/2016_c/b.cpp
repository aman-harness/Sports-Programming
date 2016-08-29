#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<long long,long long> ii;
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

#define inf 1e8
const double eps = 1e-7;

int main(){
	std::ios::sync_with_stdio(false);
	fr; fo;
	cint(t);
	ff(tt,0,t){
		cint(n);
		vector<ii>  ret;
		long long maxp, minp;
		int temp = 0;
		ff(i,0,n){
			cint(p); cint(f);
			if(p * f == 0){
				maxp = minp = 0;
				continue;
			}
			if(p == 100) {
				ret.pb({f, f});
				continue;
			}
			maxp = floor((f*100) /(long double)p);
			minp = ceil((f*100) /(long double)(p + 1));
			if(minp == f) minp++;
			if(maxp == floor((f*100) /(long double)(p + 1)))
				maxp--;
			cout << i << " " << minp << " " << maxp << endl;
			ret.pb({minp, maxp});
		}
		sort(all(ret));
		minp = inf*inf;
		maxp = INT_MIN;
		ff(i,0,sz(ret)){
			minp = min(ret[i].se, minp);
			maxp = max(ret[i].fi, maxp);
			// cout <<i << " "<< maxp << " " << ret[i].fi << endl;
		}
		cout << minp << " "  << maxp <<  endl;
		if(minp == maxp) print(tt+1, minp)
		else print(tt+1, -1);
	}
	return 0;
}
