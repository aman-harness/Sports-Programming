#include <bits/stdc++.h>
using namespace std;

typedef vector<long long> vi; 
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
#define ff(i, f, t) for(ll i=f;i<t;i++)
#define rep(i,n) for(ll i=0;i<n;i++)
#define cint(x) ll x; cin >> x;

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
vi ret;
int call(ll x, int s){
	bitset<32> xx(x);
	string str;
	ff(i,0,s){
		if(xx[i]) str.pb('4');
		else str.pb('7');
	}
	ret.pb(stoll(str));
}
int main(){
	std::ios::sync_with_stdio(false);
	// fr; fo;	
	cint(x);
	string str = to_string(x);
	int s = sz(str);
	if(s&1) s++;
	ff(i,0,(1<<s)){
		if(__builtin_popcount(i) == s / 2) call(i, s);
	}
	s += 2;
	ff(i,0,(1<<s)){
		if(__builtin_popcount(i) == s / 2) call(i, s);
	}
	sort(all(ret));
	vector<ll>:: iterator c = lower_bound(all(ret), x);
	// dbg(ret); cout << endl;
	cout << *c << endl;
	return 0;
}
