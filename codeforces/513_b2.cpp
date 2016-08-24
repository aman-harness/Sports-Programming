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
int curr_max = 0;
set<vi> ret;
ll m, n, o, p, i, j, k, l, a, b, c, f;
int main(){
	std::ios::sync_with_stdio(false);
	// fr; fo;
	ret.clear();
	cin >> n >> m;
	vi orig(n, 0);
	f = 0, l = n-1;
	ff(i,0,n){
		// cout << pow(2, l - f - 1) << " " << m<< endl;
		if(pow(2, l - f - 1) >= m){
		// if(m >> (l-f)){
			orig[f++] = i+1;
		}
		else{
			m -= pow(2, l - f - 1);
			orig[l--] = i+1;
			// m -= ;
		}
		// cout << m << " "  << l << " " << f << endl; 
	}
	dbg(orig); cout << endl;
	return 0;
}
