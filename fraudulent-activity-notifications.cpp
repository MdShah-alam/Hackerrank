#include<bits/stdc++.h>
using namespace std;

// Helper function to find the median in a sorted frequency array
double findMedian(const vector<int>& freq, int d) {
    int count = 0;
    int median1 = 0, median2 = 0;

    if (d % 2 == 1) {
        // If d is odd, we need to find the middle element
        int medianPosition = d / 2 + 1;
        for (int i = 0; i < 201; i++) {
            count += freq[i];
            if (count >= medianPosition) {
                return i;
            }
        }
    } else {
        // If d is even, we need to find the average of the two middle elements
        int medianPosition1 = d / 2, medianPosition2 = d / 2 + 1;
        for (int i = 0; i < 201; i++) {
            count += freq[i];
            if (count >= medianPosition1 && median1 == 0) {
                median1 = i;
            }
            if (count >= medianPosition2) {
                median2 = i;
                return (median1 + median2) / 2.0;
            }
        }
    }
    return 0;
}

int activityNotifications(vector<int>& expenditure, int d) {
    vector<int> freq(201, 0); // To keep track of expenditure frequency (0-200)
    int notifications = 0;

    // Initialize frequency array with the first d days
    for (int i = 0; i < d; i++) {
        freq[expenditure[i]]++;
    }

    for (int i = d; i < expenditure.size(); i++) {
        // Find the median from the last d days using the frequency array
        double median = findMedian(freq, d);

        // If the current day's expenditure is at least 2 times the median, send a notification
        if (expenditure[i] >= 2 * median) {
            notifications++;
        }

        // Update the frequency array for the sliding window
        freq[expenditure[i]]++;                // Add current day's expenditure
        freq[expenditure[i - d]]--;            // Remove the day that slides out of the window
    }

    return notifications;
}

int main()
{
    int n,d;
    cin>>n>>d;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    cout<<activityNotifications(v,d)<<endl;
    return 0;
}
/**

5 4
1 2 3 4 4

9 5
2 3 4 2 3 6 8 4 5

*/
