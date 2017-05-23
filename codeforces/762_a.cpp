#include <bits/stdc++.h>

using namespace std;

int main(){
	long long n, k;
	cin >> n >> k;
	map<long long , bool> mp;
	vector<long long> fact;
	for(long long i = 1; i < sqrt(n); i++){
		if(n % i == 0){
			fact.push_back(i);
			if(n / i != i)
				fact.push_back(n / i);
		}
	}
	long long t = sqrt(n);
	if(t * t == n) fact.push_back(sqrt(n));
	sort(fact.begin(), fact.end());
	// cout << fact.size() << " " << k <<  endl;

	if(fact.size() >= k) cout << fact[k - 1] << endl;
	else cout << -1 << endl;
}
