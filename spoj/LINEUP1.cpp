#include <bits/stdc++.h>

using namespace std;
int players= 11;
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

int maxi = 0;
int dp[(1 << 11) - 1];
int score[11][11];
int eval(){
	dp[0] = 0;
	for(int i = 1; i < (1 << players); i++){
		int count = countSetBits(i);
		dp[i] = 0;
		for(int k=0; k<players; k++){
			if(((1 << k) & i) && score[count-1][k]){
				if((i & ~(1 << k) && dp[i & ~(1 << k)]) || !(i & ~(1 << k))) 
				dp[i] = max(dp[i], dp[i & ~(1 << k)] + score[count-1][k]);
			}
		}
	}
	return dp[(1 << players) - 1];
}

int main(){
	// ifstream cin("input.txt");
	int n; cin >> n;

	while(n--){
		int i, x;
		for(i = 0; i < players; i++)
			for(int j = 0; j < players; j++){
				cin >> x;
				// if(!x) {x = INT_MIN; cout << x << endl;}
				score[i][j] = x;
			}
		cout << eval() << endl;
	}
}
