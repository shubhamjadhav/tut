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

bool f(const pair<int, int>&p, const pair<int, int> &q){
	return p.first < q.first;
}

int main(){
	cin>>n;
	// assert()
	int a[1001],b[1001];
	foi(n){
		cin>>a[i];
	}
	foi(n){
		cin>>b[i];
	}
	vector<pair<int, int> > v(n);
	foi(n){
		v[i].first = a[i] - b[i];
		v[i].second = i;
		string s(a[i]-b[i],'w');
		s+=string(b[i],'b');
		cout<<s<<endl;
	}
	sort(v.begin(), v.end(), f);
	deque<int> q;
	q.pb(v[0].second);
	
	foi(n){
		
	}
	cout<<endl;
	return 0;
}

