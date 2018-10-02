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
	int tc;
	cin>>tc;
	for(int test_case = 1; test_case <= tc; test_case++){
		printf("Case #%d: ", test_case);
		int m;
		double ans, k, c1, c2;
		cin>>m;
		if(m==1){
			cin>>k>>c1;
			ans = c1/k;
			ans -= 1.0;
			cout<<ans<<endl;
		}
		else{
			cin>>k>>c1>>c2;
			double a = k;
			double b = 2.0*k - c1;
			double c = k - c1 - c2;
			double det = b*b - 4*a*c;
			det = sqrt(det);
			double ans, ans1;
			ans = -1.0 * b + det;
			ans1 = -1.0 * b - det;
			ans = ans / (2.0 * a);
			ans1 = ans1 / (2.0 * a);

			std::cout << std::fixed;
		    std::cout << std::setprecision(12);
			if(ans >= -1.0 and ans < 1.0)
				cout<<ans<<endl;
			else
				cout<<ans1<<endl;
		}
	}
	return 0;
}