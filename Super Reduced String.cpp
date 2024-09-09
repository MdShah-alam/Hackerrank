#include<bits/stdc++.h>
using namespace std;

string superReducedString(string s) {
    stack<char>st;
    for(int i=0;i<s.size();i++){
        char c=s[i];
        if(st.empty())
            st.push(c);
        else if(st.top()==c){
            st.pop();
        }
        else{
            st.push(c);
        }
    }
    string k="";
    while(!st.empty()){
        char x = st.top();
        st.pop();
        string a(1, x);
        k=k+a;
    }
    return reverse k;
}

int main()
{
    string s;
    cin>>s;
    cout<<superReducedString(s)<<endl;
    return 0;
}
