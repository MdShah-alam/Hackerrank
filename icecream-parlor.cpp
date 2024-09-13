#include<bits/stdc++.h>
using namespace std;

vector<int> icecreamParlor(int m, vector<int> v)
{
    vector<int>k;
    int a=0,b=0;
    for(int i=0;i<v.size();i++){
        for(int j=i+1;j<v.size();j++){
            if(v[i]+v[j]==m){
               k.push_back(i+1);
               k.push_back(j+1);
               return k;
            }
        }
    }
    return k;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int k,n;
        cin>>k>>n;
        vector<int>v(n);
        for(int i=0;i<n;i++)
            cin>>v[i];
        vector<int>vv=icecreamParlor(k,v);
        for(int i=0;i<vv.size();i++)
            cout<<vv[i]<<" ";
        cout<<endl;
    }
    return 0;
}
2
4
5
1 4 5 3 2
4
4
2 2 4 3
