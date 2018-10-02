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

class tup{
public:
	string s;
	int count;
	tup(){
		s="";
		count=0;
	}
	tup(string p, int k):s(p),count(k){}
};

bool f(const tup&a, const tup&b){
	if(a.count != b.count)
		return a.count > b.count;
	return a.s < b.s;
}

int getC(string &s){
	vb c(26);
	int j;
	foi(s.le){
		j = s[i] - 'A';
		if(j>=0 and j<26)
			c[j]=1;
	}
	int ans = 0;
	foi(26){
		if(c[i])
			ans++;
	}
	return ans;
}

int main(){
	int tc;
	cin>>tc;
	for(int test_case = 1; test_case <= tc; test_case++){
		printf("Case #%d: ", test_case);
		cin>>n;
		string s;
		vector<tup> v;
		getline(cin, s);
		foi(n){
			getline(cin,s);
			// cin>>s;
			v.pb(tup(s, getC(s)));
		}
		// foi(n){
		// 	cout<<i<<" "<<v[i].s<<" "<<v[i].count<<endl;
		// }
		sort(v.begin(), v.end(), f);
		cout<<v[0].s<<endl;
	}
	return 0;
}