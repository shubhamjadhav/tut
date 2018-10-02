#include <bits/stdc++.h>

using namespace std;

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

int n;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		double p, q, d;
		double ans = 0, tmp;
		foi(n){
			cin>>p>>q>>d;
			tmp = q*p;
			tmp *= d / 100.0;
			tmp *= d / 100.0;
			ans += tmp;
		}
		std::cout << std::fixed;
	    std::cout << std::setprecision(8);		
	    cout<<ans<<endl;
	}

	return 0;
}