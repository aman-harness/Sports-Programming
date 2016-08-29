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
#define dbgg(x) ff(i,0,sz(x)){ff(j,0,sz(x[0])) cout << x[i][j] << " "; cout << endl;}

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

int main(){
	std::ios::sync_with_stdio(false);
	fr; fo;

	cint(t); ff(tt,0,t){
		cint(n); cint(m); cint(q); int flag = 0 , tm;
		vi vel(m, 0); input(vel, m);
		vii pos(n, {0, 0}); ff(i,0,n) cin >> pos[i].fi >> pos[i].se;

		int max_time = 2;
		// ff(i,0,n){
		// 	int curr = pos[i].fi;
		// 	if(!curr) break;
		// 	int mini = INT_MAX; int dir = curr / abs(curr);
		// 	ff(j,0,m){
		// 		if(vel[j]*dir > 0) mini= min(mini, abs(vel[j]));
		// 	}
		// 	if(mini == INT_MAX) {flag = 0; break;}
		// 	max_time=max(max_time, (abs(curr)+mini-1)/mini);
		// }
		
		vvi temp(max_time+1, vi(m, 0));
		vvi per(n, vi(max_time+1, 0));
		ff(plane,0,n){	
			ff(i,0,max_time) ff(j,0,m) temp[i][j] = inf;
			temp[0][pos[plane].se] = 0;
			ff(i,0,max_time){
				ff(j,0,m){
					ff(k,0,m)
					 temp[i+1][k] = min(temp[i+1][j], temp[i][j] + abs(j-k));
				}
			}
			dbgg(temp);
			cout << "-----------\n";
			ff(i,0,max_time){
				per[plane][i] = temp[i][0];
			}
		}
		int total_amt = 0;
		ff(i,0,max_time){
			total_amt = 0;
			ff(j,0,n){
				total_amt += per[j][i];
			}
			if(total_amt < q){flag = 1; tm = i; }

		}
		if(flag) cout << tm << endl;
		else cout << "Impossible\n";
	}

	return 0;
}
