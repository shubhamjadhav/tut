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

ll a[100001];

int main(){
	int q;
	cin>>n>>q;
	foi(n)
	cin>>a[i];
	ll x,y,z;
	foi(q){
		cin>>x>>y>>z;
		if(x==1){
			a[y-1] = z;
		}
		else{
			if(z-y+1<3){
				cout<<0<<endl;
				continue;
			}
			vl tmp;
			for(int i1=y-1;i1<z;i1++)
				tmp.pb(a[i1]);
			int m = tmp.si;
			sort(tmp.begin(), tmp.end(), greater<ll>());
			ll ans = 0;
			for(int i1=0;i1<m-2;i1++){
				int j=i1+1,k=m-1;
				while(j<k){
					if(tmp[j] + tmp[k] > tmp[i1]){
						ans = max(ans, tmp[i1]+tmp[j]+tmp[k]);
						k--;
					}
					else
						k--;
				}
			}
			cout<<ans<<endl;
		}
	}

	return 0;
}