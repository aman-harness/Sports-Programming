#include <bits/stdc++.h>

using namespace std;

int n, m;
string inp[1000];

map<pair<pair<int, int>, pair<int, int> >, int> mp;
int dfs(int from_x, int from_y, int dir, int cnt){
	// cerr << from_x << " " << from_y << " " << dir << " " << cnt << endl;
	if(cnt > 2) return 0;
	if(mp[{{dir, cnt}, {from_x, from_y}}]) return 0;

	if(from_x < 0 || from_x >= n || from_y < 0 || from_y >= m) return 0;
	if(inp[from_x][from_y] == '*') return 0;

	if(inp[from_x][from_y] == 'T') return 1;

	mp[{{dir, cnt}, {from_x, from_y}}] = 1;

	int x = 0;

	return dfs(from_x + 1, from_y, 0, cnt + (dir != 0)) || 
		dfs(from_x - 1, from_y, 2, cnt + (dir != 2)) || 
		dfs(from_x, from_y + 1, 3, cnt + (dir != 3)) || 
		dfs(from_x, from_y - 1, 1, cnt + (dir != 1));
}

int main(){
	cin >> n >> m;

	for(int i = 0; i < n; i++) cin >> inp[i];

	int st_x, st_y;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(inp[i][j] == 'S'){
				st_x = i, st_y = j;
			}
		}
	}

	int ret = 0;
	for(int i = 0; i < 4; i++){
		ret = ret || dfs(st_x, st_y, i, 0);;
	}
	// cout << dfs(0, 2, 3, 0);

	if(ret == 1) cout << "YES\n";
	else cout << "NO\n";  
}