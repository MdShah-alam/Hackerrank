#include<bits/stdc++.h>
using namespace std;

int findSwap(vector<int>v , vector<int>sortv)
{
    int n=v.size();
    map<int,int>mp;
    for(int i=0;i<n;i++){
        mp.insert({v[i],i});
    }
    int result=0;
    for(int i=0;i<n;i++){
        if(v[i]!=sortv[i]){
            result++;
            int swap_index=mp[sortv[i]];
            mp[v[i]]=swap_index;
            mp[sortv[i]]=i;
            swap(v[i],v[swap_index]);
        }
    }
    return result;
}

int lilysHomework(vector<int>v)
{
    vector<int>asv=v;
    sort(asv.begin(),asv.end());
    vector<int>dsv=asv;
    int asSwap=findSwap(v,asv);
    reverse(dsv.begin(),dsv.end());
    int dsSwap=findSwap(v,dsv);
    return min(dsSwap,asSwap);
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    cout<<lilysHomework(v)<<endl;
}
