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

int rec(string &str, int index, set<string>  &st, vi &dp,  vi &dpp, string last){
	// cout << index << endl;
	if(index < 4) return 0;
	else{
		if(!dp[index - 2]){
			if(index > 5) 
			if(last != str.substr(index - 1, 2)){
				st.insert(str.substr(index - 1, 2));
				rec(str, index - 2, st, dp, dpp, str.substr(index - 1, 2));
				dp[index - 2] = 1;
			}
			else{
				;
				// rec(str, index - 2, st, dp, dpp, last);
			}
		}

		if(!dpp[index - 3]){
			if(last != str.substr(index - 2, 3)){
				st.insert(str.substr(index - 2, 3));
				rec(str, index - 3, st, dp, dpp, str.substr(index - 2, 3));
				dpp[index - 3] = 1;
			}
			else{
				;
				// rec(str, index - 3, st, dp, dpp, last);
			}
			
		}
	}
}

int main(){
	// freopen("input.txt","r",stdin);
	// freopen("A.out","w",stdout);
	std::ios::sync_with_stdio(false);
	string str;
	set <string> st;

	cin >> str;
	// cout << str << endl;
	vi dp(str.size() + 1, 0);
	vi dpp(str.size() + 1, 0);
	for(int i = 0 ; i  < 4; i++) dp[i] = dpp[i]= 1;
	
	rec(str, str.size() -1, st, dp, dpp, string(1, '*'));
	cout << st.size() << endl;
	for(set<string>::iterator it = st.begin(); it != st.end(); it++){
		cout << *it << endl;
	}
	return 0;
}
