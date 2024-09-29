#include<bits/stdc++.h>
using namespace std;

int twoStacks(int maxSum, vector<int> a, vector<int> b) {
    int i = 0 ,j = 0 ,s = 0;
    while (i <a.size() && s + a[i] <= maxSum){
        s += a[i];
        i += 1;
    }

    int n = i , maxn = i;
    i -= 1;

    while(j < b.size()){
        if(s + b[j] <= maxSum){
            s += b[j];
            j += 1;
            n += 1;
            maxn = max(maxn, n);
        }
        else if(i >= 0){
            s -= a[i];
            i -= 1;
            n -= 1;
        }
        else
            break;
    }
    return maxn;
}

int main()
{
    int g;
    cin>>g;
    vector<int>v;
    while(g--){
        int n,m,maxSum;
    cin>>n>>m>>maxSum;
    vector<int>a(n),b(m);
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int j=0;j<m;j++)
        cin>>b[j];
    v.push_back(twoStacks(maxSum,a,b));
    }
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
    cout<<endl;
    return 0;
}
