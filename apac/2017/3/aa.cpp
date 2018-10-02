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
#define fi first
#define se second

bool f1(const pp &a,const pp &b){
	if(a.first!=b.first)
		return a.first<b.first;
	return a.second<b.second;
}

int f(vp &v){
	int i=1;
	int curr=0;
	int sum=v[0].se-v[0].fi+1;
	for(int i=1;i<v.size();i++){
		if(v[i].first>=v[curr].first and v[i].second<=v[curr].second)
			continue;
		sum+=v[i].se - v[curr].se;
		curr=i;
	}
	return sum;
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
		ll x1 = l1,y1=r1;
		for (int i = 1; i < n; ++i)
		{
			x = (a*x1%m + b*y1%m + c1)%m;
			y = (a*y1%m + b*x1%m + c2)%m;
			v[i].first = min(x,y);
			v[i].second = max(x,y);
			x1 = x;
			y1 = y;
			m1 = min(m1,int(v[i].first));
			m2 = max(m2,int(v[i].second));
		}
		int p,q;
		sort(v.begin(), v.end(), f1);
		// foi(n){
			// cout<<v[i].fi<<" "<<v[i].se<<endl;
		// }
		int ans = m2-m1;
		foi(n){
			vp w = v;
			w.erase(w.begin()+i);
			p = f(w);
			ans = min(ans,p);
		}
		printf("Case #%d: %d\n",qq,ans);
	}
	return 0;
}