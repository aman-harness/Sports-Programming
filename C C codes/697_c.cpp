/*
Author : Aman Singh
Solution for problem code Santa Claus and Tangerines.
*/

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

typedef unsigned long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<ll,ll> ii;
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
#define input(s, n) for(int i=0;i<n;i++) cin >> s[i];
#define F(i, f, t) for(int i=f;i<t;i++)
#define R(i,n) for(ll i=0;i<n;i++)
#define _ << ' ' <<

#define print(cnt,x) cout<<"Case #"<<cnt<<": "<<x<<"\n";

template <class T>  inline void smax(T &x,T y){ x = max((x), (y));}
template <class T>  inline void smin(T &x,T y){ x = min((x), (y));}

#ifdef LOCAL
#define fr freopen("in.txt","r",stdin)
#define fo freopen("out.txt","w",stdout)

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

inline void sc(int &x)
{
	bool f=0; x=0; char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') { f=1; c=getchar(); }
	while(c>='0' && c<='9') { x=x*10+c-'0'; c=getchar(); }
	if(f) x=-x; return;
}

void sc(char &x) {scanf("%c", &x); }
void sc(int &x,int &y) { sc(x); return sc(y); }
void sc(int &x,int &y,int &z) { sc(x); sc(y); return sc(z); }

#define inf 2e9
const double eps = 1e-7;

#define N 2000005
ll n, k, a, b, c, d;
// int inp[N], A[N], B[N];
char str[N];
map<ii, ll> mp;
int inp(){
	cin >> a >> b >> c;
	int la = 64 - __builtin_clzll(a);
	int lb = 64 - __builtin_clzll(b);
	Error(la, lb);
	while(la < lb){
		mp[{b/2, b}] += c;
		b /= 2;
		lb--;
	}
	while(la > lb){
		mp[{a / 2, a}] += c;
		a /= 2;
		la--;
	}
	while(a != b){
		mp[{a / 2, a}] += c;
		mp[{b / 2, b}] += c;
		a/=2; b/=2;
		Error(a, b);
		Error(__builtin_clzll(a), __builtin_clzll(b)); 
	}
	//mp[{a / 2, a}] += c;

	// for(auto el: mp) cout << el.fi.fi _ el.fi.se << " " << el.se << endl;

	return 0;
}


// cout << endl;
int out(){
	cin >> a >> b;
	int la = 64 - __builtin_clzll(a);
	int lb = 64 - __builtin_clzll(b);
	ll res = 0;

	while(la < lb){
		res += mp[{b / 2, b}];
		b /= 2;
		lb--;
	}
	while(la > lb){
		res += mp[{a / 2, a}];
		a /= 2;
		la--;
	}
	while(a != b){
		res += mp[{a / 2, a}];
		res += mp[{b / 2, b}];
		a/=2; b/=2; 
	}
	//res += mp[{a / 2, a}];
	cout << endl << res;
	return 0;
}

int main(){
	std::ios::sync_with_stdio(false);
	// fr;
	cin >> n; while (n--){
		cin >> a; 
		if(a == 1) inp();
		else out();
	}

	return 0;
}