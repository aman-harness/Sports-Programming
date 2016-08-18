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

int check(int mid, vector<ii > &vp){
	// for()
	;
}

int main(){
	// freopen("A.in","r",stdin);
	// freopen("A.out","w",stdout);
	std::ios::sync_with_stdio(false);
	int n; cin >> n;
	vector<ii > vp(n + 1, ii(0, 0));
	for(int i = 0 ; i< n; i++){
		int temp1, temp2;
		cin >> temp1 >> temp2;
		vp[i].first = temp1; vp[i].second = temp2;
	}
	sort(vp.begin(), vp.end(), greater< ii > ());
	int lo = 0, hi = 0;
	tr(vp, it){
		hi += it -> second;
	}
	hi += 1;

	while(lo < hi){
		int mid = (lo + hi) / 2;
		int x = check(mid, vp);
		if(x){
			lo = mid;
		}
		else hi = mid;
	}
	return lo;
	return 0;
}
