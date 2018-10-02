#include <bits/stdc++.h>
using namespace std;

int visited[21][21];
double dp[21][21][10];
double pr[21][21];
int r, c;

double fn(int rs, int cs, int s){
	double pres_pr;
	pres_pr = pr[rs][cs]*pow((1.0 - pr[rs][cs]), visited[rs][cs]);
	if(s == 0)	return pres_pr;
	visited[rs][cs]++;
	double ans = 0.0;
	if(rs > 0)	ans = max(ans, fn(rs - 1, cs, s - 1));
	if(cs > 0)	ans = max(ans, fn(rs, cs - 1, s - 1));
	if(rs < (r - 1))	ans = max(ans, fn(rs + 1, cs, s - 1));
	if(cs < (c - 1))	ans = max(ans, fn(rs, cs + 1, s - 1));
	visited[rs][cs]--;
	return ans + pres_pr;
}

int main(){
	int t;cin>>t;
	int rs, cs, s;
	double p, q;
	int cases=1;
	while(t--){
		cin >> r >> c >> rs >> cs >> s;
		cin >> p >> q;
		for(int i = 0 ; i < r; i++){
			for(int j = 0 ; j < c; j++){
				char var;cin>>var;
				if(var == 'A')	pr[i][j] = p;
				else	pr[i][j] = q;
				visited[i][j] = 0;
			}
		}
		// for(int i = 0; i < 21; i++)
		// 	for(int j = 0; j < 21; j++)
		// 		for(int k = 0; k < 10; k++)
		// 			dp[i][j][k] = -1;
		double ans = 0.0;
		if(s == 0){
			cout.precision(7);
			cout<<"Case #" << cases << ": "<<fixed<<ans<<endl;
			cases++;
			continue;
		}
		if(rs > 0)	ans = max(ans, fn(rs - 1, cs, s - 1));
		if(cs > 0)	ans = max(ans, fn(rs, cs - 1, s - 1));
		if(rs < (r - 1))	ans = max(ans, fn(rs + 1, cs, s - 1));
		if(cs < (c - 1))	ans = max(ans, fn(rs, cs + 1, s - 1));
		cout.precision(7);
		cout<<"Case #" << cases << ": "<<fixed<<ans<<endl;
		cases++;
	}
	return 0;
}
