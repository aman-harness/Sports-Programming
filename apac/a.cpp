
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

int maxi = 0;
int count_diff(string str){
	set<int> st;
	for(int i = 0 ; i < str.size(); i++){
		if(str[i] == ' ') continue;
		st.insert(str[i]);
	}
	if (st.size() > maxi) maxi = st.size();
	return st.size();
}

pair <string, ii> strr[105];
int main(){
	freopen("input.txt","r",stdin);
	// freopen("A.out","w",stdout);
	int t; cin >> t; for(int k = 0; k < t; k++){
		int n;
		maxi = 0;
		cin >> n;
		char c;
		string s;
		getline(cin,s);
		for(int i = 0 ; i < n; i++){

			// cout << i <<"th" <<endl;
			getline(cin,strr[i].first);
			strr[i].second.second = i;
			strr[i].second.first = count_diff( strr[i].first);
		}

		sort(strr, strr + n);
		for(int i = 0 ; i < n; i++){
			if(strr[i].second.first == maxi){
				printf("Case #%d: ", k + 1); cout << strr[i].first << endl; 
				break;
			}
		}
	}
	return 0;
}
