#include<bits/stdc++.h>
using namespace std;

vector<int> findClosestElements(vector<int>& arr, int k, int x)
{
    int l = 0, r = arr.size() - k;
    while (l < r)
    {
        int m = (l + r) / 2;
        if (x - arr[m] > arr[m + k] - x)
        {
            l = m + 1;
        }
        else
        {
            r = m;
        }
    }
    return vector<int>(arr.begin() + l, arr.begin() + l + k);
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0; i<n; i++)
    {
        cin>>v[i];
    }
    int k,x;
    cin>>k>>x;
    vector<int>ans=findClosestElements(v,k,x);
    for(int i=0; i<n; i++)
        cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}
