#include <bits/stdc++.h>

using namespace std;
typedef vector<long long int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii;
#define ll long long  
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
#define mp make_pair
#define si(n) scanf("%d",&n)
#define slli(n) scanf("%lld",&n);
#define ss(n) scanf("%s",n);
#define input(s, n) for(int i=0;i<n;i++)cin >> s[i];
#define ff(i, f, t) for(int i=f;i<t;i++)
#define cint(x) long long int x; cin >> x;

// string str = "001001100011011";
string str = "0010011";
vi pow2;
char fun(ll n, int s){
	if(n <= sz(str)) {
		if(s) return str[n - 1];
		if(str[n - 1] == '0') return '1';
		return '0';
	}
	else{
		int pos = lower_bound(all(pow2), n) - pow2.begin();
		if(pow2[pos] == n){
			if(s) return '0';
			else return '1';
		}
		else{
			return fun(pow2[pos - 1] - (n - pow2[pos - 1]), !s);
		}
	}
}

int main(){
	#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	std::ios::sync_with_stdio(false);

	ll m = 1; ll x = 1;
	while(m < 63){
		pow2.pb((ll)1 << m++);
	}
	// ff(i, 0, sz(pow2)) cout << pow2[i] << " ";
	// cout << endl;

	cint(n); vi arr(n, 0); input(arr, n);
	ff(i, 0, n){
		cout << "Case #" << i + 1 << ": " << fun(arr[i], 1) << endl;
	}
	return 0;
}
