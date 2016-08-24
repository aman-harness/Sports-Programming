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
int m, n, o, p, i, j, k, l, a, b, c;
int main(){
	std::ios::sync_with_stdio(false);
	fr; fo;
	cin >> m >> n;
	vi arr(m, 0), sum(m,0); input(arr, m);

	sort(all(arr));
	sum[0] = arr[0];
	ff(i,1,m) sum[i] = sum[i-1] + arr[i];
	
	int s = 0;
	c = sum[m-1] / m;
	int r = sum[m-1] - c * m;
	// if(!r) c--;
	ff(i,0,m-r) s += abs(arr[i]-c);
	ff(i,m-r,m) s += abs(arr[i]-(c+1));

	s /= 2;
	if(x >= s){
		if((x-s)&1) cout << 1 << endl;
		else cout << 0<< endl;
	}
	else{
		int hi = m - 1;
		int lo = 0;
		while(lo < hi){
			int mid = lo + ( hi - lo ) / 2;
			int sm = sum[m-1] - sum[mid];
			sm -= (hi - mid) * arr[mid];
			if(sm < s) hi = mid;
			else lo = mi1d;
		}
	}
	return 0;
}
