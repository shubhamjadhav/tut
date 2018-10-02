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
	int q,x,y;
	cin>>n>>q;
	vii a(n, vi(31));
	vii c(n+1, vi(31));
	foi(n){
		cin>>x;
		foj(31){
			if((1<<j & x) > 0)
				a[i][j] = 1;
		}
	}
	foi1(n){
		foj(31)
			c[i][j] = c[i-1][j] + a[i-1][j];
	}
	// cout<<"hi"<<endl;
	foi(q){
		cin>>x>>y;
		// cout<<x<<" "<<y<<endl;
		int ans = 0, yes, diff = y-x+1, no;
		foj(31){
			yes = c[y][j] - c[x-1][j];
			no = diff - yes;
			if(no > yes){
				ans += (1<<j);
			}
		}
		cout<<ans<<endl;
	}

	return 0;
}