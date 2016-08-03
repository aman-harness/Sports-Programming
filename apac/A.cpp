#include<bits/stdc++.h>
using namespace std;
 
#define sd(mark) scanf("%d",&mark)
#define ss(mark) scanf("%s",&mark)
#define sl(mark) scanf("%lld",&mark)
#define debug(mark) printf("check%d\n",mark)
#define clr(mark) memset(mark,0,sizeof(mark))
#define F first
#define S second
#define MP make_pair
#define pb push_back
#define ll long long

pair<int,string> a[110];
string s;
int f[30];
int main()
{
	// freopen("A.in","r",stdin);
	// freopen("A.out","w",stdout);
	int t;
	sd(t);
	for(int tt=1;tt<=t;++tt)
	{
		int n,i,j;
		sd(n);
		getline(cin,s);
		for(i=0;i<n;++i)
		{
			getline(cin,s);
			//cin>>s;
			clr(f);
			for(j=0;j<s.length();++j)
			{
				if(s[j]!=' ')
					f[s[j]-'A']++;
			}
			int cnt=0;
			for(j=0;j<26;++j)
				if(f[j])
					cnt++;
			a[i]=MP(-cnt,s);
		}
		sort(a,a+n);
		cout<<"Case #"<<tt<<": "<<a[0].S<<'\n';
	}
}