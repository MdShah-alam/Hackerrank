#include<bits/stdc++.h>
using namespace std;

int pairs(int k, vector<int> arr) {
    unordered_set<int> elements;
    int cont = 0;

    // Insert all elements into the set
    for (int i = 0; i < arr.size(); i++) {
        elements.insert(arr[i]);
    }

    // Check for each element if the pair exists
    for (int i = 0; i < arr.size(); i++) {
        if (elements.find(arr[i] + k) != elements.end()) {
            cont++;
        }
    }
    return cont;
}

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];

    cout<<pairs(k,v)<<endl;
    return 0;
}


