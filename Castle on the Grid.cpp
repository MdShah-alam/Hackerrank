#include<bits/stdc++.h>
using namespace std;

int minimumMoves(vector<string> grid, int startX, int startY, int goalX, int goalY)
{
    int c=0;
    set<int>visit;
    queue<vector<int>>q;
    vector<int>v;
    v.push_back(startX);
    v.push_back(startY);
    v.push_back(c);
    q.push(v);
    return 1;
}

int main()
{
    int t;
    cin>>t;
    vector<string>grid;
    while(t--){
        string s;
        cin>>s;
        grid.push_back(s);
    }
    int stX,stY,glX,glY;
    cin>>stX>>stY>>glX>>glY;

    cout<<minimumMoves(grid , stX,stY,glX,glY)<<endl;
    return 0;
}
/**

3
...
.X.
...
0 0 0 2

*/
