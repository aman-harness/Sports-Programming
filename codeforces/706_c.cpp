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
	// fr; fo;
	cint(n); vi cost(n, 0);
	input(cost, n);
	vector< pair<string, int> > vs;
	ff(i,0,n){
		string str; cin>> str;
		vs.pb({str, i + 1});
		reverse(all(str));
		vs.pb({str, -1*(i+1)});		
	}
	map <int, int> mymap;
	sort(all(vs));
	vector<ll> dp(2*(n ), 1000000000000000000);
	ff(i,0,2*n){
		mymap[vs[i].se] = i;
	}
	ff(i,0,2*n){
		if(abs(vs[i].se)==1){
			if(vs[i].se==1) dp[i] = 0;
			else dp[i] = cost[0];
		}
		else{
			int &xx = vs[i].se; 
			int ppos = mymap[abs(xx) - 1];
			int mpos = mymap[-1*(abs(xx) - 1)];
			int sign = xx / abs(xx);
			// if(vs[i].fi == "ac") cout << ppos << " - " << mpos << endl;
			if(ppos<i){
				if(sign==-1)
					dp[i] = min(dp[i], dp[ppos]+cost[abs(xx) - 1]);
				else dp[i] = min(dp[i], dp[ppos]);
			}
			if(mpos<i){
				if(sign==-1)
					dp[i] = min(dp[i], dp[mpos]+cost[abs(xx) - 1]);
				else dp[i] = min(dp[i], dp[mpos]);
			}
		}
	}

	// ff(i,0,2*n) cout<< vs[i].fi << " " << vs[i].se << endl; cout << endl;
	if(dp[mymap[n]]>=1000000000000000000 && dp[mymap[-1*n]]>=1000000000000000000) {cout << -1 << endl;}
	else cout << min(dp[mymap[n]], dp[mymap[-1*n]]) << endl;
	return 0;
}
