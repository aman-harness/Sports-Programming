#include <bits/stdc++.h>
#include <stdio.h>      /* printf, fopen */
#include <stdlib.h>     /* exit, EXIT_FAILURE */

using namespace std;

int die(){
	cout << "-1";
	exit(0);
}

int main(){

	long long int n, temp, k;
	std::vector<int> a, b;

	set<pair<int, pair<int, int>>> st;

	cin >> n >> k;

	for(int i =0 ; i < n; i++){
		cin >> temp;
		a.push_back(temp);
	}
	for(int i =0 ; i < n; i++){
		cin >> temp;
		b.push_back(temp);
		if(n == 200000) `cout << temp << " ";
	} 

	for(int i = 0; i < n; i++)
	st.insert({a[i] - b[i], {a[i], b[i]}});

	int ans = 0;

	// for(auto x: st){
	// 	cout << x.first << " " << x.second.first << " " << x.second.second << endl;
	// }
	auto it = st.begin();
	for(int i = 0; i < k; i++){
		ans += (it -> second).first;
		// cerr << ans << endl;
		it++;
	}

	while(it != st.end()){
		if(it -> first < 0){
			ans += (it -> second).first;
		}
		else ans += (it -> second).second;
		// cerr << ans << endl;
		it++;
	}
	cout << ans << endl;

	return 0;
}