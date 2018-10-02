#include <bits/stdc++.h>
#include <unordered_map>
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

unordered_map<int, vii > hm;


int ma(vi v, vii &w){
	int ans=0;
	foi(w.si){
		if(w[i]==v)
			ans++;
	}
	return ans;
}


ll f(vl &v, int l){
	if(v[l]!=-1)
		return v[l];
	int n = s.le;
	if(l==n)
		return v[l] = 1;
	int x,y,z;
	ll ans = 0,tmp;
	vi cc(26);
	// bool done=0;
	int count=0;
	for (int i = l; i < n; ++i)
	{
		count++;
		cc[s[i]-'a']++;
		if(hm.find(count)==hm.end())
			continue;
		x = ma(cc,hm[count]);
		if(x>0){
			tmp=x*f(v,i+1);
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
		// vii w(n,vi(26));
		ll pl,ql;
		foi(n){
			cin>>v[i];
			// cout<<": "<<v[i]<<" "<<v[i].le<<endl;
			vi oo(26);
			foj(v[i].le){
				oo[v[i][j]-'a']++;
			}
			int uu = v[i].le;
			if(hm.find(uu)==hm.end()){
				vii w;
				w.pb(oo);
				hm[uu]=w;
			}
			else{
				hm[uu].pb(oo);
			}
		}
		printf("Case #%d: ",qq);
		foi(m){
			cin>>s;
			vl xx(s.le+1,-1);
			pl = f(xx,0);
			cout<<pl<<" ";
		}
		cout<<endl;
	}
	return 0;
}