
#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
#define MP make_pair
#define si(n) scanf("%d",&n)
#define slli(n) scanf("%lld",&n);
#define ss(n) scanf("%s",n);

int main(){
	// freopen("A.in","r",stdin);
	// freopen("A.out","w",stdout);
	std::ios::sync_with_stdio(false);
	string A, B; int count;
	cin >> A >> B;
	for(int i = 0; i < A.size(); i++){
		if (A[i] != B[i]) count++;
	}
	if(count & 1) {
		cout << "impossible" <<endl; return 0;
	}
	else {
		string str;
		for(int i = 0; i < A.size(); i++){
			if(A[i] == B[i]) str.push_back(A[i]);
			else{
				if(count & 1) str.push_back(A[i]);
				else str.push_back(B[i]);
				count--;
			}
			
		}
		cout << str << endl;
	}
	return 0;
}
