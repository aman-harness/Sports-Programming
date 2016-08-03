#include <bits/stdc++.h>

int n, t;
int lcs(int , int );
int dpp[550][550];

class UF    {
    int *id, cnt, *sz;
public:
	// Create an empty union find data structure with N isolated sets.
	UF(){
		std::cout << "Blash";
	}
    UF(int N)   {
        cnt = N;
	id = new int[N];
	sz = new int[N];
        for(int i=0; i<N; i++)	{
            id[i] = i;
	    sz[i] = 1;
	}
    }
    ~UF()	{
	delete [] id;
	delete [] sz;
    }
	// Return the id of component corresponding to object p.
    int find(int p)	{
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
    void merge(int x, int y)	{
        int i = find(x);
        int j = find(y);
        if (i == j) return;
		
		// make smaller root point to larger one
        if   (sz[i] < sz[j])	{ 
		id[i] = j; 
		sz[j] += sz[i]; 
	} else	{ 
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

using namespace std;
string str[550];

int lcs(int ind1, int ind2){
	if(str[ind1] == str[ind2]) return str[ind1].size();
	int dp[str[ind1].size() + 1][str[ind2].size() + 1];
	for(int i = 0; i <= str[ind1].size(); i++) dp[i][0] = 0;
	for(int i = 0; i <= str[ind2].size(); i++) dp[0][i] = 0;

	for(int i = 1; i <= str[ind1].size(); i++)
		for(int j = 1; j <= str[ind2].size(); j++){
			int maxi = 0;
			if(str[ind1][i - 1] == str[ind2][j - 1]) 
				maxi = max(maxi, dp[i - 1][j - 1] + 1);
			else{
				maxi = max(dp[i - 1][j], dp[i][j -1]);
			}
			dp[i][j] = maxi;
		}
	return dp[str[ind1].size()][str[ind2].size()];
}

int calc(int index, UF &xxx){
	if(index < 1) return 1;
	else{
		int ret = calc(index - 1, xxx);
		for(int i  = 0; i < index; i++){
			int lc;
			if(dpp[index][i] != -1) lc = dpp[index][i];
			else lc = lcs(index, i);
			// cout << "Debug -- " << lc << index << i <<  endl;
			if(((lc * 100) / str[i].size()) >= t && ((lc * 100) / str[index].size()) >= t) {
				xxx.merge(index, i);
			}
		}
	
		return xxx.count();
	}
}

int main(){
	// ifstream cin("input.txt");
	int tt; cin >> tt;
	for(int q = 0; q < tt; q++){
		cin >> n >> t;
		int xx = n;
		UF xxx(n);
		// cout << "Reached Here \n";
		for(int i = 0 ; i < xx; i++){
			cin >> str[i];
		}
		// cout << "Reached Here \n";
		for(int i = 0; i <= xx; i++)
			for(int j = 0; j <= xx; j++)
				dpp[i][j] = -1;
		printf("Case #%d:\n%d\n", q + 1, calc(xx - 1, xxx));
	}
}