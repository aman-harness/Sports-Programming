#include <bits/stdc++.h>

using namespace std;

int table[20][20];
int p;
int fun(int x, int set){
	if(!x && !set) return 1;
	long long int ret = 0;
	for(int i = 0; i < p; i++)
		if(table[x - 1][i] && (set & (1 << i))){
			ret += fun(x-1, set & ~(1 << i));
		}
	return ret;
}
int main(){
	// ifstream cin("input.txt");
	int q; cin >> q;
	while(q--){
		int x; cin >> x;
		p = x;
		for(int i = 0; i < x; i++)
			for(int j = 0 ; j < x; j++)
				cin >> table[i][j];
		int set = (1 << x) - 1;
		cout << fun(x, set) << endl;
	}	
}