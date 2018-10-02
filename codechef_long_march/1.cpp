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
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vi a(n), b(n);
		foi(n)
		cin>>a[i];
		foi(n)
		cin>>b[i];
		bool l = 1, r = 1;
		foi(n){
			if(a[i] > b[i]){
				l = 0;
				break;
			}
		}
		foi(n){
			if(a[n-i-1] > b[i]){
				r = 0;
				break;
			}
		}
		if(l and r)
			cout<<"both"<<endl;
		else if(l)
			cout<<"front"<<endl;
		else if(r)
			cout<<"back"<<endl;
		else
			cout<<"none"<<endl;
	}

	return 0;
}