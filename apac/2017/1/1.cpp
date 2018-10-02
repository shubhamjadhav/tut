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


int main(int argc, char const *argv[])
{
	int t,n,m;
	cin>>t;
	for (int qq = 1; qq <= t; ++qq)
	{
		cin>>n>>m;
		int ans = min(n,m);
		ll aa = ans;
		aa = aa*(aa+1)/2;
		printf("Case #%d: %lld\n",qq,aa);
	}
	return 0;
}