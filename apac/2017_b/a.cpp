#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define pb push_back
#define vi vector<int>
#define vii vector<vi >
#define vb vector<bool>
#define vbb vector<vb >
#define vl vector<long long int>
#define vll vector<vl >
#define foi(x) for (int i = 0; i < x; ++i)
#define foj(x) for (int j = 0; j < x; ++j)
#define foi1(x) for (int i = 1; i <= x; ++i)
#define foj1(x) for (int j = 1; j <= x; ++j)
#define le length()
#define si size()

double a,b;
int n,m;

double f(int i,int j, vbb is, int steps,vbb &p){
	// printf("fdfdf\n");
	if(!steps)
		return 0;
	double ans=0.0;
	double tt;
	if(i>0 and !is[i-1][j]){
		if(p[i-1][j])
			tt=a;
		else
			tt=b;
		double cc=1.0-tt;
		ans = max(ans,cc+f(i-1,j,is,steps-1,p));
		is[i-1][j]=1;
		ans = max(ans,tt+f(i-1,j,is,steps-1,p));
	}
	if(i<n-1 and !is[i+1][j]){
		if(p[i+1][j])
			tt=a;
		else
			tt=b;
		double cc=1.0-tt;
		ans = max(ans,cc+f(i-1,j,is,steps-1,p));
		is[i-1][j]=1;
		ans = max(ans,tt+f(i+1,j,is,steps-1,p));
	}
	if(j>0 and !is[i][j-1]){
		if(p[i][j-1])
			tt=a;
		else
			tt=b;
		double cc=1.0-tt;
		ans = max(ans,cc+f(i-1,j,is,steps-1,p));
		is[i-1][j]=1;
		ans = max(ans,tt+f(i,j-1,is,steps-1,p));
	}
	if(j<m-1 and !is[i][j+1]){
		if(p[i][j+1])
			tt=a;
		else
			tt=b;
		ans = max(ans,tt+f(i,j+1,is,steps-1,p));
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	int t,x,y,s,p,q;
	char c;
	scanf("%d",&t);
	for (int qq = 1; qq < t+1; ++qq)
	{
		cin>>n>>m>>x>>y>>s;
		vbb P(n,vb(m));
		string S;
		// double a,b;
		cin>>a>>b;
		foi(n){
			foj(m){
				scanf("\n%c",&c);

				if(c=='.')
					P[i][j]=0;
				else
					P[i][j]=1;
			}
		}
		// foi(n){
		// 	foj(m){
		// 		cout<<P[i][j]<<" ";
		// 	}
		// 	cout<<endl;
		// }
		double ans=0;
		vbb isi(n,vb(m));
		cout<<s<<endl;
		ans = f(x,y,isi,s,P);
		printf("Case #%d: ",qq );
		cout<<ans<<endl;
	}
	return 0;
}