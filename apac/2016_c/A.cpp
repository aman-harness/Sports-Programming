#include <bits/stdc++.h>
using namespace std;

#define ll long long  
typedef vector<ll> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii;

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
#define cint(x) ll x; cin >> x;

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

bool comp(pair<ll, string> v1, pair<ll, string> v2){
	if(v1.fi > v2.fi) return true;
	else if(v1.fi==v2.fi && v1.se<v2.se) return true;
	else return false;
}

int main(){
	std::ios::sync_with_stdio(false);
	fr; fo;

	cint(t);
	map<string, vi> m;
	ff(tt,0,t){
		m.clear();
		print(tt + 1, "");
		cint(p); vi places(p, 0);
		input(places, p);
		cint(n);
		ff(i, 0, n){
			cint(w);
			ff(j, 0, p){
				string name; cin >> name;
				m[name].pb(places[j] * w);
			}
		}
	
		cint(cnt);
		vector<pair<ll, string> > ret;
		for (map<string, vi>::iterator it=m.begin(); it!=m.end(); ++it){
	    	vi &ref = it->second;
	    	sort(all(ref), greater<ll>());
	    	ll sum = 0;
	    	ff(k,0, (min((ll)ref.size(), cnt))){
	    		sum += ref[k];
	    	}
	    	ret.pb({sum, it->fi});
	    }
	    sort(all(ret), comp);
	    int rank = 1;
	    cout << rank << ": " << ret[0].second << endl;

	    ff(i,1,sz(ret)){
	    	if(ret[i].fi !=  ret[i-1].fi) rank = i + 1;
	    	cout << rank << ": " << ret[i].second << endl;
	    }
	}
	return 0;
}
