#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    stack<string>st;
    string s="";
    while(t--){
        int a;
        cin>>a;
        if(a==1){
            string s1;
            cin>>s1;
            st.push(s);
            s+=s1;
        }
        else if(a==2){
            int k;
            cin>>k;
            st.push(s);
            s.erase(s.size()-k,k);
        }
        else if(a==3){
            int k;
            cin>>k;
            cout<<s[k-1]<<endl;
        }
        else{
            s=st.top();
            st.pop();
        }
    }
}
/**

8
1 abc
3 3
2 3
1 xy
3 2
4
4
3 1

*/
