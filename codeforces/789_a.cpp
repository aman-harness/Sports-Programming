#include<bits/stdc++.h>

using namespace std;

int main(){
	int n, k; cin >> n >> k;
	vector<int> inp(n, 0);
	for(int i = 0; i < n; i++) cin >> inp[i];
	int ans = 0;
	for(int i = 0; i < n;i++){
		ans += (inp[i] + k - 1) / k;
	}
	cout << (ans + 1) / 2;
	// cout << ans << endl;
}