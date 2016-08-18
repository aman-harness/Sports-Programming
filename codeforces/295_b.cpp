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
	freopen("input.txt","r",stdin);
	// freopen("A.out","w",stdout);
	std::ios::sync_with_stdio(false);
	int n, temp;
	cin >> n;
	vi del(n, 0);
	vvi graph(n, del), dist(n, del), dp(n, del);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j ++){
			cin >> graph[i][j];
			dist[i][j] = graph[i][j];
		}
	}

	for(int i = 0 ; i < n ; i++){
		cin >> del[i];
		del[i] -= 1;
	}

	for(int k = 0 ; k < n; k++){
		for(int i = 0 ; i < n; i++){
			for(int j = 0 ; j < n; j++){
				if(dist[i][j] > dist[i][k] + dist[k][j]){
					dist[i][j] = dist[i][k] + dist[k][j];
					dp[i][j] = k;
				}
			}
		}
	}
	long long sum = 0;
	cout << n << endl;
	for(int i = 0; i < n; i++){
		for(int j = 0 ; j < n; j++){
			cout << dist[i][j] << "(" << dp[i][j] << ") ";
			sum += dist[i][j];
		}
		cout << endl;
	}

	for(int k = 0; k < 1; k++){
		cout << sum << " - ";
		int index = del[k];
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if((i == index || j == index)){
					sum -= dist[i][j];
					dist[i][j] = 10000000;
				}
				else if(dp[i][j] == index){
					// cout << i << j << dist[i][j] << endl;
					sum -= dist[i][j];
					dist[i][j] = 10000000;
					for(int l = 0 ; l < n; l++){
						if(l == index) continue;
						if(dist[i][j] > dist[i][l] + dist[l][j]){
							dist[i][j] = dist[i][l] + dist[l][j];
							dp[i][j] = l;
						}
					}
					if(dist[i][j] == 10000000);
					else sum += dp[i][j];
					cout << i << " " << j << " " << dist[i][j] <<" " << dp[i][j] << endl;
				}
			}
		}
	}


	return 0;
}
