#include<bits/stdc++.h>
using namespace std;

int jump(vector<int>&v)
{
    int n=v.size();
    if(v[0]==0 || n==1)return 0;
    int fastest=0,currentend=0,jump=0;
    for(int i=0;i<n;i++){
        fastest=max(fastest,v[i]+i);
        if(i==currentend){
            jump++;
            currentend=fastest;
            if (currentend >= n - 1) break;

        }
    }
    return jump;
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    cout<<jump(v)<<endl;
    return 0;
}
