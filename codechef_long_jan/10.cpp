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


ll n;

int main(int argc, char const *argv[])
{
	cin>>n;
	ll m;
//	m = sqrt(n) + 5;
	m = 100010;
	vl sq;
	ll i = 2;
	ll tmp;
	while(1){
		tmp = i*i;
		if(tmp>m)
			break;
		sq.pb(tmp);
		i++;
	}
	int count = 0;
	i = 4;
	while(1){
		tmp = floor(sqrt(i));
		if(tmp*tmp == i){
			cout<<i<<endl;
			count++;
		}
		else{
			for(ll j = 0;;j++){
				if(sq[j] > tmp or sq[j] > i)
					break;
				if(i % sq[j] == 0){
			cout<<i<<endl;
					count++;
					break;
				}
			}
		}
		if(count == n)
			break;
		i++;
	}
	cout<<i<<endl;
	return 0;
}
