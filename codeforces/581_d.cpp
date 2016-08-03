#include <bits/stdc++.h>

using namespace std;

int xx[3], y[3];

bool is_perfect_square(int n) {
    if (n < 0)
        return false;
    int root(round(sqrt(n)));
    return n == root * root;
}

int area(){
	int x = 0;
	for(int i = 0 ; i < 3; i++){
		x += xx[i] * y[i];
	}
	// cout << x << endl;
	if(is_perfect_square(x)) return 1;
	else return 0;

}
int check(int exist, int upper){
	// Upper on bit => xth side is there
	if(!area()) return 0;
	int top = 0;
	for(int i = 0; i < 3; i++){
		if(exist & (1 << i)){
			if(upper & (1 << i)) top += xx[i];
			else top += y[i];
		} 
	}

	int x =  __builtin_popcount(upper);
	if(x == 3){
		if(xx[0] == xx[1] && xx[1] == xx[2]) return xx[0];
	}
	else if(!x) if(y[0] == y[1] && y[1] == y[2]) return y[1];
	else if(x == 1){
		int bit_on;
		for(int i = 0 ;i < 3; i++) if(upper & (1 << i) && (exist & (1 << i))){
			bit_on = i; break;
		}

		int flag = 0;
		for(int i = 0 ; i < 3; i++){
			if(i == bit_on) continue;
			if(xx[bit_on] == xx[i] || xx[bit_on] == y[i]); else flag = 1; 
		}	
		if(!flag) return xx[bit_on];
		else return 0;
	}

	else{	
		int on[2]; int p = 0; int bit_off;
		for(int i = 0 ;i < 3; i++) if(upper & (1 << i) && (exist & (1 << i))) on[p++] = i; else bit_off = i;
		if(y[on[0]] == y[on[1]]){
			if(y[bit_off] == xx[on[0]] + xx[on[1]] || xx[bit_off] == xx[on[0]] + xx[on[1]]) return xx[on[0]] + xx[on[1]];
			else return 0;
		}
		else{
			int diff = max(xx[on[0]] , xx[on[1]]) - min(xx[on[0]] , xx[on[1]]);	
			if(diff == xx[bit_off] || diff == y[bit_off]) return xx[on[0]] + xx[on[1]];
			else return 0;
		}
	}
}

int main(){
	ifstream cin("input.txt");
	cout << "Aman\n";
	for(int i = 0; i < 3; i++){
		cin >> xx[i] >> y[i];
	}
	int x = 0;
	for(int i = 1; i < (1 << 3); i++){
		for(int j = 1; j <  (1 << 3); j++){
			x = check(i, j);
			if(x) { i = 10000; break;}
		}
	}
	if(x) cout << "x " << x;
	else cout << 0;
}