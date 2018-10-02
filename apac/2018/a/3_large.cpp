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
#define vd vector<ld>
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
#define ld long double


int m;
ld k;
ld c[101];
// int Lim = 10000;
ld eps = 1e-13;



ld eval(ld r){
	ld rPow[m+1];
	rPow[0] = 1;
	foi1(m)
		rPow[i] = (1.0 + r) * rPow[i-1];

	ld ans = -1.0 * k * rPow[m];

	for(int i=0;i<m-1;i++)
		ans += c[i] * rPow[m-i-1];
	ans += c[m-1];
	return ans;
}

ld binS(ld i, ld j){
	std::cout << std::fixed;
    std::cout << std::setprecision(12);
	// cout<<i<<" "<<j<<endl;
	if(j - i <= eps)
		return i;
	ld mid = (i+j)/2.0;
	ld ans = eval(mid);
	if(ans == 0.0)
		return mid;
	if(ans > 0.0)
		return binS(mid, j);
	return binS(i, mid);
}

int main(){
	int tc;
	cin>>tc;
	for(int test_case = 1; test_case <= tc; test_case++){
		printf("Case #%d: ", test_case);
		cin>>m>>k;
		foi(m)
		cin>>c[i];

		// cout<<eval(-1)<<endl;
		// cout<<eval(1)<<endl;

		cout<<binS(-1.0, 1.0)<<endl;
	}
	return 0;
}