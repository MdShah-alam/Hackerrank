#include<bits/stdc++.h>
using namespace std;

string highestValuePalindrome(string s, int n, int k)
{
    int ar[n]={0};
    int l=0;
    int r=n-1;

    while(l<=r){
        if(s[l]!=s[r]){
            if(s[l]>s[r]){
                s[r]=s[l];
                ar[r]=1;
            }
            else{
                s[l]=s[r];
                ar[l]=1;
            }
            k-=1;
        }
        l++;
        r--;
    }
    if(k<0)
        return "-1";
    l=0;
    r=n-1;
    while(l<=r){
        if(l==r && k>=1)
            s[l]='9';
        if(s[l]<'9'){
            if((ar[l]==0 &&ar[r]==0)&& k>=2){
                s[l]='9';
                s[r]='9';
                k-=2;
            }
            else if((ar[l]==1 || ar[r]==1) && k>=1){
                s[l]='9';
                s[r]='9';
                k-=1;
            }
        }
        l++;
        r--;
    }
    return s;
}

int main()
{
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    cout<<highestValuePalindrome(s,n,k)<<endl;
    return 0;
}
