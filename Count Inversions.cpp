#include <iostream>
#include <vector>
using namespace std;

// Function to merge two halves and count inversions
int mergeAndCount(vector<int>& arr, vector<int>& temp, int left, int mid, int right) {
    int i = left;    // Starting index for left subarray
    int j = mid + 1; // Starting index for right subarray
    int k = left;    // Starting index to be sorted
    int inv_count = 0;

    // Merge the two subarrays and count inversions
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            // If arr[i] > arr[j], it means all elements from arr[i] to arr[mid] are greater than arr[j]
            temp[k++] = arr[j++];
            inv_count += (mid + 1 - i); // Count inversions
        }
    }

    // Copy remaining elements of left subarray if any
    while (i <= mid)
        temp[k++] = arr[i++];

    // Copy remaining elements of right subarray if any
    while (j <= right)
        temp[k++] = arr[j++];

    // Copy the sorted subarray into original array
    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return inv_count;
}

// Function to implement merge sort and count inversions
int mergeSortAndCount(vector<int>& arr, vector<int>& temp, int left, int right) {
    int mid, inv_count = 0;
    if (left < right) {
        mid = (left + right) / 2;

        // Count inversions in the left subarray
        inv_count += mergeSortAndCount(arr, temp, left, mid);

        // Count inversions in the right subarray
        inv_count += mergeSortAndCount(arr, temp, mid + 1, right);

        // Count inversions while merging both halves
        inv_count += mergeAndCount(arr, temp, left, mid, right);
    }
    return inv_count;
}

// Function to count the number of inversions in the array
int countInversions(vector<int>& arr) {
    int n = arr.size();
    vector<int> temp(n);
    return mergeSortAndCount(arr, temp, 0, n - 1);
}

int main() {
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    cout << "Number of inversions: " << countInversions(v) << endl;
    return 0;
}

/**

7
9 4 7 6 3 1 5

*/
