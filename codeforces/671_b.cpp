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
#define ff(i, f, t) for(int i=f;i<t;i++)
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
ll m, n, o, p, i, j, k, l, a, b, c;
int main(){
	std::ios::sync_with_stdio(false);
	// fr; fo;
	cin >> m >> n;
	vi arr(m, 0), sum(m,0); input(arr, m);

	sort(all(arr));
	sum[0] = arr[0];
	ff(i,1,m) sum[i] = sum[i-1] + arr[i];
	
	long long cost = 0;
	long long lo = 0, hi = sz(arr);
	while(lo < hi -1){
		// cout << lo << " " << hi << endl;
		long long mid = lo + hi; mid /= 2;
		cost = arr[mid] * mid - sum[mid] + arr[mid];
		// cout << lo << " " << hi << " " << mid << " " << cost <<endl;
		if(cost <= n) lo = mid;
		else hi = mid;
	}
	cost = n;
	// cout << lo << endl;
	ff(i,0,lo){
		cost -= abs(arr[lo] - arr[i]);
		arr[i] = arr[lo];
	} 
	ff(i,0,lo + 1) arr[i] += cost / (lo + 1);

	cost %= (lo + 1);
	ff(i,0,cost) arr[i]++;

	sort(all(arr));
	// dbg(arr); cout << endl;
	lo = -1, hi = sz(arr) - 1;

	sum[0] = arr[0];
	ff(i,1,m) sum[i] = sum[i-1] + arr[i];
	while(lo < hi -1){
		// cout << lo << " " << hi << endl;
		long long mid = lo + hi; mid /= 2;
		cost = sum[m-1] - sum[mid] - arr[mid] * (m - mid - 1);
		// cout << lo << " " << hi << " " << mid << " " << cost <<endl;
		if(cost <= n) hi = mid;
		else lo = mid;
	}
	cost = n;
	// cout << hi << endl;
	ff(i, hi,m){
		cost -= abs(arr[hi] - arr[i]);
		arr[i] = arr[hi];
	} 
	ff(i,hi,m) arr[i] -= cost / ( m - hi);

	cost %= (m - hi);
	ff(i,0,cost) arr[hi + i]--;

	sort(all(arr));
	// dbg(arr); cout << endl;

	cout << arr.back() - arr[0] << endl;


	return 0;
}
