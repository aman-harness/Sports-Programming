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

	long long int n, temp, k;

	string str;
	cin >> str >> k;

	int x = count(str.begin(), str.end(), '0');

	if(x < k) {cout << str.size() -1 << endl; return 0;}
	
	int ans = 0;
	for(auto it = str.rbegin(); it !=str.rend(); it++){
		if(*it == '0') {
			k--;
		}
		else ans++;

		if(!k) break;
	}
	cout << ans << endl;
	return 0;
}