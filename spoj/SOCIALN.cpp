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
	// freopen("input.txt","r",stdin);
	// freopen("A.out","w",stdout);
	std::ios::sync_with_stdio(false);
	int t; cin >> t;
	for(int tt = 0 ; tt < t; tt++){
		long long int arr[51][51];
		long long int dist[51][51];

		int n;
		string str; cin >> str;
		n = str.size();

		for(int i = 0 ; i < n ; i++)
			for(int j = 0 ; j  < n; j++){
				dist[i][j] = INT_MAX;
				arr[i][j] = 0;
			}

		for(int i = 0 ; i < n; i++){
			dist[i][i] = 0;
		}

		
		for(int i = 0 ; i < n; i++){
			if(i) cin >> str;
			for(int j = 0 ; j < n; j++){
				if(str[j] == 'Y'){
					arr[i][j] = 1;
					dist[i][j] = 1;
				}
			}
		}

		for(int k = 0; k <  n; k++){
			for(int i = 0 ; i < n; i++){
				for(int j = 0 ; j < n ; j++){
					if(dist[i][j] > dist[i][k] + dist[k][j])
						dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
		int temp = 0;
		int maxi = 0;
		for(int i = 0 ; i < n; i++){
			int count = 0;
			for(int j = 0; j < n; j++){
				if(dist[i][j] == 2){
					count++;
				}
			}
			if(count > maxi){
				maxi = count;
				temp = i;
			}
			// cout << endl;
		}
		cout << temp <<  " " << maxi << endl;
	}
	
	return 0;
}
