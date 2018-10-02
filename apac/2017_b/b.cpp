#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define pb push_back
#define vi vector<int>
#define vii vector<vi >
#define vb vector<bool>
#define vbb vector<vb >
#define vl vector<long long int>
#define vll vector<vl >
#define foi(x) for (int i = 0; i < x; ++i)
#define foj(x) for (int j = 0; j < x; ++j)
#define foi1(x) for (int i = 1; i <= x; ++i)
#define foj1(x) for (int j = 1; j <= x; ++j)

#define z v[i][j]

int main(int argc, char const *argv[])
{
	int t,n,m,x,y,k;
	scanf("%d",&t);
	for (int qq = 1; qq < t+1; ++qq)
	{
		cin>>n>>m>>k;
		vbb v(n,vb(m));
		foi(k){
			cin>>x>>y;
			v[x][y]=1;
		}
		vii s(n,vi(m));
		foi(n){
			if(!v[i][0])
				s[i][0]=1;
		}
		foi(m){
			if(!v[0][i])
				s[0][i]=1;
		}
		for (int i = 1; i < n; ++i)
		{
			for (int j = 1; j < m; ++j)
			{
				if(z)
					continue;
				s[i][j] = 1 + min(min(s[i][j-1],s[i-1][j]),s[i-1][j-1]);
			}
		}
		ll ans=0;
		foi(n){
			foj(m){
				ans+=s[i][j];
			}
		}
		printf("Case #%d: %lld\n",qq,ans );
	}
	return 0;
}