#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii;
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

int n, m;

int dijk(int to, int tim, vector<ii> &vii, vvi &tm){
	// cout << from << " " << tim << endl;
	vi D(n, inf);
	priority_queue<ii,vector<ii>, greater<ii> > Q;
	D[1] = tim;
	// cout << tim << endl;
	Q.push({tim, 1});
	while(!Q.empty()){
		ii top = Q.top();
		Q.pop();
		int v = top.se, d = top.fi;
		// if(to == 2) cout << v << " - "<< d << endl; 
		// cout << v << endl;
		if(v == to) break;
		if(d <= D[v]){
			ff(i, 0, m){
				if(vii[i].fi == v || vii[i].se == v){
					int v2 = vii[i].se;
					if(vii[i].se == v) v2 = vii[i].fi;
					int cost = tm[i][(d + 1) % 24];
					if(D[v2] > d + cost){
						D[vii[i].se] = d + cost;
						Q.push({d + cost, v2});
					}
				}
			}
		}
	}
	if(D[to] != inf) return D[to] - tim;
	else return -1;
}

int main(){
	std::ios::sync_with_stdio(false);
	fr; fo;
	cint(t);
	ff(tt, 0, t){
		cin >> n >> m; cint(k);
		n++;
		vector<ii> vii(m, {0,0}); vvi tm(m,vi(24, 0));
		ff(i, 0, m){
			cin >> vii[i].fi >> vii[i].se;
			ff(j, 0, 24) cin >> tm[i][j];
		}
		// cout << "--- \n";
		cout<<"Case #"<<tt + 1<<": ";
		ff(i, 0, k){
			cint(fff); cint(tim);
			int ret = dijk(fff, tim, vii, tm);
			// if(!i) print(tt + 1, ret);
			cout << ret << " ";
		}
		cout << endl;
	}

	return 0;
}
