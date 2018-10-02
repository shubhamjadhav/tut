#include <bits/stdc++.h>

using namespace std;

// #define vs vector<string >
#define ll long long int
#define pb push_back
#define vi vector<int>
#define vt vector<tup>
#define vtt vector<vt >
#define vii vector<vi >
#define viii vector<vii >
#define vb vector<bool>
#define vd vector<double>
#define vbb vector<vb >
#define vl vector<long long int>
#define vll vector<vl >
#define vlll vector<vll >
#define foi(x) for (int i = 0; i < x; ++i)
#define foj(x) for (int j = 0; j < x; ++j)
#define fok(x) for (int k = 0; k < x; ++k)
#define foi1(x) for (int i = 1; i <= x; ++i)
#define foj1(x) for (int j = 1; j <= x; ++j)
#define si size()
#define le length()
#define vs vector<string>

ll power(ll a, ll e, ll m){
	if(e==0 or a==1)
		return 1 % m;
	if(e==1)
		return a % m;
	if(m==1)
		return 0;
	ll ans = 1;
	while(e>0){
		if(e & 1){
			ans *= a;
			ans %= m;
		}
		e >>= 1;
		a = a * a;
		a %= m;
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	for(int test_case = 1;test_case<=tc;test_case++){
		printf("Case #%d: ",test_case);
		ll n, b, a, k;
		cin>>a>>b>>n>>k;
		// ll val1(k);
		// ll val2(k);
		ll ans = 0;
		foi1(n){
			foj1(n){
				if(i==j)
					continue;
				ll tmp1 = power(i, a, k);
				ll tmp2 = power(j, b, k);
				tmp1 += tmp2;
				if(!tmp1 or tmp1==k)
					ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
