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
#define N 705
#define z v[i][j][p]
ll a[N][N];
ll v[N][N];

int binS(int i, int j, ll val, int k){
	int mid = (i+j)/2;
	if(a[k][mid]>=val)
		return binS(i,mid,val,k);
	if(a[k][mid+1]>=val)
		return mid;
	return binS(i+1,j,val,k);
}

int search(int i, ll val){
	if(a[i][0] >= val)
		return -1;
	if(a[i][n-1]<val)
		return n-1;
	return binS(0, n, val, i);
}

int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		// memset(v, -1, sizeof(v));
		foi(n){
			foj(n){
				cin>>a[i][j];
			}
			sort(a[i], a[i] + n);
		}
		foi(n)
			v[0][i] = a[0][i];
		foi1(n-1){
			foj(n){
				int ind = search(i-1, a[i][j]);
				if(ind<0)
					v[i][j]=-1;
				else{
					if(v[i-1][ind] > 0)
						v[i][j] = a[i][j] + v[i-1][ind];
					else
						v[i][j] = -1;
				}
			}
		}
		ll ans = 0;
		foi(n)
			ans = max(ans, v[n-1][i]);
		if(ans > 0)
			cout<<ans<<endl;
		else
			cout<<-1<<endl;
	}

	return 0;
}