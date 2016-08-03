#include <bits/stdc++.h>

using namespace std;
// ifstream cin("input.txt");

int maxi = 0;
int score[11][11];
int eval(int str, int from, int sum){
	if (str == 2047){
		if (sum > maxi) maxi = sum;
		return 0;
	}
	for(int temp = 0; temp < 11; temp++){
		if(!score[temp][from]) continue;
		if(((1 << (temp)) & str)) continue;
		
		eval(str | (1 << temp), from + 1, sum + score[temp][from]);
	}
	return 0;
}

int main(){
	int n; cin >> n;
	while(n--){
		int i, x;
		ifstream cin("input.txt");
		for(i = 0; i < 11; i++)
			for(int j = 0; j < 11; j++){
				cin >> x;
				score[i][j] = x;
			}
		eval(0, 0, 0);
		cout << maxi << endl;
		maxi = 0;
	}
}
