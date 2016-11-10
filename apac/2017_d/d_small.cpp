/*
Author : Aman Singh
Solution for problem code Stretch Rope.
 
==============================================
A programmer started to cuss,
'cause getting to sleep was a fuss.
As he lay there awake in his bed,
Looping around and 'round in his head,
Was: while(!asleep()) sheep++;
==============================================
 
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii;
typedef vector<ii> vii;
#define sz(a) int((a).size()) 
// #define mp make_pair
#define pb push_back 
#define fi first
#define se second
#define buli(x) (__builtin_popcountll(x))
#define all(c) (c).begin(),(c).end() 
#define foreach(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
#define input(s, n) for(int i=0;i<n;i++)cin >> s[i];
#define F(i, f, t) for(int i=f;i<t;i++)
#define R(i,n) for(ll i=0;i<n;i++)
#define cint(x) int x; cin >> x;

#define print(cnt,x) cout<<"Case #"<<cnt<<": "<<x<<"\n";

template <class T>  inline void smax(T &x,T y){ x = max((x), (y));}
template <class T>  inline void smin(T &x,T y){ x = min((x), (y));}

#ifdef LOCAL
#define fr freopen("input.txt","r",stdin)
#define fo freopen("output.txt","w",stdout)

#define error(x) cerr << #x << " = " << (x) <<endl
#define Error(a,b) cerr<<"( "<<#a<<" , "<<#b<<" ) = ( "<<(a)<<" , "<<(b)<<" )\n";
#define errop(a) cerr<<#a<<" = ( "<<((a).x)<<" , "<<((a).y)<<" )\n";
#define dbg(x) F(i,0,sz(x)) cout << x[i] << " ";
#define dbgg(x) F(i,0,sz(x)){F(j,0,sz(x[0])) cout << x[i][j] << " "; cout << endl;}
#else
#define fr 1
#define fo 1
#define error(x)
#define Error(a,b)
#define errop(a)
#define dbg(x)
#define dbgg(x)
#endif

#define inf 1e9
const double eps = 1e-7;

int ans = INT_MAX;

int rec(int from, int n, vector<pair<ii, int>> &inp, int f, int t, int c, int l){
	if(f <= l && t >= l) smin(ans, c);
	else if(from == n) return 0;
	else{
		int i = from;	
		rec(from + 1, n, inp, f + inp[i].fi.fi, t + inp[i].fi.se, c + inp[i].se, l);
		rec(from + 1, n, inp, f, t, c, l);
	}
	return 0;
}

int solve(){
	int n, m, l;
	ans = INT_MAX;
	cin >>  n >> m >> l;
	vector<pair<ii, int>> inp(n, {{0, 0}, 0});
	R(i, n) cin >> inp[i].fi.fi >> inp[i].fi.se >> inp[i].se;
	rec(0, n, inp, 0, 0, 0, l);
	if(ans < m) 
		return ans;
	else return -1;
}

int main(){
	std::ios::sync_with_stdio(false);
	fr;
	cint(tt); F(tc, 1, tt + 1){
		int xx = solve();
		if(xx == -1) {print(tc, "IMPOSSIBLE");r}
		else print(tc, xx);
	}
	return 0;
}