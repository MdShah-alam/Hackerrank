#include<bits/stdc++.h>
using namespace std;

int sherlockAndAnagrams(string s)
{
    int n=s.size();
    unordered_map<string,int>m;
    for(int i = 0; i < n; i++){
        // Inner loop defines the length of the substring
        for (int len = 1; len <= n - i; len++) {
            string sub = s.substr(i, len);
            sort(sub.begin(),sub.end());
            m[sub]++;
        }
    }
    int ans=0;
    for(auto x:m){
        int n=x.second;
        if(n==1)
            continue;
        else{
            ans+=(n*(n-1))/2;
        }
    }
    return ans;
}

int main()
{
    string s;
    cin>>s;
    cout<<sherlockAndAnagrams(s)<<endl;
    return 0;
}
