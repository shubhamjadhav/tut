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

int main(int argc, char const *argv[])
{
	int t,m,n;
	scanf("%d",&t);
	for (int qq = 1; qq < t+1; ++qq)
	{
		cin>>n>>m;
		if(!m){
			printf("Case #%d: 1.00000000\n",qq);
		}
		else{
			double ff = double(n)/m;
			ff = ff + 1.0;
			ff = 2/ff;
			ff = 1.0 - ff;
			printf("Case #%d: ",qq);
			cout.precision(8);
			cout<<fixed<<ff<<endl;
		}
	}
	return 0;
}