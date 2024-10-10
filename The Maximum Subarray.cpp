#include<bits/stdc++.h>
using namespace std;

vector<int>maxSubarray(vector<int>v)
{
    int cursum=0,maxsum=0,i=0,j=0;
    while(i<v.size()){
        cursum+=v[i];
        if(maxsum<cursum)
            maxsum=cursum;
        if(cursum<0)
            cursum=0;
        i++;
    }
    int ans1=0;
    while(j<v.size()){
        if(v[j]>0)
            ans1+=v[j];
        j++;
    }
    if(maxsum==ans1 && maxsum==0){
        sort(v.begin(),v.end());
        return {v[v.size()-1],v[v.size()-1]};
    }
    else
        return {maxsum,ans1};
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>v(n);
        for(int i=0;i<n;i++)
            cin>>v[i];
        vector<int>a=maxSubarray(v);
        cout<<a[0]<<" "<<a[1]<<endl;
    }
    return 0;
}
