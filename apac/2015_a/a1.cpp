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
int m, n;
vector<vi> mymap (10, vi(0,0));
int check(string str, int num){
	ff(i,0,sz(str)){
		if(str[i]=='1'){
			// if(mymap[num].find(i + 1) == mymap.end()) return 0;
			if(find(all(mymap[num]), i+1) == mymap[num].end()) return 0;
		}
	}
	return 1;
}


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
	mymap[9] = {1, 2, 3, 4, 6 ,7};
}

int rec(int curr, set<int> possible, vector<string>& vs){
	cout << curr << " " << possible.size() <<  endl;
	if(sz(possible) == 0) {cout << "Error\n"; return 0;}
	else{
		if(curr == n && sz(possible) == 1){ 
			cout << *possible.begin() << endl;
			return 0;
		}
	}
	if(curr == n) {cout << "Error\n"; return 0;}
	set<int> next;
	ff(i, 0, 10){
		if(check(vs[curr], i) && possible.find((i + 9) % 10) != possible.end()){
			next.insert(i);
		}
	}
	rec(curr+1, next, vs);
}
int main(){
	std::ios::sync_with_stdio(false);
	fr;
	int t; cin >> t;
	init();
	for(int tt = 0; tt < t; tt++){
		print (tt+1, "")
		cin >> n; std::vector<string> inp;
		ff(i,0,n){
			string str;
			cin >> str;
			inp.pb(str);
		}

		if(sz(inp) > 9) {inp.resize(9); n = 9;}
		set<int> possible;
		ff(i, 0, 10) possible.insert(i);
		rec(0, possible, inp);
	}
}	
