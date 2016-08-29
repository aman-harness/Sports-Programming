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
#define cint(x) int x; cin >> x;

#define what_is(x) cerr << #x << " is " << x << endl;
#define dbg(x) ff(i,0,sz(x)) cout << x[i] << " ";
#define dbgg(x) ff(i,0,sz(x)){ff(j,0,sz(x[0])) cout << x[i][j] << " "; cout << endl;}

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
int m, n;

int up(vvi &arr){
	ff(col,0,n){
		ff(row, 0, n){
			if(arr[row][col]==0){
				int flag = 1;
				ff(k, row, n) if(arr[k][col] > 0) flag = 0;
				if(flag) break;
				ff(k,row,n-1) arr[k][col] = arr[k+1][col];
				arr[n - 1][col] = 0;
				row--;
			}
		}
	}
	ff(col,0,n){
		ff(row, 1, n){
			if(arr[row][col]==arr[row-1][col]){
				arr[row-1][col] *= 2;
				arr[row][col] = 0;
			}
		}
	}
	ff(col,0,n){
		ff(row, 0, n){
			if(arr[row][col]==0){
				int flag = 1;
				ff(k, row, n) if(arr[k][col] > 0) flag = 0;
				if(flag) break;
				ff(k,row,n-1) arr[k][col] = arr[k+1][col];
				arr[n - 1][col] = 0;
				row--;
			}
		}
	}
	dbgg(arr);
}

int down(vvi &arr){
	for(int col = n-1; col>=0; col--){
		for(int row = n -1; row >=0; row--){
			if(arr[row][col]==0){
				int flag = 1;
				for(int k = row; k >= 0; k--) if(arr[k][col] > 0) flag = 0;
				if(flag) break;
				for(int k = row; k > 0; k--) arr[k][col] = arr[k-1][col];
				arr[0][col] = 0;
				row++;
			}
		}
	}
	for(int col = n-1; col>=0; col--){
		for(int row = n -2; row >=0; row--){
			if(arr[row][col]==arr[row+1][col]){
				arr[row+1][col] *= 2;
				arr[row][col] = 0;
			}
		}
	}
	for(int col = n-1; col>=0; col--){
		for(int row = n -1; row >=0; row--){
			if(arr[row][col]==0){
				int flag = 1;
				for(int k = row; k >= 0; k--) if(arr[k][col] > 0) flag = 0;
				if(flag) break;
				for(int k = row; k > 0; k--) arr[k][col] = arr[k-1][col];
				arr[0][col] = 0;
				row++;
			}
		}
	}
	dbgg(arr);
}

int right(vvi &arr){
	for(int row = n-1; row>=0; row--){
		for(int col = n -1; col >=0; col--){
			if(arr[row][col]==0){
				// cout <<row  << col << endl;
				int flag = 1;
				for(int k = col; k >= 0; k--) if(arr[row][k] > 0) flag = 0;
				if(flag) break;
				for(int k = col; k > 0; k--) arr[row][k] = arr[row][k-1];
				arr[row][0] = 0;
				col++;
			}
		}
	}
	// cout << n << endl;
	for(int row = n-1; row>=0; row--){
		for(int col = n -1; col > 0; col--){
			if(arr[row][col]==arr[row][col-1]){
				arr[row][col] *= 2;
				arr[row][col-1] = 0;
			}
		}
	}
	for(int row = n-1; row>=0; row--){
		for(int col = n -1; col >=0; col--){
			if(arr[row][col]==0){
				// cout <<row  << col << endl;
				int flag = 1;
				for(int k = col; k >= 0; k--) if(arr[row][k] > 0) flag = 0;
				if(flag) break;
				for(int k = col; k > 0; k--) arr[row][k] = arr[row][k-1];
				arr[row][0] = 0;
				col++;
			}
		}
	}
	dbgg(arr);
}

int left(vvi &arr){
	for(int row = n-1; row>=0; row--){
		for(int col = 0; col < n; col++){
			if(arr[row][col]==0){
				// cout <<row  << col << endl;
				int flag = 1;
				for(int k = col; k < n; k++) if(arr[row][k] > 0) flag = 0;
				if(flag) break;
				for(int k = col; k < n - 1; k++) arr[row][k] = arr[row][k+1];
				arr[row][n-1] = 0;
				col--;
			}
		}
	}
	// cout << n << endl;
	for(int row = n-1; row>=0; row--){
		for(int col = 0; col < n-1; col++){
			if(arr[row][col]==arr[row][col+1]){
				arr[row][col] *= 2;
				arr[row][col+1] = 0;
			}
		}
	}
	for(int row = n-1; row>=0; row--){
		for(int col = 0; col < n; col++){
			if(arr[row][col]==0){
				// cout <<row  << col << endl;
				int flag = 1;
				for(int k = col; k < n; k++) if(arr[row][k] > 0) flag = 0;
				if(flag) break;
				for(int k = col; k < n - 1; k++) arr[row][k] = arr[row][k+1];
				arr[row][n-1] = 0;
				col--;
			}
		}
	}
	dbgg(arr);
}

int main(){
	std::ios::sync_with_stdio(false);
	fr;
	int t; cin >> t;
	for(int tt = 1; tt <= t; tt++){
	
		print(tt, "");
		cin >> n; string str; cin >> str;
		std::vector<vi> arr(n, vi(n,0));
		ff(i,0,n) ff(j, 0, n) cin >> arr[i][j];
		// dbgg(arr); cout << endl;
		if(str == "up") up(arr);
		if(str == "left") left(arr);
		if(str == "down") down(arr);
		if(str == "right") right(arr);
	}

	return 0;
}
