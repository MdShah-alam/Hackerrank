#include<bits/stdc++.h>
using namespace std;

bool isNStraightHand(vector<int>& hand, int groupSize)
{
    if(hand.size()%groupSize!=0) return false;
    unordered_map<int,int>cont;
    for(int x : hand)
        cont[x]++;
    priority_queue<int, vector<int> ,greater<int>>minHeap;
    for(auto& [key,_]:cont)
        minHeap.push(key);
    while(!minHeap.empty()){
        int first=minHeap.top();
        for(int i=first;i<first+groupSize;i++){
            if(cont[i]==0)
                return false;
            cont[i]--;
            if(cont[i]==0){
                if(i!=minHeap.top())
                    return false;
                minHeap.pop();
            }
        }
    }
    return true;
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    int groupsize;
    cin>>groupsize;
    cout<<isNStraightHand(v,groupsize)<<endl;
    return 0;
}
