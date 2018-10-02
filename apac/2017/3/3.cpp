#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define pb push_back
#define vi vector<int>
#define vii vector<vi >
#define pp pair<long long ,long long >
#define vp vector<pair<long long,long long> >
#define vb vector<bool>
#define vbb vector<vb >
#define vl vector<long long int>
#define vll vector<vl >
#define foi(x) for (int i = 0; i < x; ++i)
#define foj(x) for (int j = 0; j < x; ++j)
#define foi1(x) for (int i = 1; i <= x; ++i)
#define foj1(x) for (int j = 1; j <= x; ++j)

bool f(const pp &a,const pp &b){
	if(a.first!=b.first)
		return a.first<b.first;
	return a.second<b.second;
}

int main(int argc, char const *argv[])
{
	int t,n,m,l1,r1,a,b,c1,c2,m1,m2;
	ll x,y;
	cin>>t;
	for (int qq = 1; qq <= t; ++qq)
	{
		cin>>n>>l1>>r1>>a>>b>>c1>>c2>>m;
		if(n==1){
			printf("Case #%d: 0\n",qq);
			continue;
		}
		vp v(n);
		v[0].first=l1;
		v[0].second=r1;
		m1 = int(l1);
		m2 = int(r1);
		for (int i = 1; i < n; ++i)
		{
			x = (a*min(v[i-1].first,v[i-1].second)%m + b*max(v[i-1].first,v[i-1].second)%m + c1)%m;
			y = (a*max(v[i-1].first,v[i-1].second)%m + b*min(v[i-1].first,v[i-1].second)%m + c2)%m;
			v[i].first = min(x,y);
			v[i].second = max(x,y);
			m1 = min(m1,int(v[i].first));
			m2 = max(m2,int(v[i].second));
		}
		sort(v.begin(), v.end(), f);
		int ss = 0,cc = 0;
		foi(n){
			if(int(v[i].second)==m2)
				cc++;
			if(int(v[i].second)!=m2)
				ss = max(ss,int(v[i].second));
		}
		if(cc>1)
			ss = m2;
		int ans = m2-m1;
		int p,q;
		foi(n){
			
		}
		// printf("Case #%d: %d\n",qq,);
	}
	return 0;
}