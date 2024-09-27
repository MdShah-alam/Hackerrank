#include<bits/stdc++.h>
using namespace std;

string appendAndDelete(string s, string t, int k) {
    if(k >= t.size() + s.size()) return "Yes";
    int same = min(t.size(), s.size());
    for(int i = 0; i< min(t.size(), s.size()); i++){
        if(s[i] != t[i]){
            same = i;
            break;
        }
    }
    k -= (s.size() - same);
    k -= (t.size() - same);
    return (k >= 0 && k%2 == 0)? "Yes":"No";
}

int main()
{
    string s,t;
    int k;
    cin>>s>>t>>k;
    cout<<appendAndDelete(s,t,k)<<endl;
    return 0;
}
