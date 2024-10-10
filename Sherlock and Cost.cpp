#include<bits/stdc++.h>
using namespace std;

int cost(vector<int>v)
{
    int n=v.size();
    int pre1=0,pre2=0,max1=0,max2=0;

    for(int i=1;i<n;i++){
        max1=max(pre1+abs(v[i]-v[i-1]),pre2+abs(1-v[i]));
        max2=pre1+abs(1-v[i-1]);

        pre1=max1;
        pre2=max2;
    }
    return max(max1,max2);
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];

    cout<<cost(v)<<endl;
    return 0;
}
