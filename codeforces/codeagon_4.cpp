/*
Author : Aman Singh
Solution for problem code .
*/

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll,ll> ii;
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
#define infll 20000000000000000
const double eps = 1e-7;

#define NN 20005
int n, k, m;int p, e, M, N;

vi graph[NN];

int match(ii a, ii b){
	if(a.fi == b.fi || a.se == b.se) return 1;
	if(abs(a.fi - b.fi) == abs(a.se - b.se)) return 1;
	return 0;
}


// A DFS based recursive function that returns true if a
// matching for vertex u is possible
bool bpm(int u, bool seen[], int matchR[])
{
    // Try every job one by one
    for (int v = 0; v < graph[u].size(); v++)
    {
        // If applicant u is interested in job v and v is
        // not visited
        if (!seen[graph[u][v]])
        {
            seen[graph[u][v]] = true; // Mark v as visited
 
            // If job 'v' is not assigned to an applicant OR
            // previously assigned applicant for job v (which is matchR[v]) 
            // has an alternate job available. 
            // Since v is marked as visited in the above line, matchR[v] 
            // in the following recursive call will not get job 'v' again
            if (matchR[graph[u][v]] < 0 || bpm(matchR[graph[u][v]], seen, matchR))
            {
                matchR[graph[u][v]] = u;
                return true;
            }
        }
    }
    return false;
}
 
// Returns maximum number of matching from M to N
int maxBPM()
{
    // An array to keep track of the applicants assigned to
    // jobs. The value of matchR[i] is the applicant number
    // assigned to job i, the value -1 indicates nobody is
    // assigned.
    int matchR[N];
 
    // Initially all jobs are available
    memset(matchR, -1, sizeof(matchR));
 
    int result = 0; // Count of jobs assigned to applicants
    for (int u = 0; u < M; u++)
    {
        // Mark all jobs as not seen for next applicant.
        bool seen[N];
        memset(seen, 0, sizeof(seen));
 
        // Find if the applicant 'u' can get a job
        if (bpm(u, seen, matchR))
            result++;
    }
    return result;
}


int main(){
	std::ios::sync_with_stdio(false);
	// fr;
	int q;
	cin >> q;
	while(q--){
		cin >> p >> e;
		M = p, N = e;

		vii pp(p, {0, 0}), ee(e, {0, 0});
		R(i, p) cin >> pp[i].fi >> pp[i].se;
		R(i, p) graph[i].clear();
		R(i, e) {
			cin >> ee[i].fi >> ee[i].se;
			R(j, p){
				if(match(pp[j], ee[i])) graph[j].pb(i);
			}
		}
		cout << maxBPM() << endl;
	}



	return 0;
}
