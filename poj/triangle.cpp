// #include <bits/stdc++.h>
#include<iostream>
#include <vector>

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


int main(){
	#ifdef LOCAL
	freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	#endif

	cint(n);
	
	vvi dp;
	ff(i, 0, n){
		vi row(i + 1, 0);
		ff(j, 0, row.size()) cin >> row[j];
		dp.pb(row);
		row.clear();
	}
		// ff(i, 0, sz(dp)){
		// 	ff(j, 0, sz(dp[i])) cout << dp[i][j] << " "; cout << endl;
		// }
	for(int i = dp.size() - 1; i > 0; i--){
		for(int j = 0 ; j < dp[i].size() - 1; j++){
			dp[i - 1][j] += max(dp[i][j], dp[i][ j + 1]);
		}
	}
	// ff(i, 0, sz(dp)){
	// 	ff(j, 0, sz(dp[i])) cout << dp[i][j] << " "; cout << endl;
	// }
	cout << dp[0][0] << endl;
	std::ios::sync_with_stdio(false);
	return 0;
}
