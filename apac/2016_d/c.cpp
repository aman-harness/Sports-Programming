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

void pp(string str){
	int x = str.size();
	str += string(32 - x , '0');
	// cout << str << endl;
	
	cout << ((bitset<8> (str.substr(0, 8))).to_ullong()) << '.';
	cout << ((bitset<8> (str.substr(8, 8))).to_ullong()) << '.';
	cout << ((bitset<8> (str.substr(16, 8))).to_ullong()) << '.';
	cout << ((bitset<8> (str.substr(24))).to_ullong()) << '/';
	cout << x << endl;
}
int CMP(int i, int j, vector<pair<string, int> >& vs, vi& mark){
	cout << mark[2] << endl;
	cout << vs[i].fi << " -- " << vs[j].fi << " " << i << " " << j << endl;
	if(vs[i].fi.size() == vs[j].fi.size()){
		int x = vs[i].fi.size();
		if(vs[i].fi == vs[j].fi) mark[j] = 1;
		else if(vs[i].fi.substr(0, x-1) == vs[j].fi.substr(0, x-1)){
			cout << vs[i].fi << " " << vs[j].fi << endl;
			mark[i] = 1;
			mark[j] = 1;
			vs.pb({vs[i].fi.substr(0, x-1), x});
			mark.pb(0);
			cout << vs.size() << " " << mark.size() <<endl;
		}
	}
	else if(vs[i].fi.size() + 1 == vs[j].fi.size()){
		if (vs[j].fi.substr(0, vs[i].fi.size()) == vs[i].fi && vs[j].fi.back() == '1'){
			mark[i] = 1;
			mark[j] = 1;
			vs.pb({vs[j].fi.substr(0, vs[i].size() - 1), ()vs.size() - 1});
			mark.pb(0);
			cout << mark.size()<< endl;
		}
	}
	else{
		int x = vs[j].fi.find(vs[i].fi);
		if(!x){
			mark[j] = 1;
		}
	}
	return 0;
}

int main(){
	std::ios::sync_with_stdio(false);
	fr;
	cint(t);ff(tt,0,t){
		print(tt+1, "");
		cint(n);
		vector<pair <ii, ii> > inp;
		vi x;
		ff(i,0,n){
			inp.pb({{0,0},{0,0}});
			char temp;
			cin >> inp[i].fi.fi >> temp >> 	inp[i].fi.se >> temp >> inp[i].se.fi >> temp >> inp[i].se.se;
			x.pb(0);
			cin >> temp >> x[i];
			cout << "--- " << inp.size() << endl;
		}
		std::vector< pair <string, int> > vs;

		ff(i,0,n){
			string xx; 
			xx += bitset<8> (inp[i].fi.fi).to_string();
			xx += bitset<8> (inp[i].fi.se).to_string();
			xx += bitset<8> (inp[i].se.fi).to_string();
			xx += bitset<8> (inp[i].se.se).to_string();
			
			// cout << xx << " " << x[i] << endl;
			xx = xx.substr(0, x[i]);
			// cout << xx << " " << x[i] << endl;
			vs.pb({xx, i});
		}
		vi mark(n, 0);
		ff(i,0,n){
			ff(j,0,n){
				if(i==j) continue;
				if(mark[i] || mark[j]) continue;
				if(sz(vs[i].fi) > sz(vs[j].fi)) continue;
				int x = CMP(i, j, vs, mark);
			}
		}
		cout << mark[2] << endl;
		cout << vs.size() << " " << mark.size() <<endl;
		sort(all(vs));
		ff(i,0,sz(mark)){
			cout << "#:"<< i << " " << mark[vs[i].se] << " " << vs[i].fi << endl;
			if(!mark[vs[i].se]) pp(vs[i].fi);
		}
	}

	return 0;
}
