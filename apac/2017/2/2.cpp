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


ll mod_pow(ll base, ll exponent, int modulus)
{
    ll result = 1;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            result = (result * base) % modulus;
        exponent = exponent >> 1;
        base = (base * base) % modulus;
    }
    return result;
}

int main(int argc, char const *argv[])
{
	int t,a,b,n,x,y,k;
	cin>>t;
	for (int qq = 1; qq <= t; ++qq)
	{
		cin>>a>>b>>n>>k;
		int ans=0;
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				if(i==j)
					continue;
// /				ll a1 = (ll)a, b1 = (ll)b, 
				// int p = mod_pow(i, a, k);
				// int q = mod_pow(j, b, k);
				ll p = mod_pow((ll)i, (ll)a, k);
				ll q = mod_pow((ll)j, (ll)b, k);
				int p1 = (int)p;
				int q1 = (int)q;
				if(p1+q1 == k or p1+q1==0)
					ans++;
			}
		}

		printf("Case #%d: %d\n",qq,ans);
	}
	return 0;
}