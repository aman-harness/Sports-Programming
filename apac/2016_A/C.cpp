#include <bits/stdc++.h>

using namespace std;
typedef vector<long long unsigned int> vi; 
typedef vector<vi> vvi; 
typedef pair<long long unsigned int,long long unsigned int> ii;
#define ll long long unsigned int  
#define sz(a) long long unsigned int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
#define mp make_pair
#define si(n) scanf("%d",&n)
#define slli(n) scanf("%lld",&n);
#define ss(n) scanf("%s",n);
#define input(s, n) for(long long unsigned int i=0;i<n;i++)cin >> s[i];
#define ff(i, f, t) for(long long unsigned int i=f;i<t;i++)
#define cint(x) long long unsigned int x; cin >> x;
#define fi first
#define se second
#define dbg(x) ff(i,0,sz(x)) cout << x[i] << " ";


int main(){
	#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	std::ios::sync_with_stdio(false);
	cint(t);
	ff(tt, 0, t){
		cout << "Case #" << tt + 1 << ": " << endl;
		map<ii, long long unsigned int> mpp, my;
		long long unsigned int count = 0;
		cint(n); cint(m);
		vi mark(m, 0);
		vvi dp(n, vi(n, (ll)100000000000)); vvi dist(n, vi(n, (ll)100000000000));
		vector< pair<ii, long long unsigned int> > vp(m, mp(mp(0, 0), 0));
		ff(i, 0, m){
			long long unsigned int x, y, z;
			cin >> x >> y >> z;
			vp[i].fi.fi = x; vp[i].fi.se = y; vp[i].se = z;
			if(dist[x][y] > z)
				dist[x][y] = z;
			if(dist[y][x] > z)
				dist[y][x] = z;
			if(mpp[mp(x, y)] == z || mpp[mp(y, x)]){
				continue;
			}
			if(x < y){
				if(!mpp[mp(x, y)]) mpp[mp(x, y)] = z;
				else mpp[mp(x, y)] = min(z, mpp[mp(x, y)]);
			}
			else {
				if(!mpp[mp(y, x)]) mpp[mp(y, x)] = z;
				else mpp[mp(y, x)] = min(z, mpp[mp(y, x)]);
			}
		}
		ff(i, 0, n) dist[i][i] = 0;
		ff(k, 0, n){
			ff(i, 0, n){
				ff(j, 0, n){
					if(dist[i][j] > dist[i][k] + dist[k][j]){
						dist[i][j] = dist[i][k] + dist[k][j];
					}
				}
			}
		}

		long long unsigned int flag = 0;
		ff(i, 0, m) if(dist[vp[i].fi.fi][vp[i].fi.se] != vp[i].se) {cout << i  << endl;}
		if(flag) cout << endl;
	}
	return 0;
}
