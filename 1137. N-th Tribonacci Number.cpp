#include<bits/stdc++.h>
using namespace std;

int dp[50];
int fun(int n)
{
    if(n==0) return 0;
    if(n<=2) return 1;
    if(dp[n]!=-1) return dp[n];
    dp[n]=fun(n-3)+fun(n-2)+fun(n-1);
    return dp[n];
}
int tribonacci(int n)
{
    for(int i=0;i<=n;i++)
        dp[i]=-1;
    return fun(n);
}

int main()
{
    int n;
    cin>>n;
    cout<<tribonacci(n)<<endl;
    return 0;
}
