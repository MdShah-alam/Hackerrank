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

int flatlandSpaceStations(int n, vector<int>c)
{
    vector<int>v=countSort(c,n);
    int result = v[0];
    for(int i = 1; i < v.size(); i++){
        result = max(result, (v[i] - v[i-1]) / 2 );
    }
    result = max(result, n - 1 - v[v.size() - 1]);
    return result;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>v(m);
    for(int i=0;i<m;i++)
        cin>>v[i];

    cout<<flatlandSpaceStations(n,v)<<endl;
    return 0;
}
