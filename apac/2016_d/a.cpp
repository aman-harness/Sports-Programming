#include <bits/stdc++.h>
using namespace std;
 
typedef vector<long long> vi;
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
#define cint(x) long long x; cin >> x;
 
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
 
class UF    {
    int *id, cnt, *sz;
public:
    // Create an empty union find data structure with N isolated sets.
    UF(int N)   {
        cnt = N;
    id = new int[N];
    sz = new int[N];
        for(int i=0; i<N; i++)  {
            id[i] = i;
        sz[i] = 1;
    }
    }
    ~UF()   {
    delete [] id;
    delete [] sz;
    }
    // Return the id of component corresponding to object p.
    int find(int p) {
        int root = p;
        while (root != id[root])
            root = id[root];
        while (p != root) {
            int newp = id[p];
            id[p] = root;
            p = newp;
        }
        return root;
    }
    // Replace sets containing x and y with their union.
    void merge(int x, int y)    {
        int i = find(x);
        int j = find(y);
        if (i == j) return;
       
        // make smaller root point to larger one
        if   (sz[i] < sz[j])    {
        id[i] = j;
        sz[j] += sz[i];
    } else  {
        id[j] = i;
        sz[i] += sz[j];
    }
        cnt--;
    }
    // Are objects x and y in the same set?
    bool connected(int x, int y)    {
        return find(x) == find(y);
    }
    // Return the number of disjoint sets.
    int count() {
        return cnt;
    }
};
 
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int marking(int i, int j, int r, int c, vector<string>& vs, vvi& mark){
    if(i < 0 || j < 0 || i > r-1 || j > c-1 || mark[i][j] || vs[i][j]=='0') return 0;
    else{
        mark[i][j] = 1;
        ff(k,0,4){
            marking(i+dx[k], j+dy[k], r, c, vs, mark);
        }
        return 1;
    }

}
 
int main(){
    std::ios::sync_with_stdio(false);
    fr;fo;
    cint(t);
    ff(tt,0,t){
        print(tt+1, "");
        cint(r); cint(c);
        vector<string> vs;
        vvi mark(r, vi(c, 0));
        ff(j,0,r){
            string str; cin >> str;
            vs.pb(str);
        }
        int count = 0;
        ff(i,0,r) ff(j,0,c) mark[i][j] = 0;
        ff(i,0,r)ff(j,0,c) {
            int p = marking(i, j, r, c, vs, mark);
            // cout << "p " << p << " i " << i << " j " << j << "   " << vs[i][j]  << endl;
            if(p) count++;
        }
        cint(q);
        ff(qq,0,q){
            char cc; cin >> cc;
            // cout << "C : " << cc << endl;
            if(cc == 'M'){
                cint(x); cint(y); cint(z);
                // cout << "x " << x << "y " << y << "z " << z << endl;  
                vs[x][y] = z + '0';
                count = 0;
                ff(i,0,r) ff(j,0,c) mark[i][j] = 0;
                ff(i,0,r)ff(j,0,c) {
                    int p = marking(i, j, r, c, vs, mark);
                    // cout << "p " << p << " i " << i << " j " << j << " " << (int)vs[i][j]  << endl;
                    if(p) count++;
                }
            }
            else{
                cout << count << endl;
            }
        }
       
    }
 
    return 0;
}