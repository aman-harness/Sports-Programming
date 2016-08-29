#include <bits/stdc++.h>
using namespace std;

typedef vector<char> vi; 
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

int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[] = {0, 0, 1, -1, -1, 1, 1, -1};
int n, cnt;
int check(int x, int y, vector<string> &vs){
	int cnt = 0;
	ff(i,0,8){
		int new_x = x+dx[i];
		int new_y = y+dy[i];
		if(new_x >= 0 && new_x < n && new_y >= 0 && new_y < n && vs[new_x][new_y] == '*') cnt++;
	}
	return cnt;
}

int bfs(int x, int y, vector<string> &graph, map<ii, int>& mark){
	// cout << x << " " << y << endl;
	mark[{x,y}] = 1;
	int r = check(x, y, graph);
	if(r == 0){
		graph[x][y] = '0';
		ff(i,0,8){
			int new_x = x+dx[i];
			int new_y = y+dy[i];
			if(new_x >= 0 && new_x < n && new_y >= 0 && new_y < n && graph[new_x][new_y] != '*' && !mark[{new_x, new_y}]) bfs(new_x, new_y, graph, mark);
		}
	}
	else{
		graph[x][y] = '0' + r;
	}
}

int solve(){
	cnt = 0;
	cin >> n; string str;
	vector<string> graph;
	ff(i,0,n){
		cin >> str;
		graph.pb(str);	
	}
	map<ii, int> mark;
	ff(i,0,n){
		ff(j,0,n){
			if(graph[i][j] == '.' && !check(i, j, graph)) {cnt++; bfs(i, j, graph, mark);}
		}
	}
	ff(i,0,n){
		ff(j,0,n){
			if(graph[i][j] == '.') {cnt++; graph[i][j] = 'x';}
		}
	}
	return cnt; 
}
int main(){
	std::ios::sync_with_stdio(false);
	fr;
	int t; cin >> t;
	for(int tt = 1; tt <= t; tt++){
		print(tt, solve());
	}

	return 0;
}
