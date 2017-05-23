/*
Author : Aman Singh
Solution for problem code .
*/

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
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
#define infll 20000000000000000
const double eps = 1e-7;

#define N 2000005
int n, k, m;
int A[N], B[N], inp[N];
char str[N];

int main(){
	std::ios::sync_with_stdio(false);
	// fr;
	string a, b;
	cin >> a >> b;

	int i = 0;, j = 0;
	vi f(sz(b), -1), b(sz(b), -1);
	while(i < sz(a) && j < sz(b)){
		while(i < sz(a) && a[i] != b[j]) i++;
		if(i < sz(a)){
			f[j] = i;
			j++;
		}
	}
	j = sz(b) - 1, i = sz(a) - 1;
	while(i >= 0 && j >= 0){
		while(i >= 0 && a[i] != b[j]) i--;
		if(i >= 0){
			b[j] = i;
			j--;
		}
	}

	int from = 0, to = 0;
	i = 0;
	
	while(i < sz(f) && f[i] != -1) i++;
	// Excluding to
	from = i, to = sz(f);
	
	i = sz(f) - 1;
	while(i >= 0 && b[i] != -1) i--;
	if(n - i + 1 > ){
		from = 0, to = 
	}

	i = 0, j = sz(f) - 1;
	while(i < j && (f[i] != -1 && b[j] != -1) && (f[i] < b[j])){
		i++;
		j--;
	}

	if(f[i] == -1 && i) i--;
	if(b[j] == -1 && j != n - 1) j++;


	return 0;
}
