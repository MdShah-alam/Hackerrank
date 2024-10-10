#include<bits/stdc++.h>
using namespace std;

int longestIncreasingSubsequence(vector<int> v) {
    vector<vector<int>>L(v.size());
    L[0].push_back(v[0]);

    for(int i=1;i<v.size();i++){
        for(int j=0;j<i;j++){
            if( (v[j]<v[i]) && (L[i].size()<L[j].size()))
                L[i]=L[j];
        }
        L[i].push_back(v[i]);
    }
    int i=0;
    for(int j=0;j<L.size();j++)
        i = max(i , (int)L[j].size());
    return i;
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    cout<<longestIncreasingSubsequence(v)<<endl;
}
