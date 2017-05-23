	#include <bits/stdc++.h>
	using namespace std;
	typedef long long ll;

	int main(){
		long long n, m;

		cin >> n >> m;

		// cerr << temp << endl;
		m = min(n, m);
		if(n == m){
			cout << n  << endl;
			return 0;
		}
		else if (n == m + 1){
			cout << m + 1 << endl;
		}

		else{
			ll ans = m;
			ll temp = 0;

			ll right = INT_MAX - 1000;

			while(temp < right - 1){
				ll mid = temp + (right - temp) / 2; 


				ll x = 0;
				if((mid + 1) % 2 == 0) x = (mid + 1) / 2 * (mid + 2);
				else x = (mid + 1) * (mid + 2) / 2;

				// cout << temp << " " << right << " " << mid << " " << (n - m) - x << endl;
				if( (n - m) - x > 0){
					temp = mid;
				}
				else right = mid;
			}
			cerr << temp << endl;
			cout << temp +  m + 2 << endl;
			// if((temp * (temp + 1)) / 2 == n) cout << ans + temp << endl;
			// else cout << ans + right << endl;
			// cout << ans << " " << ans + temp<< endl;
		}

		return 0;
	}
