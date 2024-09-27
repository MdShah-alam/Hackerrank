#include<bits/stdc++.h>
using namespace std;

int pickingNumbers(vector<int> a) {
    int b=0;
    int cont=0;
    for(int i=0;i<a.size();i++){
        cont=0;
        for(int j=0;j<a.size();j++){
            if((a[i]-a[j])==0 || (a[i]-a[j])==1){
                cont++;
            }
        }
        b=max(b,cont);
    }
    return b;
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    cout<<pickingNumbers(v)<<endl;
}
