/*
Author : Aman Singh
Solution for problem code Santa Claus and Tangerines.
*/

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
#define sz(a) ll((a).size())
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define buli(x) (__builtin_popcountll(x))
#define all(c) (c).begin(),(c).end()
#define foreach(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define input(s, n) for(ll i=0;i<n;i++) cin >> s[i];
#define F(i, f, t) for(ll i=f;i<t;i++)
#define R(i,n) for(ll i=0;i<n;i++)
#define _ << ' ' <<

#define prll(cnt,x) cout<<"Case #"<<cnt<<": "<<x<<"\n";

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

inline void sc(ll &x)
{
	bool f=0; x=0; char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') { f=1; c=getchar(); }
	while(c>='0' && c<='9') { x=x*10+c-'0'; c=getchar(); }
	if(f) x=-x; return;
}

void sc(char &x) {scanf("%c", &x); }
void sc(ll &x,ll &y) { sc(x); return sc(y); }
void sc(ll &x,ll &y,ll &z) { sc(x); sc(y); return sc(z); }

#define inf 2e9
const double eps = 1e-7;

#define N 2000005
ll n, k, w;
ll ttime = 0, val = 0, ans = 0, pop = 0, curr = 1;
ll A[N], B[N];
char str[N];

multiset<ll> half, full;


ll insert(){
	//cout << "Inserting " _ curr	 << endl;
	full.insert(B[curr]);
	val += A[curr];
	ttime += B[curr++];
	if(half.size() < w){
		auto x = *full.rbegin();
		auto it = full.end(); it--;
		half.insert(x);
		full.erase(it);
		ttime -= (x) / 2 ;
	}
}

ll rollback(){
	//cout << "Rollbacking " _ pop << endl;
	if(full.find(B[pop]) != full.end()){
		full.erase(full.find(B[pop]));
		ttime -= B[pop];
		val -= A[pop];
	}
	else if(half.find(B[pop]) != half.end()){
		half.erase(half.find(B[pop]));
		val -= A[pop];
		ttime -= (B[pop] + 1) / 2;
		if(!full.empty()){
			half.insert(*full.rbegin());
			ttime -= (*full.rbegin() ) / 2;
			auto it = full.end(); it--;
			full.erase(it);
			// full.erase(full.rbegin());
		}
	}
	pop++;
}

int main(){
	std::ios::sync_with_stdio(false);
	// fr;
	sc(n, w, k); R(i, n) sc(A[i]); R(i, n) sc(B[i]);

	if(w && (B[0] + 1) / 2 <= k) {half.insert(B[0]); ttime += (B[0] + 1) / 2; val = A[0];} 
	else if(B[0] <= k){full.insert(B[0]); ttime += (B[0]); val = A[0 ];}
	else pop = 1;
	smax(ans, val);
	while(curr < n && pop < n){
		//Error(ttime, curr);
		if(ttime <= k) insert();
		//Error(ttime, val);
		if(ttime > k) rollback();
		if(ttime <= k) smax(ans, val);
	}

	cout << ans << endl;
	return 0;
}