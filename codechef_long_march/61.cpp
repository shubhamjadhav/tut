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

void update(vl &a, int l, int r){
	for(int i=l;i<=r;i++)
		a[i]++;
}

int binS(vl &c, int st, int end, int i, ll val){
	if(st == end)
		return st;
	int mid = (st + end) / 2;
	ll now = c[i] - c[mid+1];
	if(now > val)
		return binS(c,mid+1,end,i,val);
	if(c[i] - c[mid] <= val)
		return binS(c,st,mid-1,i,val);
	return mid;
}

int binSRev(vl &c, int st, int end1, int i, ll val){
	if(st == end1)
		return st;
	int mid = (st + end1) / 2;
	ll now = c[mid] - c[i+1];
	if(now > val)
		return binSRev(c,st,mid-1,i,val);
	if(c[mid+1] - c[i+1] <= val)
		return binSRev(c,mid+1,end1,i,val);
	return mid;
}


int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		vl a(n),c(n+1);
		foi(n)
		cin>>a[i];
		foi(n)
		c[i+1] = c[i] + a[i];
		vl tree(2*n + 100);
		foi1(n-1){
			int ind;
			if(a[i] >= c[i] - a[0]){
				ind = 0;
			}
			else
				ind = binS(c,0,i-1,i,a[i]);
			update(tree,ind,i-1);
		}

		// foi(n)
		// cout<<get(tree,1,0,n-1,i)<<" ";
		// cout<<endl;

		foi(n-1){
			int ind;
			if(c[n-1] - c[i+1] <= a[i])
				ind = n-1;
			else
				ind = binSRev(c,i+1,n-1,i,a[i]);
			update(tree,i+1,ind);
		}
		foi(n)
		cout<<tree[i]<<" ";
		cout<<endl;
	}
	return 0;
}