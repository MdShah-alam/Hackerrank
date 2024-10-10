#include<bits/stdc++.h>
using namespace std;

const int m=100000007;
long countArray(int n,int k,int x)
{
    vector<long long>b(n),a(n);
    a[0]=x==1 ? 1:0;
    b[0]=x==1 ? 0:1;

    for(int i=1;i<n;i++){
        a[i]=b[i-1]%m;
        b[i]=(a[i-1]*(k-1) + b[i-1]*(k-1))%m;
    }
    return a[n-1];
}

int main()
{
    int n,k,x;
    cin>>n>>k>>x;
    cout<<countArray(n,k,x)<<endl;
    return 0;
}

