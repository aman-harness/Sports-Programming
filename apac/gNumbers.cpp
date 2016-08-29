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
#define ff(i, f, t) for(ll i=f;i<t;i++)
#define rep(i,n) for(ll i=0;i<n;i++)
#define cint(x) ll x; cin >> x;

#define what_is(x) cerr << #x << " is " << x << endl;
#define dbg(x) ff(i,0,sz(x)) cout << x[i] << " ";
#define dbgg(x) ff(i,0,sz(x)){ff(j,0,sz(x[0])) cout << ff[i][j] << " "; cout << endl;}

#define print(cnt,x) cout<<"Case #"<<cnt<<": "<<x;

#ifdef LOCAL
#define fr freopen("input.txt","r",stdin)
#define fo freopen("output.txt","w",stdout)
#else
#define fr 1
#define fo 1
#endif

#define inf 1e9
const double eps = 1e-7;
long long int m, n, o, p, i, j, k, l, a, b, c;
bool primes[100000];
int init_prime(){
	// memset(primes, 1, sizeof(primes));
	ff(i,0,100000) primes[i]=1;
	ff(i,2,100000){
		j = 2;
		if(primes[i]){
			ll x = i * j;
			while(x < 100000){
				primes[x] = 0;
				x = i * j++;
			}
		}
	}
	return 0;
}

int isGnumber(ll x){
	ll sum = 0;
	while(x > 0){
		sum += x % 10;
		x /= 10;
	}
	// cout << sum << " "<< primes[sum] << endl;
	return primes[sum] ? 1 : 0;
}
int calc(ll num, int st, set<ll> &factors);
int calc2(ll num, int st, set<ll> &factors){
	// cout << "In lose side "<< num << " "<< st<<  " "  <<  endl;
	if(isGnumber(num)) return true;
	else{
		// cout << num << " - "<< st<< endl;
		int i = 0;
		for(auto it: factors){
			if(st & (1 << i)){
				ll temp = num;
				while(!(temp % it)) temp /= it;
				// cout << temp << " - "<< it<< endl;
				m = calc(temp, st & ~(1 << i) , factors);
				// cout << m << "-" << num << endl;
				if(!m) return false;
			}
			i++;
		}
	}
	return true;
}

int calc(ll num, int st, set<ll> &factors){
	// cout << "In win side " << num << " "<< st<<  "  "  <<  endl;
	if(isGnumber(num)) return false;
	else{
		int i = 0;
		for(auto it: factors){
			// cout << "Counting -- ";
			// cout << st << " " << (st & (1 << i)) << " " << i << endl;
			if(st & (1 << i)){
				ll temp = num;
				while(!(temp % it)) temp /= it;
				// cout << temp << " - "<< it<< endl;
				m = calc2(temp, st & ~(1 << i) , factors);
				// cout << m << "-" << num << endl;
				if(m) return true;
			}
			i++;
		}
	}
	return false;
}

int solve(){
	set<ll> factors;
	ll xd = n;
	int xx = sqrt(n) + 1;
	ff(i,2,xx){
		if(n % i == 0){
			factors.insert(i);
			while(n % i == 0) {n /= i;}
		}
	}
	if (n > 1) factors.insert(n);
	factors.erase(1);
	// cout << factors.size() << endl;
	// for(auto it: factors) cout<< it << " "; cout << endl;
	int x = factors.size();
	int maxi = (1 << x) - 1;

	return calc(xd, maxi, factors);
}

int main(){
	std::ios::sync_with_stdio(false);
	fr;
	init_prime();
	// ff(i,1,16) cout << i << " " <<primes[i] << endl;
	// cout << primes[167]; cout << endl;
	ll t; cin >> t;
	for(ll tt = 1; tt <= t; tt++){
		cin >> n;
		print(tt, "");
		if (solve())  cout << string("Laurence"); else cout <<  string("Seymour");
		cout << endl;
	}

	
	return 0;
}
