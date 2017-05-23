#include <bits/stdc++.h>

using namespace std;

long long kadanes(std::vector<long long> &data){
	// for(long long x : data) cerr << x << " "; cerr << endl;
	// if(data.size() == 0) return long long_MIN;
	// 3 -2 1 -2 

	long long cur_sum = 0, max_sum = 0;
	for(long long i =0 ; i < data.size(); i++){
		if(cur_sum >= 0){
			max_sum = max(max_sum, cur_sum);
			cur_sum += data[i];
		}
		else {
			cur_sum = data[i];
			}
	}
	max_sum = max(max_sum, cur_sum);cerr << max_sum << endl; 

	return max_sum;
}

int main(){
	clock_t tStart = clock();
	long long n, temp; cin >> n;
	std::vector<long long> inp;
	for(long long i = 0; i < n; i++) {cin >> temp; inp.push_back(temp);}

	std::vector<long long> data[3];
	long long count = 0;
	for(long long i = 1; i < n; i++){ 
		if(count % 2 == 0)
			data[0].push_back(abs(inp[i] - inp[i - 1]));
		else 
			data[0].push_back(-abs(inp[i] - inp[i - 1]));

		count++;
	}
	count = 0;
	for(long long i = 2; i < n; i++){ 
		if(count % 2 == 0)
			data[1].push_back(abs(inp[i] - inp[i - 1]));
		else 
			data[1].push_back(-abs(inp[i] - inp[i - 1]));

		count++;
	}
	long long ans = kadanes(data[0]);
	ans = max(ans, kadanes(data[1]));

	cout << ans << endl;
	// prlong longf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
}