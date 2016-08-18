#include <bits/stdc++.h>

using namespace std;
typedef vector<long long > vi; 
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

ll hcf(ll a, ll b) {
   if (b == 0) {
      return a;
   } else {
      return hcf(b, a % b);
   }
}


int main(){
	#ifdef LOCAL
	freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	#endif
	std::ios::sync_with_stdio(false);

	ll summ = 0;
	cint(n);
	vi vec(n, 0); input(vec, n);
	sort(all(vec));
	vi sum(n, 0); sum[0] = 0;
	ff(i, 1, n) {sum[i] += vec[i] - vec[0] + sum[i - 1];}

	summ += 2 * sum[n - 1];
	ff(i, 1, n){
		summ += 2 * (sum[n - 1] - sum[i] - (n - 1 - i) * (vec[i] - vec[0]));
	}
	ff(i, 0, n) summ += vec[i];
	ll hc = hcf(summ, n);
	cout << summ / hc << " " << n / hc<< endl;

	return 0;
}
