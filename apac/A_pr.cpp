#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
#define MP make_pair
#define si(n) scanf("%d",&n)
#define slli(n) scanf("%lld",&n);
#define ss(n) scanf("%s",n);

int main(){
	std::ios::sync_with_stdio(false);
	freopen("input.txt","r",stdin);
	freopen("A.out","w",stdout);
	int t; cin >> t;
	for(int tt =0; tt < t; tt++){
		string temp;
		cin >> temp;
		// cout << temp << endl;
		vi dp(temp.size() + 1, 0);
		dp[0] = 1;// if(temp.size() == 1)
		if(temp.size() > 1 && temp[0] == temp[1]) dp[1] = 1;
		else dp[1] = 2;
		for(int i = 2; i < temp.size(); i++){
			if(temp[i] == temp[i - 1]) dp[i] = dp[i - 1];
			else dp[i] += dp[i - 2] + dp[i - 1];
		}
		cout << "Case #" << tt +1 << ": " << dp[temp.size() - 1] << endl;
		dp.clear();
	}
	return 0;
}
