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

#define print(cnt,x) cout<<"Case #"<<cnt<<": ";

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
int flag = 0;
int rec(int& cnt, int open, string str){
	// cout << cnt << " " << open << " " << str << endl;
	int from = sz(str);
	// cout << m << " " << n << " "<< flag << endl;
	if(flag || sz(str) > n * 2) return 0;
	if(sz(str) == n * 2){
		// cout << str << endl;
		cnt++;
		if(cnt == m){
			cout << str << endl;
			flag = 1;
			return 0;
		}
	}
	else{

		if(open < n && count(all(str), '(') < n) rec(cnt, open + 1, str + '(');
		if(open) rec (cnt, open - 1, str + ')');
		return 0;
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	fr;
	int t; cin >> t;
	for(int tt = 1; tt <= t; tt++){
		cin >> n >> m;
		flag = 0;
		print(tt, "");
		int cnt = 0;
		rec(cnt, 0, "");
		if(!flag) cout << "Doesn't Exist!\n";
	}

	return 0;
}
