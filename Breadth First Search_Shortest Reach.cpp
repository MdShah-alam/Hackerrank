#include<bits/stdc++.h>
using namespace std;

vector<int> bfs(int n, int m, vector<vector<int>> edges, int s)
{
    vector<int>adj[n+1];
    int visit[n+1];
    for(int i=0;i<=n;i++)
        visit[i]=0;

    for(vector<int>k:edges){
        adj[k[0]].push_back(k[1]);
        adj[k[1]].push_back(k[0]);
    }

    int level[n+1];
    queue<pair<int,int>>q;
    q.push({s,0});
    visit[s]=1;

    while(!q.empty()){
        auto it=q.front();
        q.pop();

        int node=it.first;
        int steps=it.second;
        level[node]=steps;
        for(int adj_node:adj[node]){
            if(visit[adj_node]==0){
                visit[adj_node]=1;
                q.push({adj_node,steps+1});
            }
        }
    }
    vector<int>v;
    for(int i=1;i<=n;i++){
        if(visit[i]==0)
            v.push_back(-1);
        else if(i==s) continue;
        else
            v.push_back(level[i]*6);
    }
    return v;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>>edges;
        for(int i=0;i<m;i++){
            int a,b;
            cin>>a>>b;
            vector<int>k;
            k.push_back(a);
            k.push_back(b);
            edges.push_back(k);
        }
        int s;
        cin>>s;

        vector<int>v = bfs(n,m,edges,s);
        for(int x : v)
            cout<<x<<" ";
        cout<<endl;
    }
}
/**

2
4 2
1 2
1 3
1
3 1
2 3
2

*/
