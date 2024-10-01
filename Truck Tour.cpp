#include<bits/stdc++.h>
using namespace std;

int truckTour(vector<vector<int>>v)
{
    int n=v.size();
    queue<pair<int,int>>pr;
    for(int i=0;i<n;i++){
        int a,b;
        a=v[i][0];
        b=v[i][1];
        pr.push({a,b});
    }
    int f=0,r=0,i=0,balance=0;
    while(i!=n){
        int a=pr.front().first;
        int b=pr.front().second;
        pr.pop();
        pr.push({a,b});
        balance+=a;
        balance-=b;
        cout<<balance<<endl;
        if(balance<0){
            f=i;
            r=i;
            balance=0;
        }
        i++;
    }
    if(balance<0)
        return -1;
    return f+1;
}

int main()
{
    int n;
    cin>>n;
    vector<vector<int>>v;
    for(int i=0;i<n;i++){
        vector<int>v1;
        for(int j=0;j<2;j++){
            int a;
            cin>>a;
            v1.push_back(a);
        }
        v.push_back(v1);
    }

    cout<<truckTour(v)<<endl;

    return 0;
}
