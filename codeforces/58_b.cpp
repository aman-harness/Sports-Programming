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
	// freopen("A.in","r",stdin); 
	// freopen("A.out","w",stdout);
	std::ios::sync_with_stdio(false);
	int n, temp; cin >> n;
	if(n == 1){
		cout << 1 << endl;
		return 0;
	}
	temp = n;
	vi arr(n + 1, 0);
	arr[1] = 1;
	for(int i = 2; i <= temp; i++){
		if(temp % i == 0){
			arr[i]++;
			temp /= i;
			i--;
		}
	}
	vector<int> ret;
	ret.pb(1);
	int ii = 1;
	int i = 2;
	while(ii < n){
		if(arr[i]){
			arr[i]--;
			ii *= i;
			ret.pb(ii);
			i--;
		}
		i++;
	}
	sort(ret.begin(), ret.end(), greater<int>());
	for(int j = 0; j < ret.size(); j++){
		cout << ret[j] << " ";
	}
	cout<< endl;
	return 0;
}
