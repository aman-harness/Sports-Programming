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
int check(int x[], string str){
	ff(i, 0, sz(str)){
		if( !x[str[i] - '0'] ) return false;
	}
	return sz(str);
}

const double eps = 1e-7;
int solve(){
	int x[10]; input(x, 10); int ret = 0;
	map<int, int> mymap; 
	set<int> st;
	cint(n);
	if(n == 1 && x[1] == 1) return 2;
	else if(n == 1 && x[1] != 1) return -1;
	ff(i, 1, sqrt(n) + 2) if(!(n % i)){
		st.insert(i); st.insert(n / i);
	}
	st.erase(1);
	for(auto it: st){
		int xx = check(x, to_string(it));
		if(xx) mymap[it] = xx;
		else mymap[it] = -1;
	}
	for(auto it: st){
		if(mymap[it] == -1){
			int mini = INT_MAX;
			ff(i,1, sqrt(it) + 2){
				if(it % i == 0){
					if(mymap[i] > 0 && mymap[it / i] > 0){
						mini = min(mymap[i] + mymap[it / i] + 1, mini);
					}
				}
			}
			if(mini < INT_MAX) mymap[it] = mini;
		}
	}
	// for(auto it: mymap){
	// 	cout << it.fi << " " << it.se << endl;
	// }
	// if(mymap[n] > 0 && check(x, to_string(n))) return mymap[n];
	if(mymap[n] > 0) return mymap[n] + 1;
	else return -1;
}

int m, n;
int main(){
	std::ios::sync_with_stdio(false);
	fr;
	int t; cin >> t;
	for(int tt = 1; tt <= t; tt++){
		int x = solve();
		if(x != -1) {print(tt, x);}
		else print(tt, "Impossible");
	}

	return 0;
}
