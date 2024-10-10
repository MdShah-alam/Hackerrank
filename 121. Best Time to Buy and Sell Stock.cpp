#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& v)
{
    int l=0,r=1;
    int maxprofit=0;
    while(r<v.size()){
        if(v[l]<v[r]){
            int ans=v[r]-v[l];
            maxprofit=max(ans,maxprofit);
        }
        else
            l=r;
        r++;
    }
    return maxprofit;
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    cout<<maxProfit(v);
}
/**

6
7 2 5 3 1 6

*/
