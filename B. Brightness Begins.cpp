#include<bits/stdc++.h>
using namespace std;

long long call(long long a)
{
    long long x=sqrt(a)+2;
    while(x*x>a){
        x--;
    }
    return x;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        long long k;
        cin>>k;
        unsigned long long l=0 , r=10e19 , ans=0;
        while(l<=r){
            unsigned long long mid = (l+r)>>1;
            unsigned long long root = call(mid);
            if(mid-root>=k){
                ans=mid;
                r=mid-1;
            }
            else
                l=mid+1;
        }
        cout<<ans<<endl;
    }
}
