#include<bits/stdc++.h>
using namespace std;

int minSubArrayLen(int target , vector<int>&v)
{
    int n=v.size();
    int total=0,l=0;
    int ans=INT_MAX;
    for(int r=0; r<n; r++){
        total+=v[r];
        while(total>=target){
            ans=min(ans,r-l+1);
            total-=v[l];
            l++;
        }
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    int target;
    cin>>target;
    cout<<minSubArrayLen(target,v)<<endl;
    return 0;
}
/**


6
2 3 1 2 4 3
7

*/
