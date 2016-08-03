#include <bits/stdc++.h>

using namespace std;

int main(){
	int x, y, z;
	cin >> x  >> y >> z;

	if(z == x + 1) cout << "NO" << endl;
	else if((z - x) % y != 0 && (z - x) % y != 1) cout << "NO" << endl;
	else cout << "YES" << endl;
	return 0;
}