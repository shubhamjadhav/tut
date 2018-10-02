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

int k[13], M, N, l[13];
int c[13][11];
int a[13][11];

int v[13][11][1001];

#define z v[i][level][s]

int f(int i, int level, int s){
	if(z!=-1)
		return z;
	if(i == N+1)
		return z=0;
	z = a[i][level] + f(i+1, l[i+1], s);
	if(level == k[i])
		return z;
	if(s >= c[i][level]){
		z = max(z, f(i, level+1, s - c[i][level]));
	}
	return z;
}


int main(){
	int tc;
	cin>>tc;
	for(int test_case = 1; test_case <= tc; test_case++){
		memset(v, -1, sizeof(v));
		printf("Case #%d: ", test_case);
		cin>>M>>N;
		foi1(N){
			cin>>k[i]>>l[i];
			foj1(k[i])
				cin>>a[i][j];
			foj1(k[i] - 1)
				cin>>c[i][j];
		}
		cout<<f(1, l[1], M)<<endl;
	}
	return 0;
}