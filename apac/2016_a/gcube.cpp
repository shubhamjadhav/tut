#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define pb push_back
#define vi vector<int>
#define vii vector<vi >
#define vl vector<long long int>
#define vll vector<vl >
#define foi(x) for (int i = 0; i < x; ++i)
#define foj(x) for (int j = 0; j < x; ++j)

int main(int argc, char const *argv[])
{
	int t,n,m,x,y;
	scanf("%d",&t);
	for (int qq = 1; qq < t+1; ++qq)
	{
		printf("Case #%d:\n",qq );
		scanf("%d%d",&n,&m);
		vi w(n);
		foi(n)
			scanf("%d",&w[i]);
		vll v(n, vl(n));
		foi(n)
		v[i][i]=w[i];
		foi(n-1){
			for(int j = i+1; j < n; ++j)
				v[i][j] = v[i][j-1]*w[j];
		}
		foi(m){
			scanf("%d %d",&x,&y);
			ll ans = v[x][y];
			int len = y-x+1;
			cout<<ans<<" "<<len<<endl;
			printf("%Lf\n",(long double)pow(ans,1.0/len));
		}
	}
	return 0;
}