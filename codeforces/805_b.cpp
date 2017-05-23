#include <bits/stdc++.h>

using namespace std;

int main(){
	int a;
	cin >> a;

	string ret = "";


	for(int i = 0; i < a; i++){
		if((i / 2) % 2 == 0) ret += 'a';
		else ret += 'b'; 
	}
	cout << ret << endl;

	return 0;
}