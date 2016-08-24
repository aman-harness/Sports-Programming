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
#define buli(x) (__builtin_popcntll(x))
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
map <int, int> mark;
int cnt = 0;
int rmv(int from, vi &arr, list <ii> *lst){
	// cout << from << endl;
	if(mark[from]) return 0;
	cnt++;
	mark[from] = 1;
	auto it = lst[from].begin();
	while(it!=lst[from].end()){
		int x = it->fi;
		if(!mark[x])rmv(x, arr, lst);
		it++;
	}
	return 0;
}
int dfs(int from, int dist, list <ii> *lst, vi &arr, int mini){
	// cout << from << endl;
	// cint(xxx);
	mini = arr[from - 1];
	if(mark[from]) return 0;
	if(dist > mini && from > 1){
		rmv(from, arr, lst);
		return 0;
	}
	if(mini > dist + arr[from -1]){
		dist = 0;
		mini = arr[from -1];
	}
	// dist = max(dist, arr[from-1]);
	mark[from] = 1;
	auto it = lst[from].begin();
	while(it!=lst[from].end()){
		int x = it->fi;
		int y = it->se + dist;
		dfs(x, y, lst, arr, mini);
		it++;
	}
}
int main(){
	std::ios::sync_with_stdio(false);
	// fr; fo;
	cint(n); 
	vi arr(n, 0); input(arr, n);
	list<ii> lst[n + 1];
	ff(i, 0, n-1){
		// cout << i<< " " << n << endl;
 		int x, y;cin >> x >> y;
 		// cout << i + 2 << " " << x << " " << y << endl;
 		lst[x].pb({i+2, y});

		lst[i+2].pb({x, y});
		
	}
		// cout << "Function Called\n";
		// ff(from,1,n){cout << from << " - ";auto it = lst[from].begin();
		// 	while(it!=lst[from].end()){
		// 		cout << it-> first << "(" << it->se << ")" << " ";
		// 		it++;
		// 	}
		// 	cout<< endl;
		// }

	dfs(1, -1*inf, lst, arr, inf);
	cout << cnt << endl;
	return 0;
}
