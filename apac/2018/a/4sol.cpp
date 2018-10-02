#include <bits/stdc++.h>

#define icin(x) scanf("%d",&x)
#define pb push_back
#define LL long long
#define F first
#define S second
#define eps ((double)1e-14)
#define maxn 109
#define maxm 100009

using namespace std;

int dp[15][500000];
int mus[15][15];
int cost[15][15];
int sum_cost[15][15];
int curl[15],maxl[15];

int main()
{
  int t;
  icin(t);
  for(int tc=1;tc<=t;tc++)
  {
    int m,n;
    icin(m);
    icin(n);
    memset(dp,-1,sizeof(dp));
    memset(sum_cost,0,sizeof(sum_cost));
    int init=0;
    for(int i=1;i<=n;i++)
    {
      icin(maxl[i]);
      icin(curl[i]);
      for(int j=1;j<=maxl[i];j++)
        icin(mus[i][j]);
      init += mus[i][curl[i]];
      for(int j=2;j<=maxl[i];j++)
      {
        icin(cost[i][j]);
        sum_cost[i][j] = sum_cost[i][j-1] + cost[i][j];
      }
    }
    //  cout << "OUT" << init << endl;
//    for(int i=0;i<=init;i++)
    
    for(int i=0;i<=8;i++)
    dp[i][init]=0;
    
    for(int i=1;i<=8;i++)
    {
      for(int j=curl[i]+1;j<=maxl[i];j++)
      {
        //cout << i << " " << j << endl;
        int mm = sum_cost[i][j] - sum_cost[i][curl[i]];
        int mp = mus[i][j] - mus[i][curl[i]];
        for(int k=0;k<=100000;k++)
        {
          if(dp[i-1][k]!=-1)
          {
              if(dp[i][k+mp]==-1)
              dp[i][k+mp] = dp[i-1][k] + mm;
            else
              dp[i][k+mp] = min(dp[i][k+mp], dp[i-1][k] + mm);
          }
        }
  
      }
      for(int k=0;k<=100000;k++)
      {
        if(dp[i][k]==-1)
          dp[i][k]=dp[i-1][k];
        else if(dp[i-1][k]!=-1)
          dp[i][k] = min(dp[i-1][k],dp[i][k]);
      }
    }

    int ans =0,x;
    for(int i=0;i<=100000;i++)
    {
      if(dp[8][i]<=m && dp[8][i]!=-1)
      {
        ans=i;
        x = dp[8][i];
      }
    }
    printf("Case #%d: %d\n",tc,ans);
  }
}