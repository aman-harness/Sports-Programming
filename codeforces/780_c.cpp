	#include <bits/stdc++.h>

	using namespace std;

	unordered_map<int, int> col;
	unordered_map<int, bool> vis;

	int mod;
	int dfs(int from, vector<vector<int>> &inp, int ccol, int pcol){
		// cerr << from << " " << ccol << " " << pcol << endl;
		if(vis[from]) return 1;

		col[from] = ccol;
		vis[from] = 1;
		int temp = 1;
		for(int i = 0; i < inp[from].size(); i++){
			if(vis[inp[from][i]]) continue;
			if(pcol == (ccol + temp) % mod) temp++;
			dfs(inp[from][i], inp, (ccol + temp++) % mod, ccol);
		}
		return 0;
	}

	int main(){
		vector<vector<int>> inp(200002, vector<int> ());
		int n, a, b; cin >> n;
		for(int i = 0; i < n - 1; i++){
			cin >> a >> b;
			inp[a].push_back(b);
			inp[b].push_back(a);
		}
		int ans = 0;
		for(int i = 1; i <= n; i++){
			// cout << "-- " << inp[i].size() << endl; 
			ans = max(ans, (int)inp[i].size());
		}
		mod = ans + 1;
		cout << ans + 1 << endl;
		dfs(1, inp, 0, -1);
		for(int i = 1; i <= n; i++) cout << col[i] + 1 << " ";
	}