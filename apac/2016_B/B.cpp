#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii;
// #define ll long long  
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
#define dbg(x) ff(i,0,sz(x)) cout << x[i].fi << "(" << x[i].se << ") ";
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

bool comp(pair<long long, int> a, int b)
{
    if(a.fi < b) return true;
    // else if(a.fi == b.fi && a.se < b.se) return true;
    else return false; 
}

vector< pair<long long, int> > vp;

int main(){
	std::ios::sync_with_stdio(false);
	fr; fo;
	int p, e, l; vi pp, ee, ll;
	cint(t);
	ff(tt, 0, t){
		cin >> p;  cin >> e; cin >> l;
		pp.resize(p, 0); input(pp, p);
		ee.resize(e, 0); input(ee, e);
		ll.resize(l, 0); input(ll, l);
	
		ff(i, 0, e)
			ff(j, 0, l) {vp.pb({ee[i] * ll[j], i});}
		sort(all(vp));
		// dbg(vp); cout << endl;
		cint(q);
		int temp = 0;
		cout<<"Case #"<<tt + 1<<":"<<"\n";
		while(q--){
			temp = 0;
			cint(x); cint(y);
			int gc = __gcd(x, y); x /= gc; y /= gc;
			ff(i, 0, sz(vp)) vp[i].fi *= x;

			// dbg(vp); cout << endl;
			ff(i, 0, p){
				ff(j, 0, e){
					long long key = pp[i] * ee[j] * y;
					// cout << i <<" " << j << " " << key << endl;
					int po = lower_bound(all(vp), key, comp) - vp.begin();
					if(po == sz(vp)) continue;
					else{
						if(vp[po].se != j) {temp = inf; break;}
						else{
							if(po != sz(vp) - 1 && vp[po].se == key) {temp = inf; break;}
						}
					} 
				}
				if(temp == inf) break;
			}
			if(temp == inf) cout << "Yes\n";
			else cout << "No\n"; 

			ff(i, 0, sz(vp)) vp[i].fi /= x;
			
			// pos.clear();
		}
		vp.clear();
	}

	return 0;
}
