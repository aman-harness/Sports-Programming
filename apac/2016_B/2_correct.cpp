#include <vector> 
#include <queue>
#include <map> 
#include <set>
#include <utility> //Pair
#include <algorithm>
#include <sstream> // istringstream>> ostring stream<<
#include <iostream> 
#include <iomanip> 
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <bitset>
#include <limits>


using namespace std;
#define REP(a, b, c) for(int a = b; a < c; a++)
#define asd(x)              cout<<__LINE__<<" :: "<<#x<< ": "<<x<<endl;
#define asdf(x, y)          cout<<__LINE__<<" :: "<<#x<< ": "<<x<<" | "<<#y<< ": "<<y<<endl;
typedef pair<int,int> ii;
typedef long long LL;

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int test;
	scanf("%d", &test);
	REP(i, 0, test){
		int NP, NT, NE;
		cin >> NP >> NT >> NE;
		vector<int> P(NP), T(NT), E(NE);

		REP(j, 0, NP){
			cin >> P[j];
		} REP(j, 0, NT) {
			cin >> T[j];
		} REP(j, 0, NE) {
			cin >> E[j];
		}

		map<ii, int> store1, store2;

		REP(a, 0, NP){
			REP(d, 0, NE){
				int num = P[a], den = E[d];
				int gcd = __gcd(num, den);
				num /= gcd, den /= gcd;

				store1[ii(num, den)];
			}
		}


		REP(b, 0, NT){
			REP(c, 0, NT){
				if(b == c) continue;
				int num = T[b], den = T[c];
				int gcd = __gcd(num, den);
				num /= gcd, den /= gcd;
				store2[ii(num, den)];
			}
		}


		printf("Case #%d:\n", i+1);
		int K;
		cin >> K;
		while(K--){
			int P, Q;
			cin >> P >> Q;
			string ans = "No";
			for(map<ii, int> :: iterator it = store1.begin(); it != store1.end(); it++){
				LL a = (it->first).first, b = (it->first).second;
				b *= P;
				a *= Q;
				LL gcd = __gcd(b, a);

				b /= gcd, a /= gcd;

				if(store2.count(ii(b, a))) { ans = "Yes"; break; }
			}
			cout << ans << endl;
		}
	}
	
	return 0;
}
