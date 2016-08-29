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
int m, n;

int solve(){
	// Node - - line and station.
	ii node;
	map <pair <ii, ii>, int > dist;
	map < pair<ii, ii>, int> path;
	map <int, int> wait;
	cint(n);
	vvi 
	ff(i,1, n+1){
		cint(sn); cint(w);
		ff(j,1,sn+1){
			cint(temp);
			dist[{{i, j}, {i, j + 1}}] = temp;
		}
		wait[i] = w;
	}
	cint(m);
	ff(i,0,m){
		int m1, s1, m2, s2, t;
		cin >> m1 >> s1 >> m2 >> s2 >> t;
		path[{{m1, s1}, {m2, s2}}] = t;
	}

	map <ii , int> final;

}

int main(){
	std::ios::sync_with_stdio(false);
	fr; fo;
	int t; cin >> t;
	for(int tt = 1; tt <= t; tt++){
		print(tt, solve());
	}
	return 0;
}
