#include<bits/stdc++.h>
using namespace std;

vector<int>countSort(vector<int>v,int n)
{
    vector<int>cont(n,0),result(v.size());
    for(int i=0;i<v.size();i++)
        cont[v[i]]++;

    for(int i=1;i<n;i++)
        cont[i]+=cont[i-1];

    for(int i=v.size()-1;i>=0;i--){
        result[cont[v[i]]-1]=v[i];
        cont[v[i]]--;
    }
    return result;
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];

    vector<int>vv=countSort(v,n);
    for(int i=0;i<vv.size();i++)
        cout<<vv[i]<<" ";
    cout<<endl;
    return 0;
}
