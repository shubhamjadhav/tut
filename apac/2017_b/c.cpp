#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define pb push_back
#define vi vector<int>
#define vii vector<vi >
#define vs vector<string>
#define vss vector<vs >
#define vb vector<bool>
#define vbb vector<vb >
#define foi(x) for (int i = 0; i < x; ++i)
#define foj(x) for (int j = 0; j < x; ++j)
#define foi1(x) for (int i = 1; i <= x; ++i)
#define foj1(x) for (int j = 1; j <= x; ++j)
#define le length()
#define si size()

class graph{
public:
	vii v;
	graph(int n){
		vii w(n);
		v=w;
	}
	void addE(int a, int b){
		v[a].pb(b);
		return;
	}
	void isc(int k, vi &is,bool &found){
		if(found)
			return;
		is[k]=1;
		foi(v[k].si){
			int y=v[k][i];
			if(is[y]==0){
				isc(y,is,found);
				if(found)
					return;
			}
			else if(is[y]==1){
				found=1;
				return;
			}
		}
		is[k]=2;
		return;
	}
};



int main(int argc, char const *argv[])
{
	int t,n,m;
	scanf("%d",&t);
	for (int qq = 1; qq < t+1; ++qq)
	{
		cin>>m;
		bool fine=1;
		graph g(10000);
		int curr=0;
		map<string,int> v;
		map<string,int> args;
		map<int,bool> leaf;
		string s,x,y,z,fname;
		int par,child;
		int p,q;
		foi(m){
			cin>>s;
			if(!fine)
				continue;
			p=s.find('=');
			assert(p>0);
			x=s.substr(0,p);	//var1
			if(v.find(x)==v.end()){
				v[x]=curr;
				curr++;
			}

			par=v[x];

			s=s.substr(p+1,s.length()-p-1);
			// cout<<s<<endl;
			p=s.find('(');
			assert(p>0);
			fname=s.substr(0,p);	//fname
			// cout<<"fname is "<<fname<<endl;
			s=s.substr(p,s.le-p);
			// cout<<s<<endl;
			assert(s[0]=='(');
			assert(s[s.le-1]==')');
			s=s.substr(1,s.le-2);
			int ac=0;
			p=s.find(',');
			while(p>0){
				x=s.substr(0,p);	//var1
				if(v.find(x)==v.end()){
					v[x]=curr;
					curr++;
				}
				child = v[x];
				if(child==par)
					fine=0;
				g.addE(par,child);
				s=s.substr(p+1,s.length()-p-1);
				p=s.find(',');
				ac++;
			}
			if(s.le>0){
				ac++;
				if(v.find(s)==v.end()){
					v[s]=curr;
					curr++;
				}
				child = v[s];
				g.addE(par,child);
			}
			if(args.find(fname)==args.end()){
				args[fname]=ac;
			}
			else{
				if(args[fname]!=ac)
					fine=0;
			}
			if(!ac){
				assert(leaf.find(par)==leaf.end());
				leaf[par]=1;
			}
		}
		if(!fine){
			printf("Case #%d: BAD\n",qq );
			continue;
		}
		assert(curr==v.si);
		assert(curr<=10000);
		vi is(curr);
		bool bb=0;
		foi(curr){
			if(!is[i]){
				g.isc(i,is,bb);
				if(bb){
					printf("Case #%d: BAD\n",qq );
					break;
				}
			}
		}
		if(!bb){
			bool fff=0;
			foi(curr){
				if(g.v[i].si==0){
					if(leaf.find(i)==leaf.end()){
						fff=1;
						break;
					}
				}
			}
			if(fff)
				printf("Case #%d: BAD\n",qq );
			else
				printf("Case #%d: GOOD\n",qq );
		}
	}
	return 0;
}