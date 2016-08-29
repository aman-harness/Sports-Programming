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
// int m, n;
vector<vi> mymap (7, vi(0,0));
int init(){
	mymap[0] = {1, 2, 3, 4, 5, 6};
	mymap[1] = {2, 3};
	mymap[2] = {1, 2, 4, 5, 7};
	mymap[3] = {1, 4, 7};
	mymap[4] = {1, 2, 3, 4, 7};
	mymap[5] = {1, 2, 3, 4, 6, 7};
	mymap[6] = {1, 3, 4, 5, 6, 7};
	mymap[7] = {1, 2, 3};
	mymap[8] = {1, 2, 3, 4, 5, 6, 7};
	mymap[8] = {1, 2, 3, 4, 6 ,7};
}

int rec(int curr, set<int> & possible, vector<string>& vs, int last){
	int n = vs.size();
	if(possible.size() == 1) {
		cout << possible.size() << endl;
		if(possible.size() == 1) {
			cout << "Found";
			return 0;
		}	 
		else {
			for(auto it: impossible) cout << it << " "; cout << endl;
			cout << "Error\n"; return 0;
		}
	}
	else{
		string &str = vs[curr];
		set<int> nxt;
		for(auto it: possible){
			int xx = match(it, str);
			if(xx) nxt.insert(it);
		}
		rec(curr+1, nxt, vs);
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	fr;
	int t; cin >> t;
	init();
	for(int tt = 0; tt < t; tt++){
		cint(n); std::vector<string> inp;
		ff(i,0,n){
			string str;
			cin >> str;
			inp.pb(str);
		}

		if(sz(inp) > 9) inp.resize(9);
		set<int> impossible;
		ff(i, 0, 10) possible.insert(i);
		rec(0, possible, inp);
	}

	return 0;
}
