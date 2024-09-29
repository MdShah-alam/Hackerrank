#include <bits/stdc++.h>
using namespace std;

int downToZero(int n)
{
    queue<int> q;
    vector<int> dp(n + 1, -1);  // Initialize dp array with -1 (unvisited)
    q.push(n);
    dp[n] = 0;  // Starting point, 0 moves to reduce n to n

    while (!q.empty()) {
        int cn = q.front();
        q.pop();

        // If cn is 0, we reached the goal
        if (cn == 0) {
            return dp[0];  // Return the number of moves to reach 0
        }

        // Option 1: Decrease by 1
        if (cn - 1 >= 0 && dp[cn - 1] == -1) {  // If unvisited
            dp[cn - 1] = dp[cn] + 1;
            q.push(cn - 1);
        }

        // Option 2: Try dividing by any divisor
        for (int i = sqrt(cn); i >= 2; --i) {
            if (cn % i == 0) {
                int div = cn / i;
                if (dp[div] == -1) {  // If unvisited
                    dp[div] = dp[cn] + 1;
                    q.push(div);
                    cout<<i<<" ";
                }
            }
        }
    }
    cout<<endl;
    return dp[0];
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int result=downToZero(n);
        cout<<result<<endl;
    }

    return 0;
}
