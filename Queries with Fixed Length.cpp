#include<bits/stdc++.h>
using namespace std;

vector<int>solve(vector<int>ar , vector<int>q)
{
    vector<int>v;
    for(int j=0;j<q.size();j++){
        vector<vector<int>>ans;
        for(int k=0;k<ar.size()-q[j]+1;k++){
            vector<int>result;
            int i=k,a=0;
            while(a<q[j] && k+q[j]<=ar.size()){
                result.push_back(ar[i]);
                i++;
                a++;
            }
            ans.push_back(result);
        }
        vector<int>v1;

        for(int a=0;a<ans.size();a++){
            int an=0;
            for(int b=0;b<ans[a].size();b++){
                an=max(an,ans[a][b]);
            }
            v1.push_back(an);
        }
        sort(v1.begin(),v1.end());
        v.push_back(v1[0]);
    }
    return v;
}

int main()
{
    int n,q;
    cin>>n>>q;
    vector<int>ar(n),d(q);
    for(int i=0;i<n;i++)
        cin>>ar[i];
    for(int i=0;i<q;i++)
        cin>>d[i];

    vector<int>v=solve(ar,d);
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
    cout<<endl;
    return 0;
}
/**

5 3
33 11 44 11 55
3
4
5

*/

