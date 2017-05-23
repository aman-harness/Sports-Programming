#include <bits/stdc++.h>

using namespace std;

std::vector<int> v;

int check(int cnt, string& a, string &b){
	vector<int> mark(a.size(), 1);

	for(int i = 0; i < cnt; i++) mark[v[i] - 1] = 0;

	int x = 0, y = 0;
	while(x < a.size() && y < b.size()){
		if(!mark[x]){
			x++; continue;
		}
		// cout << x << " " << y << a[x] << " " << b[y] << endl;
		if(a[x] == b[y]){
			x++; y++; continue;
		}
		else{
			x++;
		}
	}
	if(y >= b.size()) return 1;
	else return 0;
}

int main(){
	string a, b;
	cin >> a >> b;
	int temp;

	for(auto z : a){
		cin >> temp; v.push_back(temp);
	}

	int right = a.size(), left = 0;

	while(left < right - 1){
		int mid = right + left; mid /= 2;
		// cout << check(mid, a, b) << " " << left << " " << right << " " << mid << endl;
		if(check(mid, a, b)) left = mid;
		else right = mid;
	}

	cout << left << endl;

}