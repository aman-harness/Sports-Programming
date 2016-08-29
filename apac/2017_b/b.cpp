#include <bits/stdc++.h>
using namespace std;

#define ll long long

typedef vector<int> vi; 
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

#define IS_64BIT_ARCH (sizeof(ulong) == sizeof(i64))

typedef unsigned long long i64;
#define IS_64BIT_ARCH (sizeof(ulong) == sizeof(i64))
typedef map<i64, int> m64i;
typedef m64i::iterator fptr64;
typedef unsigned int i32;
const int BASES_LENGTH = 9;
const i32 BASES[BASES_LENGTH] = { 2, 3, 5, 7, 11, 13, 17, 19, 23 };
const int MAXN = 2e5;
int S[MAXN + 1], P[2][MAXN + 1];
i64 A[MAXN + 1];
inline i64 mod_mul(const i64 a, const i64 b, const i64 MOD) {
    i64 rx;
    __asm__(
            "mulq   %%rdx               \n\t"
            "divq   %%rbx               \n\t"
            : "=d" (rx)
            : "a" (a), "b" (MOD), "d" (b)
    );
    return rx;
}

inline ll safe_mull(const ll a, const ll b, const ll MOD) {
    if (IS_64BIT_ARCH) return mod_mul(a, b, MOD);
    ll rx = 0, tmpx = 0;
    for (register int bx = 0; b >> bx; ++bx) {
        tmpx += bx ? tmpx : a;
        if (tmpx >= MOD)
            tmpx -= MOD;
        if ((b >> bx) & 1) {
            rx += tmpx;
            if (rx >= MOD)
                rx -= MOD;
        }
    }
    return rx;
}
//assuming base is mod MOD
inline ll mod_pow(const ll base, const ll exp, const ll MOD) {
    ll rx = 1, tmp = 1;
    for (register int bx = 0; exp >> bx; ++bx) {
        tmp = safe_mull(tmp, bx ? tmp : base, MOD);
        if ((exp >> bx) & 1)
            rx = safe_mull(rx, tmp, MOD);
    }
    return rx;
}

int solve(){
	ll cnt = 0;
	ll mod = 1000000007;
	cint(a); cint(b); cint(n); cint (k);
	ff(i, 1, n + 1){
		ff(j, 1, n + 1){
			if(i == j) continue;
			ll x = mod_pow(i, a, k) + mod_pow(j, b, k);
			if(x % k == 0) cnt++;
		}
	}
	return cnt % mod;
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
