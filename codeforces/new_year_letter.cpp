#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii;
typedef vector<ii> vii;
#define ll long long  
#define sz(a) int((a).size()) 
#define mp make_pair
#define pb push_back 
#define fi first
#define se second
#define buli(x) (__builtin_popcountll(x))
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
#define input(s, n) for(int i=0;i<n;i++)cin >> s[i];
#define ff(i, f, t) for(int i=f;i<t;i++)
#define rep(i,n) for(ll i=0;i<n;i++)
#define cint(x) int x; cin >> x;

#define what_is(x) cerr << #x << " is " << x << endl;
#define dbg(x) ff(i,0,sz(x)) cout << x[i] << " ";
#define dbgg(x) ff(i,0,sz(x)){ff(j,0,sz(x[0])) cout << ff[i][j] << " "; cout << endl;}

#define print(cnt,x) cout<<"Case #"<<cnt<<": "<<x<<"\n";

#ifdef LOCAL
#define fr freopen("input.txt","r",stdin)
#define fo freopen("output.txt","w",stdout)
#else
#define fr 1
#define fo 1
#endif

#define inf 1e9
const double eps = 1e-7;
int k, x, n, m;

int output(int a, int b, int c, int d){
	what_is(a);
	what_is(b);
	what_is(c);
	what_is(d);
	string x = "";
	// if(a == 0 || a == 3) x.pb('C');
	// else if(n > 2*c )x.pb('Q');
	while(c--) x += (string("AC"));
	if(a == 1||a==3) x.pb('A');
	while(sz(x) < n-1) x = 'R' + x;
	if((a==0||a==3) && sz(x) < n) x = 'C' + x;
	else if(sz(x) < n) x = 'R' + x;
	cout << x << " " << endl;

	string y = "";
	// if(a == 0 || a == 3) x.pb('C');
	// else if(n > 2*c )x.pb('Q');
	while(d--) y += (string("AC"));
	if(b == 1||b==3) y.pb('A');
	while(sz(y)< m-1) y = 'R' + y;
	if((b==0||b==3) && sz(y) < m) y = 'C' + y;
	else if(sz(x) < n) y = 'R' + y;
	cout << y << endl;
	return 0;
}
int solve(){
	// Case 0 -- starting with 'C' bas.
	// Case 1 -- Ending with 'A' bas;
	// Case 2 -- None.
	// Case 3 -- Starting and Ending with C and A res.
	// max AC strings possible in both the cases.
	int a = m / 2, b = n / 2;
	ff(c,0,4){
		ff(d,0,4){
			ff(i,0,a+1){
				ff(j,0,b+1){
					vi dp(k+1, 0);
					dp[1] = i;
					dp[2] = j;
					ff(p,3,(k+1)){
						dp[p] += dp[p-1]+dp[p-2];
						
						if(p == 3){
							if((c==1||c==3)&&(d==0||d==3))
								dp[p]+=1;
						}
						else if(!(p&1)){
							if((d==1 || d==3) && (c == 0 || c== 3)){
								dp[i] += 1;
							}
						}
						else{
							if(d==3) dp[i] += 1;
						}
					}
					if(dp[k] == x){
						output(c, d, i, j);
						return 0;
					}
				}
			}
		}
	}
	cout << "Happy new year!" << endl;
}
int main(){
	std::ios::sync_with_stdio(false);
	// fr; fo;

	cin >> k >> x >> n >> m;
	solve();

	// ff(i,0,)

	return 0;
}
