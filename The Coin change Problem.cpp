#include<bits/stdc++.h>
using namespace std;

long getWays(int n, vector<long> c)
{
    int m=c.size();
    long dp[m+1][n+1];
    for(int i=0;i<=n;i++)
        dp[0][i]=0;
    for(int i=0;i<=m;i++)
        dp[i][0]=1;

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(j>=c[i-1])
                dp[i][j]=dp[i][j-c[i-1]]+dp[i-1][j];
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    return dp[m][n];
}

int main()
{
    int sum,n;
    cin>>sum>>n;
    vector<long>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    cout<<getWays(n,v)<<endl;
    return 0;
}
