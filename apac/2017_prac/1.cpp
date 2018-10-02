#include <bits/stdc++.h>


using namespace std;
const int N=1000000007;

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	string s,b;
	for (int q = 1; q <= t; ++q)
	{
		cin>>s;
		int n=s.length();
		if(n==1){
			cout<<"Case #"<<q<<": 1"<<endl;
			continue;
		}
		int sum=1,sum1;
		for (int i = 0; i < n; ++i)
		{
			if(i==0){
				if(s[0]!=s[1]){
					sum*=2;
					sum=sum%N;
				}
			}
			else if(i==n-1){
				if(s[n-1]!=s[n-2]){
					sum*=2;
					sum=sum%N;
				}				
			}
			else if(s[i]!=s[i-1] and s[i]!=s[i+1] and s[i-1]!=s[i+1]){
				sum1 = sum<<1;
				sum1=sum1%N;
				sum+=sum1;
				sum=sum%N;
			}
			else if(s[i]!=s[i-1] or s[i]!=s[i+1] or s[i-1]!=s[i+1]){
				sum<<=1;
				sum=sum%N;
			}
		}
		cout<<"Case #"<<q<<": "<<sum<<endl;
	}
	return 0;
}