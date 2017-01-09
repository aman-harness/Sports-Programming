/*
Author : Aman Singh
Solution for problem code Santa Claus and Tangerines.
*/

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
#define sz(a) int((a).size())
// #define mp make_pair
#define pb push_back
#define fi first
#define se second
#define buli(x) (__builtin_popcountll(x))
#define all(c) (c).begin(),(c).end()
#define foreach(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define input(s, n) for(int i=0;i<n;i++) cin >> s[i];
#define F(i, f, t) for(int i=f;i<t;i++)
#define R(i,n) for(ll i=0;i<n;i++)
#define _ << ' ' <<

#define print(cnt,x) cout<<"Case #"<<cnt<<": "<<x<<"\n";

template <class T>  inline void smax(T &x,T y){ x = max((x), (y));}
template <class T>  inline void smin(T &x,T y){ x = min((x), (y));}

#ifdef LOCs
#define fr freopen("in.txt","r",stdin)
#define fo freopen("out.txt","w",stdout)

#define error(x) cerr << #x << " = " << (x) <<endl
#define Error(a,b) cerr<<"( "<<#a<<" , "<<#b<<" ) = ( "<<(a)<<" , "<<(b)<<" )\n";
#define errop(a) cerr<<#a<<" = ( "<<((a).x)<<" , "<<((a).y)<<" )\n";
#define dbg(x) F(i,0,sz(x)) cout << x[i] << " ";
#define dbgg(x) F(i,0,sz(x)){F(j,0,sz(x[0])) cout << x[i][j] << " "; cout << endl;}
#else
#define fr 1
#define fo 1
#define error(x)
#define Error(a,b)
#define errop(a)
#define dbg(x)
#define dbgg(x)
#endif

inline void sc(int &x)
{
	bool f=0; x=0; char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') { f=1; c=getchar(); }
	while(c>='0' && c<='9') { x=x*10+c-'0'; c=getchar(); }
	if(f) x=-x; return;
}

void sc(char &x) {scanf("%c", &x); }
void sc(int &x,int &y) { sc(x); return sc(y); }
void sc(int &x,int &y,int &z) { sc(x); sc(y); return sc(z); }

#define inf 2e9
const double eps = 1e-7;

#define N 2000005
int t, n, k, i, j, m, x;
int inp[N], A[N], B[N];
char str[N];
map<string, int> mp;
int check(string & from, string & to){
	// return 0;
	int x = 0;
	if(from == to) return 1;
	while(from.find(to, x) != -1){
		int pos = from.find(to, x);
		if(pos == 0 && !isalpha(from[to.size()]) &&!isdigit(from[to.size()])) return 1;
		if(pos == from.size() - to.size() && !isalpha(from[pos - 1]) &&!isdigit(from[pos - 1])) return 1;
		if(!isalpha(from[pos - 1]) && !isdigit(from[pos - 1]) && !isalpha(from[pos + sz(to)]) && !isdigit(from[pos + sz(to)])) return 1;
		x++;
	}
	return 0;
}

int correct(string &str){
	return 0;
	int x = 0;
	while(x < str.size() && str[x] == ' ')x++;
	str = str.substr(x);
}

int calc(vvi &dp){
	for(int i = 0; i < dp.size() - 1; i++){
		for(int j = 0; j < dp[0].size(); j++){
			int flag = 0;
			R(kk, dp[0].size()){
				if(j != kk && dp[i+1][j] && dp[i][kk]){flag = kk + 1; break;}
			}
			dp[i+1][j] = flag;
		}
	}
	return accumulate(all(dp.back()), 0);
}
int main(){
	std::ios::sync_with_stdio(false);
	// fr;
	string str;
	cin >> t; while(t--){
		//error(t);
		int cntttt = 0;
		int user, mess; cin >> user; vector<string> vs;
		R(i, user){cin >> str; vs.pb(str); mp[str] = i;}
		// cout << "Yes\n";
		cin >> mess; vector<pair<string, string>> vm;
		vvi dp(mess, vi(user, 1));
		std::cin.ignore();
		R(i, mess){
			getline(cin, str);
			int pos = find(all(str), ':') - str.begin();
			vm.pb({str.substr(0, pos), str.substr(pos + 1)});
			correct(vm.back().se);
		}
		// return 0;
		int flag = 1;
		R(i, mess){
			if(vm[i].fi.size() == 1 && vm[i].fi[0] == '?'){

			}
			else{
				// error(i);
				// if(vm[i].se.find(vm[i].fi) != vm[i].se.size()){
				if(check(vm[i].se, vm[i].fi)){
					cout << "Impossible\n"; cntttt++; break;
				}
				R(k, user) dp[i][k] = 0;
				dp[i][mp[vm[i].fi]] = 1;
			}
			R(j, user){
				//cout << vm[i].se _ vs[j] << endl; 
				if(check(vm[i].se, vs[j])){
					// Error(i,j);
					dp[i][j] = 0;
				}
			}
		}
		if(cntttt) continue;

		// R(i, mess) {R(j, user) cout << dp[i][j] << " "; cout << endl;}		

		int res = calc(dp);

		if(!res) {
			cout << "Impossible\n"; continue;
		}
		error(res);
		// R(i, mess) {R(j, user) cout << dp[i][j] << " "; cout << endl;}

		int last;
		for(i = 0; i < dp[0].size(); i++){
			if(dp.back()[i]) {last = dp.back()[i]; break;}
		}
		// error(last);
		vm.back().fi = vs[i];
		//last = dp.back()[last - 1];
		i = mess - 2;

		while(i >= 0){
			vm[i].fi = vs[last - 1];
			last = dp[i][last - 1];
			// Error(i, last);
			i--;
		}

		R(i, mess){
			cout << vm[i].fi << ":" << vm[i].se << endl;
		}

	}

	return 0;
}
