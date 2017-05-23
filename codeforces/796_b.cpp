#include <bits/stdc++.h>

using namespace std;

int main(){
	std::ios::sync_with_stdio(false);
	int n, m, k, temp, a, b;
	cin >> n >> m >> k;
	vector<bool> mp(n +2, 0);
	for(int i= 0;i < m; i++){
		cin >> temp;
		mp[temp] = 1;
	}
	int curr = 1;
	int flag = 0;
	if(mp[curr] == 1) flag = 1;
	for(int i = 0; i < k; i++){
		cin >> a >> b;
		cerr << a << " " << b << " " << curr << endl;

		if(flag) break;
		if(a == curr) curr = b;
		else if(b == curr) curr = a;
		if(mp[curr]) break;
	}
	cout << curr << endl;
}