#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii;
#define ll long long  
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
#define mp make_pair
#define si(n) scanf("%d",&n)
#define slli(n) scanf("%lld",&n);
#define ss(n) scanf("%s",n);
#define input(s, n) for(int i=0;i<n;i++)cin >> s[i];
#define ff(i, f, t) for(int i=f;i<t;i++)
#define cint(x) int x; cin >> x;

#define thr 1e-6

bool isequal(double x, double y){
	if(abs(x - y) < thr) return 1;
	else return 0;
}

double poww(double len, int powww){
	if(powww == 1) return len;
	else{
		if(powww % 2) return len * poww(len, powww -1);
		else{
			double x = poww(len, powww/2);
			return x * x;
		}
	}
}

int main(){
	#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	std::ios::sync_with_stdio(false);

	cint(t);
	ff(tt, 0, t){
		std::cout << std::fixed;
		std::cout << std::setprecision(10);
		cout << "Case #" << tt + 1 << ":" << endl;
		cint(n); cint(m);
		vi arr(n, 0); input(arr, n);
		ff(i, 0, m){
			cint(l); cint(r);
			int mini = INT_MAX; int maxi = INT_MIN;
			ll vol = 1;
			ff(j, l, r + 1){
				vol *= arr[j];
				mini = min(mini, arr[j]);
				maxi = max(maxi, arr[j]);
			}
			cout << "vol "<< vol << endl;
			double lo = (double)mini;
			double hi= (double)maxi;
			// cout << lo << " " << hi << endl;
			while(lo < hi && !isequal(lo, hi)){
				double mid = lo * 0.5 + hi * 0.5;
				// cout << lo << " " << hi << " " <<  mid << endl;
				// if(isequal(mid, lo) || isequal(mid, hi)) break;
				double new_vol = poww(mid, r - l + 1);
				if(isequal(new_vol, vol)) {lo = mid; break;}
				else if(new_vol < vol) lo = mid;
				else hi = mid;
			}
			cout << std::setprecision(8) << lo << endl;
		}
	}

	return 0;
}
