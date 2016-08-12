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
int mod = 1000000009;

long long retu(int n){
	// cout << n << endl;
    long long ret = 1;
    long long a = 2;
    while (n > 0) {
        if (n & 1) ret = ret * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return ret;
}

int main(){
	// freopen("A.in","r",stdin);
	// freopen("A.out","w",stdout);
	// std::ios::sync_with_stdio(false);
	long long int correct, wrong, total, k, added, n;
	cin >> total >> correct >> k;
	wrong = total - correct;
	if(total / k < total - correct) cout << correct << endl;
	else{
		long long int up_right = (k -1) * wrong;
		up_right += correct - up_right - ((correct - up_right) / k) * k;
		// cout << up_right << endl;	
		// added = (k -1) * wrong + up_right;
		// cout << correct - up_right<< endl;	
		long long int left = correct - up_right; 
		long long int sum = 0, i = 1;
		// while(i <= left){
		// 	// cout << sum << endl;
		// 	sum += k;
		// 	sum *=2;
		// 	sum %= mod;
		// 	i+= k;
		// }
		// cout << left << endl;
		sum = (retu(left / k + 1) + mod - 2) % mod;
		sum *= k;
		sum += up_right;
		cout << sum % mod << endl;
	}
	return 0;
}
