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
const int mod  = 1000000007;

#define N 2000005
int NN;
// int n, k, m;
vi graph[N];
 
// A recursive function used by topologicalSort
void topologicalSortUtil(int v, bool visited[], 
                                stack<int> &Stack)
{
    // Mark the current node as visited.
    visited[v] = true;
 
    // Recur for all the vertices adjacent to this vertex
    for (auto i = graph[v].begin(); i != graph[v].end(); ++i)
        if (!visited[*i])
            topologicalSortUtil(*i, visited, Stack);
 
    // Push current vertex to stack which stores result
    Stack.push(v);
}
 
// The function to do Topological Sort. It uses recursive 
// topologicalSortUtil()
void topologicalSort(vi &install)
{
    stack<int> Stack;
    sort(all(install));
    reverse(all(install));

    int V = NN;
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
 
    // Call the recursive helper function to store Topological
    // Sort starting from all vertices one by one
    vector<stack<int>> vs;
    for (int i = 0; i < install.size(); i++)
      if (visited[install[i]] == false){
        stack<int> Stack;
        topologicalSortUtil(install[i], visited, Stack);
        // cout << Stack.size() << endl;
        vs.pb(Stack);
      }
 
    vvi tt;
    
    R(i, sz(vs)){
        vi ttt;
        
        while (vs[i].empty() == false)
        {
            // cout << vs[i.top() << " ";
            ttt.pb(vs[i].top());
            vs[i].pop();
        }
        // error(ttt.size());
        tt.pb(ttt);
    }


    R(i, sz(tt)) reverse(all(tt[i]));
    sort(all(tt));

    int k = 0;
    R(i, sz(tt)){
        k += tt[i].size();
    }

    // cout << endl;
    cout << k << endl;

    priority_queue<ii,vector<ii> , greater<ii>> Q; 
    vi pointer(sz(tt), 0);
    R(i, sz(tt)){
        if(sz(tt[i])) Q.push({tt[i][0], i});
    }
    while(!Q.empty()){
        cout << Q.top().fi + 1<< " ";
        int xx = Q.top().se; Q.pop();
        pointer[xx]++;
        if(pointer[xx] < sz(tt[xx])) Q.push({tt[xx][pointer[xx]], xx});
    }
    cout << endl;
}



int main(){
    std::ios::sync_with_stdio(false);
    // fr;
    int q; cin >> q; while(q--)
    {
        ll n, m, k, temp;
        cin >> n >> m;
        NN = n;
        vi install(m,0);
        R(i, n) graph[i].clear();
        R(i, n){
            cin >> k;
            R(j, k){
                cin >> temp;
                // graph[temp - 1].pb(i);
                graph[i].pb(temp - 1);
            }
        }
    
        R(i, n) {sort(all(graph[i])); //reverse(all(graph[i]));
        }
    
        R(i, m) cin >> install[i];
        R(i, m) install[i]--;
    
        topologicalSort(install);
    }
    return 0;
}


















