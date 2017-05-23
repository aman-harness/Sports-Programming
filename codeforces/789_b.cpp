#include <bits/stdc++.h>

using namespace std;

int main(){
	long long b, q, l, m;
	cin >> b >> q >> l >> m;
	std::vector<int> inp(m ,0);

	for(int i = 0; i < m; i++) cin >> inp[i];

	set<int> inps; for(auto x : inp) inps.insert(x);
	
	long long it = b;
	int ans = 0;

	// count cases where all the numbers are negaive or positive side
	if(b == 0){
		if(inps.find(0) == inps.end()) cout << "inf" << endl;
		else cout << 0 << endl;
		return 0;
	}
	if(q == 0){
		int ans = 0;
		if(abs(b) > l) {cout << "0" << endl; return 0;}
		if(b != 0 && inps.find(b) == inps.end() && abs(b) <= l) ans++;

		if(inps.find(0) == inps.end()) {cout << "inf" << endl; return 0;}
		cout << ans << endl;
		return 0; 
	}
	if(q == 1){
		if(abs(b) <= l){
			if(inps.find(b) == inps.end()) cout << "inf" << endl;
			else cout << 0 << endl;
			return 0;
		}
		cout << 0 << endl;
		return 0; 
	}
	if(q == -1){
		if(abs(b) <= l){
			if(inps.find(b) == inps.end() || inps.find(-b) == inps.end()) cout << "inf" << endl;
			else cout << 0 << endl;
			return 0;
		}
		cout << 0 << endl;
		return 0; 
	}

	if(b != 0 && q != 0 && q != 1){
		cerr << "-------\n" << endl;
		while(abs(it) <= l){
			if(inps.find(it) != inps.end());
			else ans++;
			it *= q;
		}

		cout << ans << endl;
		return 0;
	} 
}