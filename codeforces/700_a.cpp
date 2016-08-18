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
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
#define input(s, n) for(int i=0;i<n;i++)cin >> s[i];
#define ff(i, f, t) for(int i=f;i<t;i++)
#define rep(i,n) for(ll i=0;i<n;i++)
#define cint(x) int x; cin >> x;
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

#define thr 1e-6

bool isequal(double x, double y){
	if(abs(x - y) < thr) return 1;
	else return 0;
}

int check(double t, double len, int n, int k, int v1, int v2){
	double trips = ceil(double(n) / k)
	double time_Each = t / trips;
	double dist = time_Each * v2 + (t - time_Each) * v1;
	cout << dist << " - " << len << " "<< t << endl;
	if((dist > len)) return 1;
	else return 0;
}

int main(){
	std::ios::sync_with_stdio(false);
	fr; fo;
	cint(n); double l; cin >> l; cint(v1); cint(v2); cint(k);

	double mini = (double)l / v2, maxi = (double)l / v1;
	while(mini < maxi && !isequal(mini, maxi)){
		// cout << mini << " " << maxi << endl;
		double mid = (mini + maxi) * 0.5;
		if(check(mid, l, n, k, v1, v2) ){
			maxi = mid;
		}
		else mini = mid;
	}
	cout << maxi << endl;

	return 0;
}
