#include<bits/stdc++.h>
using namespace std;

long strangeCounter(long t) {
    long cycle_start = 3;  // Start with the first cycle value
    long time_in_cycle = 0;

    // Keep doubling the cycle length until we find the cycle where `t` belongs
    while (t > time_in_cycle + cycle_start) {
        time_in_cycle += cycle_start;
        cycle_start *= 2;
        cout<<time_in_cycle<<" "<<cycle_start<<endl;
    }
    cout<<cycle_start - (t - time_in_cycle - 1)<<endl;
    // Calculate the remaining time in the current cycle
    return cycle_start - (t - time_in_cycle - 1);
}

int main() {
    long t;
    std::cin >> t;
    std::cout << strangeCounter(t) << std::endl;
    return 0;
}
