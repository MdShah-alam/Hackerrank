#include<bits/stdc++.h>
using namespace std;

vector<int> bsolutePermutation(int n, int k)
{
    vector<int>v;
    for(int i=1;i<=n;i++){
        int a=i+k;
        if(a<=n && a>0){
            int cnt = count(v.begin(), v.end(), a);
            if(cnt==0)
                v.push_back(a);
            cnt = count(v.begin(), v.end(), i);
            if(cnt==0)
                v.push_back(i);
        }
    }
    return v;
}

vector<int> absolutePermutation(int n, int k) {
    // If k == 0, the permutation is simply 1 to n
    if (k == 0) {
        vector<int> perm(n);
        for (int i = 1; i <= n; i++) {
            perm[i-1] = i;
        }
        return perm;
    }

    // If n is not divisible by 2*k, it's impossible to form the permutation
    if (n % (2 * k) != 0) {
        return {-1};
    }

    vector<int> perm(n);
    for (int i = 1; i <= n; i++) {
        // Toggle between adding k and subtracting k for blocks of size k
        if ((i-1) / k % 2 == 0) {
            perm[i-1] = i + k;
        } else {
            perm[i-1] = i - k;
        }
    }

    return perm;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int>v=absolutePermutation(n,k);
        for(int i=0;i<v.size();i++)
            cout<<v[i]<<" ";
        cout<<endl;
    }
    return 0;
}
