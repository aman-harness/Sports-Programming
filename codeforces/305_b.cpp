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
#define cint(x) long long x; cin >> x;

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

int main(){
	std::ios::sync_with_stdio(false);
	// fr; fo;
	cint(p); cint(q);
	cint(n); vi arr(n, 0);
	input(arr, n);
	ll i;
	int flag = 1;
	for(i = 0; i < n- 2 ; i++){
		if(!q) break;
		ll temp = p / q;
		// cout << i << " " << temp << " " << arr[i] << endl;
		if(temp != arr[i]) {flag = 0;break;}
		p = p % q;
		swap(p, q);
		if(p * q != 0){
			ll g = __gcd(p, q);
			// cout << g << endl;
			// cout << p << " " << q << endl;
			p /= g; q /= g;
		}
	}
	// cout << flag << endl;
	// cout << p << q << endl;
	// cout << arr[n-2] << " " << arr[n-1] << endl;
	if(!((p-1) % arr[n-2] == 0 && (p-1) % arr[n-1] == 0 && q == arr[n-1] && ((p-1) / arr[n - 2]) == arr[n-1])) flag = 0; 
	if(flag) cout << "YES\n";
	else cout << "NO\n";

	return 0;
}
