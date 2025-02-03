#include <iostream>
#include <deque>
using namespace std;

int longestSettlementQueue(int totalTransaction, deque<int>& transactions) {
    deque<int> queue;

    for (int fee : transactions) {
        if (fee == 0) continue; // Ignore fees of 0

        // Maintain strictly decreasing order
        if (queue.empty() || fee < queue.back()) {
            queue.push_back(fee); // Append if it is smaller than the last element
        } else if (fee > queue.front()) {
            queue.push_front(fee); // Prepend if it is greater than the first element
        }
    }
    return queue.size();
}

int main() {
    int days;
    cin >> days;

    while (days--) {
        int totalTransaction;
        cin >> totalTransaction;

        deque<int> transactions;
        for (int i = 0; i < totalTransaction; ++i) {
            int fee;
            cin >> fee;
            transactions.push_back(fee);
        }

        cout << longestSettlementQueue(totalTransaction, transactions) << endl;
    }

    return 0;
}
