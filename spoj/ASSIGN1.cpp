#include <bits/stdc++.h>
#define ison(x, i) (((x) >> (i)) & 1)
using namespace std;

int table[20][20];
int p;
int countSetBits(unsigned int n)
{
  unsigned int count = 0;
  while(n)
  {
    count += n & 1;
    n >>= 1;
  }
  return count;
}
long long int dp[(1 << 20)];
long long int fun(){
	dp[0] = 1;
	for(int i = 1 ; i < (1 << p); i++){
		int x = countSetBits(i);
		dp[i] = 0;

		for(int k = 0 ; k < p;k++){
			if(table[x - 1][k] && (i & (1 << k)))
				dp[i] += dp[i & ~(1 << k)];
		}
	}
	return dp[(1 << p) - 1];
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
		cout << fun() << endl;
	}	
}