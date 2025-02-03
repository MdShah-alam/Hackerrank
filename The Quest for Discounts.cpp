#include <iostream>
#include <vector>
using namespace std;

bool isDPLChar(char c) {
    return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}
bool three(const string &s)
{
    int n = s.size();
    for (int i = 0; i <= n - 3; ++i) {
        int dplCount = 0, nonDplCount = 0, unknownCount = 0;
        for (int j = 0; j < 3; ++j) {
            if (s[i + j] == '?') unknownCount++;
            else if (isDPLChar(s[i + j])) dplCount++;
            else nonDplCount++;
        }
        if (dplCount + unknownCount >= 3) return true;
    }
    return false;
}
bool five(const string &s)
{
    int n = s.size();
     for (int i = 0; i <= n - 5; ++i) {
        int dplCount = 0, nonDplCount = 0, unknownCount = 0;
        for (int j = 0; j < 5; ++j) {
            if (s[i + j] == '?') unknownCount++;
            else if (isDPLChar(s[i + j])) dplCount++;
            else nonDplCount++;
        }
        if (nonDplCount + unknownCount >= 5) return true;
    }
    return false;
}
string classifyName(const string &s) {
    int n = s.size();
    bool canBeDPL100 = three(s) || five(s);
    bool canBeDPL00 = false;

    string k=s,m=s;
    bool found=false;
    for(int i=0;i<n;i++){
        if(s[i]=='?'){
            found=true;
            break;
        }
    }
    for(int i=0;i<s.size();i++){
        if(k[i]=='?')
            k[i]='A';
    }
    for(int i=0;i<s.size();i++){
        if(m[i]=='?')
            m[i]='M';
    }
    if(found)
        canBeDPL00 = !three(k) || !five(m);

    if (canBeDPL100 && canBeDPL00) return "50%";
    if (canBeDPL100) return "100%";
    return "0%";
}

int main() {
    int t;
    cin>>t;
    int i=1;
    while(i<=t){
        string s;
        cin>>s;
        cout << "Case "<<i<<": " << classifyName(s) << endl;
        i++;
    }

    return 0;
}
