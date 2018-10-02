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
#define vs vector<string>
#define si size()
#define le length()
#define N 1000000007

string s;

int ma(vi v, vii &w){
	int ans=0;
	foi(w.si){
		if(w[i]==v)
			ans++;
	}
	return ans;
}

ll f(vl &v, vii &w, int l){
	if(v[l]!=-1)
		return v[l];
	int n = s.le;
	if(l==n)
		return v[l] = 1;
	int x,y,z;
	ll ans = 0,tmp;
	vi cc(26);
	// bool done=0;
	for (int i = l; i < n; ++i)
	{
		cc[s[i]-'a']++;
		x = ma(cc,w);
		if(x>0){
			tmp=x*f(v,w,i+1);
			tmp = tmp%N;
			ans+=tmp;
			ans=ans%N;
			// done=1;
		}
	}
	return v[l] = ans;
}


int main(int argc, char const *argv[])
{
	int t,n,m;
	scanf("%d",&t);
	for (int qq = 1; qq < t+1; ++qq)
	{
		cin>>n>>m;
		vs v(n);
		vii w(n,vi(26));
		ll pl,ql;
		foi(n){
			cin>>v[i];
			foj(v[i].si)
				w[i][v[i][j]-'a']++;
		}
		printf("Case #%d: ",qq);
		foi(m){
			cin>>s;
			vl xx(s.le+1,-1);
			pl = f(xx,w,0);
			cout<<pl<<" ";
		}
		cout<<endl;
	}
	return 0;
}