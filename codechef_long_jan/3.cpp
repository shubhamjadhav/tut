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

ll n, k;
ll b[300010];
ll a[100010];

ll st, end1;		

ll gs;

void runKanade(int lim){
	ll sum1 = 0;
	gs = 0;
	int i=0,j=0;
	while(j < lim){
		sum1 += b[j];
		if(sum1 > gs){
			gs = sum1;
			st = i;
			end1 = j;
		}
		if(sum1 < 0){
			sum1 = 0;
			i = j+1;
		}
		j++;
	}
	return;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		gs = 0;
		cin>>n>>k;
		ll mm = LLONG_MIN;
		ll ans = 0;
		ll tmp;

		foi(n){
			cin>>tmp;
			a[i] = tmp;
			b[i] = b[n+i] = b[n+n+i] = tmp;
			mm = max(mm, tmp);
			ans += tmp;
		}

		if(mm<=0){
			cout<<mm<<endl;
			continue;
		}
		if(k<3){
			runKanade(n*k);
			cout<<gs<<endl;
			continue;
		}
		runKanade(n*3);
		// cout<<st<<" "<<end1<<" "<<endl;
		if(end1<n){
			cout<<gs<<endl;
		}
		else if(end1<2*n){
			cout<<gs<<endl;
		}
		else{
			ans *= (k-2);
			// cout<<"ans is "<<ans<<endl;
			assert(st<n);
			for(int i=st;i<n;i++)
				ans+=b[i];
			for(int i=2*n;i<=end1;i++)
				ans+=b[i];
			cout<<ans<<endl;
		}

	}

	return 0;
}