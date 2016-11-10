/*
Author : Aman Singh
Solution for problem code 732_c.
 
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
#define cint(x) ll x; cin >> x;

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

int check(int a[]){
	if(!a[0] && !a[1] && !a[2]) return 1;
	else return 0;
}

int main(){
	std::ios::sync_with_stdio(false);
	fr;
	int tt = 1; F(tc, 1, tt + 1){
		ll a[3];
		cin >> a[0] >> a[1] >> a[2];
		ll mini = min(a[0], min(a[1], a[2]));
		a[0] -= mini;
		a[1] -= mini;
		a[2] -= mini;
		ll ret = 0;
		ll st = 0;
		if(a[1] == max(a[0], max(a[1], a[2]))) st =1;
		else if(a[2] == max(a[0], max(a[1], a[2]))) st = 2;

		if(a[st] > a[(st + 1) % 3] && a[st] > a[(st + 2) % 3]) {a[st]--;}
		else if((a[st] == a[(st + 1) % 3] && a[st] != a[(st + 2) % 3]) || 
				(a[st] == a[(st + 2) % 3] && a[st] != a[(st + 1) % 3])	) ret = -1;
		ret += a[st] - a[(st + 1) % 3];
		ret += a[st] - a[(st + 2) % 3];
		cout << ret << endl;
	}
	return 0;
}