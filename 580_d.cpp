#include <bits/stdc++.h>

using namespace std;

long long int m,n, k, sat[20], maxi;
std::vector< pair<long long int, long long int> > vi[20];
int countSetBits(long long int n)
{
  long long int count = 0;
  while(n)
  {
    count += n & 1;
    n >>= 1;
  }
  return count;
}

int cache[1 << 18][18];
long long int calc(long long str, long long value, long long prev){
    
	long long x = __builtin_popcount(str);
	if (x == m){
		if ( value > maxi ) maxi = value;
		if(cache[str][prev] != -1) return cache[str][prev];

// 		cout << "=======================================\n";
		return value;
	}
    
	for(int i = 0; i < n; i++){
		if(!(str & (1 << i)) &&  prev == -1)
			cache[str | (1 << i)][i] = calc(str | (1 << i), value + sat[i], i);
		else if(!(str & (1 << i)) && (prev + 1)){
		    
		    int flag = 0;

			for(int j = 0; j < vi[prev].size(); j++){

				if(vi[prev][j].first == (i)){
				    flag = 1;
				    // cout << "Here\n";
					cache[str | (1 << i)][i] = calc(str | (1 << i), value + sat[i] + vi[prev][j].second, i);
					break;
				}
			}
			if(!flag)
				cache[str | (1 << i)][i] = calc(str | (1 << i), value + sat[i], i);
		}
	}
	return value;

}

int main(){
	cin >> n >> m >> k;
	for(int i = 0; i < n; i++){
		cin >> sat[i];
	}
	int a, b, c;
	for(int i = 0; i < k; i++){
		cin >> a >> b >> c;
		vi[a - 1].push_back(make_pair(b - 1, c));
	}
	calc(0, 0, -1);
	for(int f=0;f < (1 << 18); f++)
		for(int h = 0; h < 18; h++)
			cache[f][h] = -1;
	
	cout << maxi << endl;
}