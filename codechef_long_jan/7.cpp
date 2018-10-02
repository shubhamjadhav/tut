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

#define N 1000000

int a[N];

int x,y;

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	foi(n)
	cin>>a[i];
	int q;
	cin>>q;
	if(n<1025 and q<2050){
		foi(q){
			cin>>x>>y;
			int ans=0;
			foj(n){
				if(a[j]>0){
					if((j & x) == j)
						a[j] -= y;
				}
				if(a[j]>0)
					ans++;
			}
			cout<<ans<<endl;
		}
	}
	else{
		set<int> seen;
		int tmp;
		list<int> l;
		foi(n){
			l.push_back(i);
		}
		foi(q){
			cin>>x>>y;
			if(seen.find(x)==seen.end()){
				seen.insert(x);
				for(list<int>::iterator it=l.begin();it!=l.end();it++){
					tmp = *it;
					if((tmp & x) == tmp){
						l.erase(it);
						it--;
					}
				}
			}
			cout<<l.si<<endl;
		}
	}
	return 0;
}