#include<bits/stdc++.h>
using namespace std;

const int M = 100000007;
int substrings(string s)
{
    int prev=0,total=0;
    int i=0;
    while(i<s.size()){
        prev=prev*10 + (s[i]-'0')*(i+1);
        prev=prev % M;
        total=total+prev;
        i++;
    }
    return total;
}

int main()
{
    string s;
    cin>>s;
    cout<<substrings(s)<<endl;
    return 0;
}
