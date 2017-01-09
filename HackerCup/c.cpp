/*
Author : Aman Singh
Solution for problem code HackerCup 3rd.
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

#ifdef LOCAL
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
int n, k;
int inp[N], A[N], B[N];
char str[N];

double dp[6][21][401];

map<int, int> mp, rev;
vi faces =  {4, 6, 8, 10, 12, 20};
int pre(int face){
	double p = (double)1 / mp[face];
	for(int i = 1; i <= mp[face]; i++){
		dp[face][1][i] = (double)1 / mp[face]; 
	}

	F(i, 1, 20){
		F(j, 1, mp[face] + 1){
			F(k, 1, 401){
				if(k + j < 401)
					dp[face][i + 1][k + j] += p * dp[face][i][k];  
			}
		}
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	fr; fo;
	R(i, sz(faces)) {mp[i] = faces[i]; rev[faces[i]] = i; pre(i);}

	int t, n, max_d; cin >> t; int ttt = 1;
	while(t--){
		cin >> max_d >> n;
		cout.precision(8); cout << fixed;
		double p = 0;
		while(n--){
			string str; cin >> str; int a, b, c = 0;
			a = stoi(str.substr(0, str.find('d')));
			str = str.substr(str.find('d') + 1);
			
			char cc = '-'; if(str.find('+') != -1) cc = '+';
			b = stoi(str.substr(0, str.find(cc)));

			//cout << a _ str _ b _ str.find(cc) _  cc << endl;
			// continue;

			if(str.find(cc) != -1)
			if(str.size()){
				str = str.substr(str.find(cc));
				c = stoi(str);
			}
			// cout << a _ b _ c << endl;
			int maxn = max_d - c;
			double temp = 0;
			F(i, maxn, 401) temp += dp[rev[b]][a][i];
			smax(p, temp);
		} 
		print( ttt++, p);
	}

	return 0;
}