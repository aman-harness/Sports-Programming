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
#define mp make_pair

char gr[1000][1000];
char out[1000][1000];
int dp[1000][1000];
int group[1000][1000];
int m, n;
map<ii, int> M;
int done[1000];

int check(int x, int y){ 
	// cout << x << " " << y << endl;
	if(x < 0 || y < 0 || x >= m || y >= n) return 0;
	else if(gr[x][y] == '*') return 0;
	else if(M[mp(x, y)]) return 0;
	else return 1;
}

int conn_com(int x, int y){
	// cout << "---- " <<x << " " << y << endl;
	if(check(x + 1, y)){
		M[mp(x + 1, y)] = 1;
		conn_com(x+1, y);
	}

	if(check(x - 1, y)){
		M[mp(x - 1, y)] = 1;
		conn_com(x-1, y);
	}

	if(check(x, y + 1)){
		M[mp(x, y + 1)] = 1;
		conn_com(x, y + 1);
	}
	if(check(x, y - 1)){
		M[mp(x, y - 1)] = 1;
		conn_com(x, y - 1);
	}
}

int fun(int x, int y){
	int kk = 1;
	for(int i = 0; i < x; i++){
		for(int j = 0 ; j < y; j++){
			if(dp[i][j]) continue;
			if(gr[i][j] == '.'){M[mp(i, j)] = 1; conn_com(i, j);}
			else{
				dp[i][j] = 0;
				continue;
			}
			int sz = M.size();
			for(std::map<ii,int >::iterator iter = M.begin(); iter != M.end(); ++iter){
				ii k =  iter->first;
				dp[k.first][k.second] = sz;
				group[k.first][k.second] = kk;
			}
			kk++;
			M.clear();
		}
	}
	
	for(int i = 0 ; i < kk; i++) done[i] = 0;
	for(int i = 0; i < x; i++)
		for(int j = 0 ; j < y; j++){
			if(gr[i][j] == '.') out[i][j] = '.';
			else{
				int tot = 0;
				if(i > 0) { tot += dp[i -1][j]; done[group[i -1][j]] = 1; }
				if(j > 0  && !done[group[i][j - 1]]) {tot += dp[i][j - 1]; done[group[i][j - 1]] = 1;} 	
				if(i < x - 1 && !done[group[i + 1][j]]) {tot += dp[i + 1][j]; done[group[i + 1][j]] =1; }
				if(j < y - 1 && !done[group[i][j + 1]]) {tot += dp[i][j+1];}
				out[i][j] = ((tot+1) % 10) + '0';
				if(j < y - 1)done[group[i][j + 1]] = 0;
				if(j > 0) done[group[i][j - 1]] = 0;
				if(i < x - 1) done[group[i + 1][j]] = 0;
				if(i > 0) done[group[i - 1][j]] = 0;
			}
		}
}

int main(){
	// ifstream cin("input.txt");
	std::ios::sync_with_stdio(false);
	int x, y; cin >> x >> y;
	m = x; n = y;
	for(int i = 0; i < x; i++)
		for(int j = 0;  j < y; j++){
			cin >> gr[i][j];
		}
	// cout << "Function Complete\n";
	fun(x, y);

	for(int i = 0; i < x; i++){
		for(int j = 0;  j < y; j++)
			cout << out[i][j];
		cout << endl;
	}

	for(int i = 0; i < x; i++){
		for(int j = 0;  j < y; j++)
			cout << dp[i][j];
		cout << endl;
	}

	return 0;
}