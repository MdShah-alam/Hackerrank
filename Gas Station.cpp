#include<bits/stdc++.h>
using namespace std;

int f(int i,vector<int>&gas,vector<int>&cost)
{
    int n=gas.size()+1;
    int m=gas[i];
    int k=gas.size()-1;
    int ans=i;
    while(n--){
        if(m<cost[i]) return -1;
        if(i==k){
            m=m-cost[i];
            i=0;
            m=m+gas[i];
        }
        else{
            m=m-cost[i]+gas[i+1];
            i++;
        }
    }
    return ans;
}
int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
{
    for(int i=0;i<gas.size();i++){
        int ans=f(i,gas,cost);
        if(ans!=-1) return ans;
    }
    return -1;
}

int main()
{
    int n;
    cin>>n;
    vector<int>gas(n),cost(n);
    for(int i=0;i<n;i++)
        cin>>gas[i];
    for(int i=0;i<n;i++)
        cin>>cost[i];
    cout<<canCompleteCircuit(gas,cost)<<endl;
    return 0;
}

/**

4
1 2 3 4
2 2 4 1


3
1 2 3
2 3 2

5
1 2 3 4 5
3 4 5 1 2

*/
