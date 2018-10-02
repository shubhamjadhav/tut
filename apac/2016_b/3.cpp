#include <bits/stdc++.h>

using namespace std;

// #define vs vector<string >
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
#define vs vector<string>

class tup{
public:
	ll a, b;
	int k;
	tup(){
		a=b=k=0;
	}
	tup(ll a1, ll b1, int k1){
		a = a1;
		b = b1;
		k = k1;
	}
};

bool f(const tup&p, const tup&q){
	if(p.b == q.b)
		return p.a < q.a;
	if(p.a != q.a)
		return p.a < q.a;
	if(!p.b)
		return 1;
	return 0;
}

int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	for(int test_case = 1;test_case<=tc;test_case++){
		// printf("Case #%d: ",test_case);
		ll n, l1, r1, t1, t2, a, b, c1, c2, m;
		cin>>n>>l1>>r1>>a>>b>>c1>>c2>>m;
		vt in(n);
		vt v;
		in[0].a = l1;
		in[0].b = r1;
		v.pb(tup(l1, 0, 0));
		v.pb(tup(r1, 1, 0));
		foi1(n-1){
			t1 = (a*in[i-1].a + b*in[i-1].b + c1)%m;
			t2 = (a*in[i-1].b + b*in[i-1].a + c2)%m;
			in[i].a = min(t1, t2);
			in[i].b = max(t1, t2);
			v.pb(tup(in[i].a, 0, i));
			v.pb(tup(in[i].b, 1, i));
		}
		sort(v.begin(), v.end(), f);
		ll count = 0;
		set<int> curr;
		vl sum(n);
		ll overlap = 0, st, st1;
		foi(v.si){
			cout<<v[i].a<<" "<<v[i].b<<" "<<v[i].k<<endl;
			// cout<<"ASD"<<endl;
			if(!v[i].b){
				overlap++;
				if(overlap==1){
					st = v[i].a;
					st1 = v[i].a;
				}
				else if(overlap==2){
					int ind = *(curr.begin());
					sum[ind] += v[i].a - st;
				}
				curr.insert(v[i].k);
			}
			else{
				overlap--;
				if(overlap==1){
					st = v[i].a + 1;
				}
				else if(!overlap){
					int ind = *(curr.begin());
					ll tmp = v[i].a - st + 1;
					if(tmp>0)
					sum[ind] += tmp;
					count += v[i].a - st1 + 1;
				}
				curr.erase(v[i].k);
			}
		}
		ll mm = 0;
		foi(n)
		mm = max(mm, sum[i]);
		// cout<<mm<<endl;
		cout<<count - mm<<endl;
	}
	return 0;
}
