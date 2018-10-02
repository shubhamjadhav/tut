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

ll getT(vl &a, ll k){
	ll ans = 0;
	foi(a.si){
		ans += a[i] / k;
		if(a[i] % k != 0)
			ans++;
	}
	return ans;
}

ll n, h;

ll binS(vl &a, ll i, ll j){
	if(j - i <= 1)
		return i;
	ll mid = (j - i) / 2 + i;
	if(getT(a,mid) > h)
		return binS(a, mid+1, j);
	if(getT(a, mid - 1) <= h)
		return binS(a,i,mid);
	return mid;
}

ll max_val(vl &a){
	ll ans = 0;
	foi(a.si)
	ans = max(ans, a[i]);
	return ans;
}

int main(){
	ll t;
	cin>>t;
	while(t--){
		cin>>n>>h;
		vl a(n);
		foi(n)
		cin>>a[i];
		if(h == n){
			cout<<max_val(a)<<endl;
			continue;
		}
		if(getT(a, 1) <= h)
			cout<<1<<endl;
		else
			cout<<binS(a, 1, 2000000001)<<endl;
	}
	return 0;
}