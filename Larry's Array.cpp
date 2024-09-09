#include<bits/stdc++.h>
using namespace std;

string larrysArray(vector<int> v)
{
    int a=0;
    for(int i=0;i<v.size();i++){
        int b=0;
        for(int j=i+1;j<v.size();j++){
            if(v[i]>v[j])
                b++;
        }
        a=a+b;
    }
    if(a%2==0)
        return "YES";
    else
        return "NO";
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>v(n);
        for(int i=0;i<n;i++)
            cin>>v[i];
        cout<<larrysArray(v)<<endl;
    }
    return 0;
}
