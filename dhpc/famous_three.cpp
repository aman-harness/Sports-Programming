/*
Author : Aman Singh
Solution for problem code The Famous Three.
 
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
typedef vector<ll> vi; 
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
#define fr freopen("in.txt","r",stdin)
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

#define MOD 1000000007

inline void sc(int &x)
{
	bool f=0; x=0; char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') { f=1; c=getchar(); }
	while(c>='0' && c<='9') { x=x*10+c-'0'; c=getchar(); }
	if(f) x=-x; return;
}

void sc(int &x,int &y) { sc(x); return sc(y); }
void sc(int &x,int &y,int &z) { sc(x); sc(y); return sc(z); }

#define inf 1e9
const double eps = 1e-7;

vvi g = {{0, 0, 0}, {2, 4, 12}, {2, 6, 16}};

vvi mul(vvi A, vvi B){
	vvi temp(A);
	R(i, 3){
		R(j, 3){
			ll t = 0;
			R(k, 3){
				t += temp[i][k] * B[k][j];
			}
			A[i][j] = t % MOD;
		}
	}
	return A;
}

vvi pow(int n){
	if(n == 1) return g;
	if(n & 1){
		return mul(pow(n - 1) , g);
	}
	else return mul(pow(n / 2), pow(n / 2));
}

ll ans(int n){
	vvi x = pow(n);
	dbgg(x);
	cout << endl;
	return (x[0][0] * 1 + 2 * x[1][0] + 6 * x[2][0] +
			   x[0][1] * 1 + 2 * x[1][1] + 6 * x[2][1] +
			   x[0][2] * 1 + 2 * x[1][2] + 6 * x[2][2]) % MOD;
}

int main(){
	std::ios::sync_with_stdio(false);
	fr;
	cint(tt); F(tc, 1, tt + 1){
		cint(x);
		if(x == 1){ cout << 9 << endl; continue;}
		cout <<  ans(x - 1) << endl;
	}
	return 0;
}