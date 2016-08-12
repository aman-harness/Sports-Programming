
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
#define si(n) int n; scanf("%d",&n)
#define slli(n) scanf("%lld",&n);
#define ss(n) scanf("%s",n);

int m, n;
int coins_req[100][100], attack_power[100][100];
int max_level[100], curr_level[100];

int fun(int money, int from, int count){
	int ret = 0;
	int flag = 0;
	for(int i = 0 ; i < n; i++){
		if(count > 8) break;
		if(curr_level[i] == max_level[i])
			continue;
		if(coins_req[i][curr_level[i]] <= money) {
			flag = 1; 
			break;}
	}
	if(!flag){
		vi xx;
		ret = 0;
		for(int i = 0; i < n; i++){
			// ret += attack_power[i][curr_level[i]];
			xx.pb(attack_power[i][curr_level[i]]);
		}
		sort(xx.begin(), xx.end(), greater<int>());
		for(int i = 0; i < 8; i++) ret += xx[i];
		return ret;
	}

	int temp[100]; for(int i = 0 ; i < 100; i++) temp[i] = 0; 
	for(int i = from ; i < n; i++){
		if(curr_level[i] < max_level[i] && coins_req[i][curr_level[i]] <= money) {
			curr_level[i] += 1;
			temp[i] = fun(money - coins_req[i][curr_level[i] - 1], i, count + 1);
			curr_level[i] -= 1;
		}
		else temp[i] = 0;
	}
	ret = 0;
	for(int i = 0; i < n; i++){
		ret = max(ret, temp[i]);
	}
	return ret;

}

int main(){
	freopen("input.txt","r",stdin);
	// freopen("A.out","w",stdout);
	std::ios::sync_with_stdio(false);
	int t; cin >> t;
	for(int tt = 0; tt < t; tt++){
		cin >> m >> n;
		for(int i = 0 ; i < n; i++){
			cin >> max_level[i] >> curr_level[i];
			curr_level[i]--; max_level[i]--;
			for(int j = 0; j <= max_level[i]; j++) cin >> attack_power[i][j];
			for(int j = 0; j < max_level[i]; j++) cin >> coins_req[i][j];
		}
		// if(m == 20){
		// for(int i = 0 ; i < n; i++) cout << curr_level[i] << " ";
		// 	cout << endl;
		// }
		printf("Case #%d: %lld\n", tt + 1, fun(m, 0, 0)); ;
		// max = 0;
	}
	
	return 0;
}
