#include<bits/stdc++.h>
using namespace std;

int maxRepeating(string s, string w) {
    int maxK=0;
    string repeated=w;
    while (s.find(repeated) != string::npos) {
        maxK++;
        repeated += w;
    }
    return maxK;
}

int main()
{
    string s,w;
    cin>>s>>w;
    cout<<maxRepeating(s,w)<<endl;
    return 0;
}
