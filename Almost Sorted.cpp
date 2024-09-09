#include<bits/stdc++.h>
using namespace std;

void almostSorted(vector<int>v)
{
    int n=v.size();
    int l=0, r=n-1;
    vector<int>v1=v;
    sort(v1.begin(),v1.end());
    if(v1==v){
        cout<<"yes"<<endl;
        return ;
    }
    while(l<n && v[l]==v1[l]) l++;
    while(r>0 && v[r]==v1[r]) r--;

    swap(v[l],v[r]);
    if(v==v1){
        cout<<"yes"<<endl;
        cout<<"swap "<<l+1<<" "<<r+1<<endl;
        return ;
    }

    swap(v[l],v[r]);
    reverse(v.begin()+l,v.begin()+(r+1));
    if(v1==v){
        cout<<"yes"<<endl;
        cout<<"reverse "<<l+1<<" "<<r+1<<endl;
        return ;
    }
    cout<<"no"<<endl;
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    almostSorted(v);
    return 0;
}
/**

2
4 2

6
1 5 4 3 2 6

*/
