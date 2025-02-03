#include<bits/stdc++.h>
using namespace std;

int quickestWayUp(vector<vector<int>>&ladders, vector<vector<int>>&snakes) {
    vector<int> board(101);
    for (int i = 1; i <= 100; i++) {
        board[i] = i;
    }
    for(vector<int>v:ladders){
        board[v[0]]=v[1];
    }
    for(vector<int>v:snakes){
        board[v[0]]=v[1];
    }

    vector<bool> visited(101, false);
    queue<pair<int, int>> q;
    q.push({1, 0});
    visited[1] = true;

    while (!q.empty()) {
        auto [current, moves] = q.front();
        q.pop();

        if (current == 100) {
            return moves;
        }

        for (int roll = 1; roll <= 6; roll++) {
            int next = current + roll;
            if (next <= 100 && !visited[board[next]]) {
                visited[board[next]] = true;
                q.push({board[next], moves + 1});
            }
        }
    }
    return -1;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int l;
        cin >> l;
        vector<vector<int>>ladders;
        for(int i=0;i<l;i++) {
            int a,b;
            cin>>a>>b;
            ladders.push_back({a,b});
        }

        int s;
        cin >> s;
        vector<vector<int>>snakes;
        for(int i = 0; i < s; i++) {
            int a,b;
            cin>>a>>b;
            snakes.push_back({a,b});
        }

        cout << quickestWayUp(ladders, snakes) << endl;
    }

    return 0;
}

