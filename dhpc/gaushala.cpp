/*
Author : Aman Singh
Solution for problem code Gaushala Maidan.
 
==============================================
A programmer started to cuss,
'cause getting to sleep was a fuss.
As he lay there awake in his bed,
Looping around and 'round in his head,
Was: while(!asleep()) sheep++;
==============================================
 
 */

#include <bits/stdc++.h>
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
#define input(s, n) for(int i=0;i<n;i++)cin >> s[i];
#define F(i, f, t) for(int i=f;i<t;i++)
#define R(i,n) for(ll i=0;i<n;i++)
#define cint(x) int x; cin >> x;
// #define cint(x, y) {cint(x); cint(y); }

#define print(cnt,x) cout<<"Case #"<<cnt<<": "<<x<<"\n";

template <class T>  inline void smax(T &x,T y){ x = max((x), (y));}
template <class T>  inline void smin(T &x,T y){ x = min((x), (y));}

#ifdef LOCAL
#define fr freopen("in.txt","r",stdin)
#define fo freopen("output.txt","w",stdout)

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

void sc(int &x,int &y) { sc(x); return sc(y); }
void sc(int &x,int &y,int &z) { sc(x); sc(y); return sc(z); }

#define inf 1e9
const double eps = 1e-7;

long long dp[20][20][20][3];
ll q, w, e;
ll rec(int r, int b, int c, int last){
	// cout << r << " " << b << " " << c << " " << last << endl; 
	if(r == 0 && b == 0 && c == 0) return 1;


	if((r == 0 && b == 0 && c != 1) ||
	   (b == 0 && c == 0 && r != 1) ||
	   (c == 0 && r == 0 && b != 1)) return 0;

	if(r && b == 0 && c == 0 && last != 0) return 1;
	if(b && r == 0 && c == 0 && last != 1) return 1;
	if(c && r == 0 && b == 0 && last != 2) return 1;

	if(last == -1){
		ll temp = 0;
		if(r && last != 0){
			temp += rec(r - 1, b, c, 0);
		}
		if(b && last != 1){
			temp += rec(r, b - 1, c, 1);
		}
		if(c && last != 2){
			temp += rec(r, b, c - 1, 2);
		}
		return temp;
	}

	if(!dp[r][b][c][last]){
		ll temp = 0;
		if(r && last != 0){
			temp += rec(r - 1, b, c, 0);
		}
		if(b && last != 1){
			temp += rec(r, b - 1, c, 1);
		}
		if(c && last != 2){
			temp += rec(r, b, c - 1, 2);
		}
		if(last == -1) return temp;
		dp[r][b][c][last] = temp;
	}

	return dp[r][b][c][last]; 
}

int main(){
	std::ios::sync_with_stdio(false);
	fr;
	cint(tt); F(tc, 1, tt + 1){
		int q, w, e; cin >> q >> w >> e;
		R(i, q + 1){
			R(j, w + 1){
				R(k, e + 1){
					R(l, 3) dp[i][j][k][l] = 0;
				}
			}
		}
		cout << rec(q, w, e, -1) << endl;
		// cout << rec(q, w, e, 0) + rec(q, w, e, 1) + rec(q, w, e, 2) << endl;
		continue;
		R(i, q + 1){
			R(j, w + 1){
				R(k, e + 1){
					R(l, 3){
						dp[i][j][k][l] = 0;
					}
				}
			}
		}

		dp[0][0][0][0] = 1;
		dp[0][0][0][1] = 1;
		dp[0][0][0][2] = 1;

		R(i, q + 1){
			R(j, w + 1){
				R(k, e + 1){
					R(l, 3){
						cout << i << " " << j << " " << k << " " << l << endl;
						if(l != 0){ 
							dp[i + 1][j][k][(0) % 3] += dp[i][j][k][l];
							dp[i + 1][j][k][(0) % 3] += dp[i][j][k][l];
						}

						if(l != 1){
							dp[i][j + 1][k][(1) % 3] += dp[i][j][k][l];
							dp[i][j + 1][k][(1) % 3] += dp[i][j][k][l];
						}

						if(l != 2){
							dp[i][j][k + 1][(2) % 3] += dp[i][j][k][l];
							dp[i][j][k + 1][(2) % 3] += dp[i][j][k][l];
						}						
					}
				}
			}
		}
		cout << dp[q][w][e][0] + dp[q][w][e][1] + dp[q][w][e][2] << endl;
	}
	return 0;
}