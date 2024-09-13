#include<bits/stdc++.h>
using namespace std;

int hackerlandRadioTransmitters(vector<int> x, int k) {
    // Sort the house locations to handle them in order
    sort(x.begin(), x.end());
    int n = x.size();  // Number of houses
    int transmitters = 0;
    int i = 0;

    while (i < n) {
        // Step 1: Place the transmitter as far as possible within range
        int location = x[i] + k;
        while (i < n && x[i] <= location) {
            i++;
        }
        // Step 2: Place the transmitter at the furthest house within range
        transmitters++;
        location = x[i - 1] + k;

        // Step 3: Skip all houses that are covered by this transmitter
        while (i < n && x[i] <= location) {
            i++;
        }
    }
    return transmitters;
}

int main()
{
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int>v(n);

    for(int i=0;i<n;i++)
        cin>>v[i];

    cout<<hackerlandRadioTransmitters(v,k);
    return 0;
}
