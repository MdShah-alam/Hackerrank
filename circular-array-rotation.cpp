#include<bits/stdc++.h>
using namespace std;

vector<int> circularArrayRotation(vector<int> a, int k, vector<int> queries){

    vector<int>v(a.size()),result;

    for(int i=0;i<a.size();i++)
        v[(i+k)%a.size()]=a[i];

    for(int i=0;i<queries.size();i++)
        result.push_back(v[queries[i]]);
    return result;
}

int main()
{
    int n,k,q;
    cin>>n>>k>>q;
    vector<int>v(n),queries(q);

    for(int i=0;i<n;i++)
        cin>>v[i];
    for(int i=0;i<q;i++)
        cin>>queries[i];

    vector<int>r=circularArrayRotation(v,k,queries);
    for(int i=0;i<r.size();i++)
        cout<<r[i]<<" ";
    cout<<endl;
}
