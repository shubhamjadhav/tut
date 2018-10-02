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
#define si size()
#define le length()



int f(int n){
	if(n<=2)
		return n;
	int ans = 0;
	while(1){
		if(n>=3){
			ans+=2;
			n-=3;
		}
		else{
			ans+=n;	
			break;
		}
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	int t,n,m;
	scanf("%d",&t);
	for (int qq = 1; qq < t+1; ++qq)
	{
		cin>>n>>m;
		int ans = 0, ans1=0;
		if(n==1){
			if(m<=2){
				ans = m;
			}
			else{

			// ans = m*2;
			// ans = ans/3;
				ans = f(m);
			}
		}
		else if(m==1){
			if(n<=2){
				ans = m;
			}
			else{

			// ans = n*2;
			// ans = ans/3;	
				ans = f(n);
			}
		}
		else{
		ans = f(n)*f(m);
		
		// ans1 = m*2;
		// ans1 = ans1/3;
		// ans1 = ans1*n*2/3;
		// ans = max(ans, ans1);

		ans+=(n/3)*(m/3);
		}

		printf("Case #%d: %d\n",qq,ans);
	}
	return 0;
}