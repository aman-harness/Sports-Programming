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
int main(){
	std::ios::sync_with_stdio(false);
	fr;

	int t; cin >> t;
	for(int tt = 1; tt <= t; tt++){
		cin >> n >> m;
		list <int> lst;
		int temp;
		// cout << n << endl;
		ff(i, 0, n){
			cin >> temp;
			lst.pb(temp);
		}
		// cout << "Here\n";
		int x = 3;
		int flag = 0;
		for(auto it = lst.begin(); it != lst.end(); it++){
			if(flag && it != lst.begin()) it = lst.begin();
			cout  <<flag << "--"<< *it << " " << lst.size() <<endl;
			auto temp = it;
			auto temp2 = ++temp; if(temp2 == lst.end()) {flag = 0;continue;}
			auto temp3 = ++temp; if(temp3 == lst.end()) {flag = 0;continue;} 
			if(*temp2 - *it == m && *temp3 - *it == 2 * m){
				cout << "In --\n";
				it = lst.erase(it, ++temp3);
				// if(it != lst.begin()) it--;
				// if(it != lst.begin()) it--;
				// if(it != lst.begin()) it--;
				it = lst.begin();
				// cout << "Yeah -- "<< *it << endl; 
				flag = 1; continue;
			}
			flag = 0;
		}
		// for(auto it: lst) cout << it << " " ;
		vi in(all(lst));
		ff(i,1, sz(in)) cout << in[i] - in[i-1] << " ";
		print(tt, sz(lst));
	}
	return 0;
}
