#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define pb push_back
#define vi vector<int>
#define vl vector<long long int>
#define foi(x) for (int i = 0; i < x; ++i)
#define foj(x) for (int j = 0; j < x; ++j)

bool f(ll k, ll n){
	// cout<<k<<" "<<n<<endl;
	// return 1;
	if(k==1)
		return 0;
	if(n==1)
		return 0;
	// ll b;
	ll c = n>>1;
	if(k==c+1)
		return 0;
	if(k<=c)
		return f(k,c);
	return !f(n-k+1,c);
}

int main(int argc, char const *argv[])
{
	int t;
	scanf("%d",&t);
	long long int a=1,b,c;
	vl v(1,1);
	while(a<=1000000000000000000){
		a<<=1;
		a+=1;
		v.pb(a);
	}
	for (int qq = 1; qq <= t; ++qq)
	{
		scanf("%lld",&a);
		int i;
		for(i=0;i<v.size();i++)
			if(v[i]>=a)
				break;
		b = v[i];
		// cout<<"b si "<<b<<endl;
		bool b1 = f(a,b);
		printf("Case #%d: %d\n",qq,b1);
	}
	return 0;
}
