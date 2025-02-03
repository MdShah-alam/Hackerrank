#include<bits/stdc++.h>
using namespace std;

vector<int>partitionLabels(string s)
{
    unordered_map<char,int>mp;
    for(int i=0;i<s.size();i++){
        mp[s[i]]=i;
    }
    vector<int>v;
    int st=0,ed=0;
    for(int i=0;i<s.size();i++){
        st+=1;
        ed=max(ed,mp[s[i]]);
        if(i==ed){
            v.push_back(st);
            st=0;
        }
    }
    return v;
}

int main()
{
    string s;
    cin>>s;
    vector<int>v=partitionLabels(s);
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
    cout<<endl;
    return 0;
}
