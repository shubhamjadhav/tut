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

char s[5001], t[5001];
string p,q;
int n, m, l, k;

int v[5002][5002];
#define z v[i][j]

int f(int i, int j){
	if(z!=-1)
		return z;
	if(i==n or j==m)
		return z = 0;
	if(s[i]==t[j])
		return z = 1 + f(i+1, j+1);
	return z=max(f(i+1, j), f(i, j+1));
}

int main(int argc, char const *argv[])
{
	int t1;
	cin>>t1;
	while(t1--){
		memset(v, -1, sizeof(v));
		cin>>n>>m;
		cin>>p>>q;
		l=1;
		k=1;

		s[0]=p[0];
		t[0]=q[0];

		foi1(n-1){
			if(p[i]!=s[l-1]){
				s[l]=p[i];
				l++;
			}
		}
		foi1(m-1){
			if(q[i]!=t[k-1]){
				t[k]=q[i];
				k++;
			}
		}
		// foi(l)
		// cout<<s[i]<<" ";
		// cout<<endl;
		// foi(k)
		// cout<<t[i]<<" ";
		// cout<<endl;

		n=l;
		m=k;
		int ans = f(0, 0);
		// cout<<l<<" "<<k<<" "<<ans<<endl;
		cout<<l+k-ans<<endl;
	}
	return 0;
}