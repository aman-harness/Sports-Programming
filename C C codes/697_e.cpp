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
typedef pair<int,int> ii;
typedef vector<ii> vii;
#define sz(a) int((a).size())
#define mp make_pair
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

inline void sc(ll &x)
{
	scanf("%lld", &x);
}

#define inf 2e9
const double eps = 1e-7;
#define N 2000005
ll MOD = 1000000007;
ll n, k;
ll inp[N], A[N], B[N];
char str[N];

vvi mat = {{1, 1, 0}, {1, 0, 1}, {0, 1, 1}};
ll x = 2;

struct Matrix {
	Matrix() {a[0][0] = a[1][1] = a[0][1] = a[1][0] = 0;}
	long long a[2][2];
};

Matrix operator *(const Matrix &A, const Matrix &B) {
	Matrix C;
	C.a[0][0] = C.a[0][1] = C.a[1][0] = C.a[1][1] = 0;
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j)
			for (int k = 0; k < 2; ++k)
				C.a[i][j] += A.a[i][k] * B.a[k][j], C.a[i][j] %= MOD;
	return C;
}

long long pow(long long A, long long p) {
	long long C = 1;
	while (p) {
		if (p & 1)
			C = (C * A) % MOD;
		A = (A * A) % MOD;
		p >>= 1;
	}
	return C;
}

Matrix pow(Matrix A, long long p) {
	Matrix C;
	C.a[0][0] = C.a[1][1] = 1;
	while (p) {
		if (p & 1)
			C = C * A;
		A = A * A;
		p >>= 1;
	}
	return C;
}


ll calc2(long long base, long long n,long long M = MOD)
{
    if(n==0)
       return 1;
    if(n==1)
    return base;
    long long halfn=calc2(base,n/2,M);
    if(n%2==0)
        return ( halfn * halfn ) % M;
    else
        return ( ( ( halfn * halfn ) % M ) * base ) % M;
}
ll inv(){
	return (calc2(2, MOD - 2, MOD) + MOD) % MOD;
}

int main(){
	std::ios::sync_with_stdio(false);
	// fr;
	sc(n); R(i, n) sc(inp[i]);
	Matrix A;
	A.a[0][0] = MOD - 1;
	A.a[0][1] = 1;
	A.a[1][0] = 0;
	A.a[1][1] = 2;

	ll p2 = 2;
	R(i, n){
		A = pow(A, inp[i]);
		p2 = pow(p2, inp[i]);
	}
	// cout << inv() << endl;
	// cout << MOD << endl;
	cout << (((A.a[0][0] + A.a[0][1]) * inv()) % MOD + MOD) % MOD << "/" << (p2 * inv()) % MOD << endl;
	return 0;
}