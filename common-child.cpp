#include<bits/stdc++.h>
using namespace std;

int commonChild(string s1, string s2)
{
    int n=s1.size();
    int m=s2.size();
    int ar[n+1][m+1];
    for(int i=0;i<m+1;i++)
        ar[0][i]=0;
    for(int i=0;i<n+1;i++)
        ar[i][0]=0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1])
                ar[i][j]=ar[i-1][j-1]+1;
            else
                ar[i][j]=max(ar[i][j-1],ar[i-1][j]);
        }
    }
    return ar[n][m];
}

int main()
{
    string s,s2;
    cin>>s>>s2;
    cout<<commonChild(s,s2)<<endl;
    return 0;
}
