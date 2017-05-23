#include <bits/stdc++.h>
#include <stdio.h>      /* printf, fopen */
#include <stdlib.h>     /* exit, EXIT_FAILURE */


using namespace std;

int die(){
	cout << "-1";
	exit(0);
}

int main(){
	map<int, int> mp, qq;

	int n, temp;
	cin >> n;
	std::vector<int> a, b;

	for(int i = 0; i < n; i++){
		cin >> temp;
		a.push_back(temp);
		mp[temp]++;
		qq[temp]++;
	}
	
	for(int i = 0; i < n; i++){
		cin >> temp;
		b.push_back(temp);
		mp[temp]++;
	}
	int cnt = 0;
	for(auto it = mp.begin(); it != mp.end(); it++){
		if(it -> second % 2 != 0) die();
		cnt +=  abs(it -> second / 2 - qq[it -> first]);
	}
	cout << cnt / 2<< endl;
	return 0;
}