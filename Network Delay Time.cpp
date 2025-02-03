#include<bits/stdc++.h>
using namespace std;

int networkDelayTime(vector<vector<int>>&times,int n,int k){
    unordered_map<int, vector<pair<int, int>>> edges;
    for (const auto& time : times) {
        edges[time[0]].push_back({time[1], time[2]});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minHeap;
    minHeap.push({0,k});
    unordered_map<int,int>visit;
    int t=0;
    while (!minHeap.empty()) {
        auto [w1, n1] = minHeap.top();
        minHeap.pop();

        if (visit.count(n1)) continue;
        visit[n1] = w1;
        t = max(t, w1);
        for (const auto& [n2, w2] : edges[n1]) {
            if (!visit.count(n2)) {
                minHeap.push({w1 + w2, n2});
            }
        }
    }
    return (visit.size() == n) ? t : -1;
}

int main()
{
    int n;
    cin>>n;
    vector<vector<int>>v;
    for(int i=0;i<n;i++){
        vector<int>k(3);
        for(int i=0;i<3;i++){
            cin>>k[i];
        }
        v.push_back(k);
    }
    int start,endNode;
    cin>>endNode>>start;
    cout<<networkDelayTime(v,endNode,start)<<endl;
    return 0;
}/**

4
1 2 1
2 3 1
1 4 4
3 4 1
4 1

1
1 2 1
2 2

*/
