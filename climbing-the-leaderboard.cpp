#include<bits/stdc++.h>
using namespace std;

// Function to calculate the player's rank after each score
vector<int> climbingLeaderboard(vector<int> ranked, vector<int> player) {

    set<int>st;
    for(int x:ranked)
        st.insert(x);
    vector<int>vc(st.begin(), st.end());

    int n=vc.size();
    vector<int>v;
    int i=0;

    for(int x : player){
        while(i<n && vc[i]<=x){
            i=i+1;
        }
        v.push_back(n-i+1);
    }
    return v;
}

int main() {
    int n, m;
    // Input the leaderboard scores
    cin >> n;
    vector<int> ranked(n);
    for (int i = 0; i < n; i++) {
        cin >> ranked[i];
    }

    // Input the player's scores
    cin >> m;
    vector<int> player(m);
    for (int i = 0; i < m; i++) {
        cin >> player[i];
    }

    // Get the player's rank after each game
    vector<int> result = climbingLeaderboard(ranked, player);

    // Output the result
    for (int rank : result) {
        cout << rank << endl;
    }

    return 0;
}
