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

ll n, x;


int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>x>>n;
		vi a(n+1,0);
		a[x]=2;
		ll sum = n*(n+1);
		ll kk = 2;
		sum = sum / kk;
		sum -= x;
		if(sum%kk != 0){
			cout<<"impossible"<<endl;
			continue;
		}
		// cout<<sum<<endl;
		sum = sum / kk;
		ll curr = 0;
		ll i;
		for(i=n;i>=1;i--){
			if(i==x)
				continue;
			a[i]=1;
			curr += i;
			if(curr>=sum)
				break;
		}
		assert(i>0);
		ll ass = 0;
		// cout<<n<<" "<<sum<<endl;
		if(curr == sum){
			for(ll j=1;j<=n;j++){
				if(a[j]==1)
					ass+=j;
				cout<<a[j];
			}
			cout<<endl;
			assert(ass==sum);
			continue;
		}
		ass = 0;
		ll diff = curr - sum;
		if(diff == 1 and i-1 == x and i-2>1){
			a[i]=0;
			a[1]=a[i-2]=1;
			for(ll j=1;j<=n;j++){
				cout<<a[j];
			}
			cout<<endl;
			continue;
		}
		for(;i<=n;i++){
			ll tmp = i-diff;
			if(i==x or tmp==x)
				continue;
			if(tmp>0 and !a[tmp]){
				assert(a[i] == 1);
				a[tmp]=1;
				a[i]=0;
				break;
			}
		}
		if(i==n+1){
			cout<<"impossible"<<endl;
			continue;
		}
		for(ll j=1;j<=n;j++){
			cout<<a[j];
			if(a[j]==0)
				ass+=j;
		}
		cout<<endl;
		assert(ass == sum);
		// assert()
	}

	return 0;
}