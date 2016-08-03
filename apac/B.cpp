
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


int tx[] = {1, 0, 0, -1};
int ty[] = {0, -1, 1, 0};
map<ii, int> mp;
int a, b;
int gr[50][50];
int vis[50][50];
int out[50][50];

int check(int x, int y, int height){
	// cout << x << " "<< y << " "<< height << endl;
	if(x < 0 || y < 0 || x >= a || y >= b) return 0;
	else if (gr[x][y] > height) return 1;
	else if (gr[x][y] < height) return 0;
	if(mp[MP(x, y)]) return 1;
	else if(gr[x][y] == height){
		// cout << "Mapping --" << x << y <<height <<endl;
		mp[MP(x, y)] = 1;
		bool xx[4];
		for(int i = 0 ; i < 4; i++){
			// cout << " -- "  << x << " "<< y << " "<< height << endl;
			xx[i] = check(x + tx[i], y + ty[i] , height);
			if(!xx[i]) return 0;
		}
		return 1;
	}
}

int fun(int x, int y){
	bool res;
	int flag = 0;
	for(int i = 0; i < a; i++){
		for(int j = 0 ; j < b; j++){
			if(vis[i][j]) continue;
			for(int k = 0; k < 4; k++){
				res = check(i + tx[k], j + ty[k], gr[i][j]);
				if(res == 0){
					vis[i][j]= 1;
					out[i][j] = gr[i][j];
					flag = 1;
					mp.clear();
					break;
				}
			}
			if(flag){flag = 0; continue;}
			else{
				if(i == 1 && j == 1) cout << mp.size() << endl;
				mp[MP(i, j)] = 1;
				for(std::map<ii,int >::iterator iter = mp.begin(); iter != mp.end(); ++iter){
					ii k =  iter->first;
					// cout << "----" <<k.first << k.second <<endl;
					if(!vis[k.first][k.second]) out[k.first][k.second] = gr[i][j] + 1;
					vis[k.first][k.second] = 1;
					// cout << out[k.first][k.second] <<endl;
				}
				mp.clear();
			}
		}
	}
}
int main(){
	freopen("input.txt","r",stdin);
	// freopen("A.out","w",stdout);
	std::ios::sync_with_stdio(false);
	int t; cin >> t;
	for(int tt = 0 ; tt < t; tt++){
		int x, y; cin >> x >> y;
		a = x; b = y;
		for(int i = 0; i < x; i++){
			for(int j = 0; j < y; j++){
				cin >> gr[i][j];
			}
		}
		cout << "Input Complete\n";
		fun(x, y);
		for(int i = 0; i < x; i++){
			for(int j = 0; j < y; j++){
				cout << out	[i][j] << " ";
			}
		cout << endl;
		}
	}

	return 0;
}
