#include<bits/stdc++.h>
using namespace std;

int equalStacks(vector<int> h1, vector<int> h2, vector<int> h3)
{
    stack<int>st1,st2,st3;
    reverse(h1.begin(),h1.end());
    reverse(h2.begin(),h2.end());
    reverse(h3.begin(),h3.end());

    st1.push(h1[0]);
    st2.push(h2[0]);
    st3.push(h3[0]);

    for(int i=1;i<h1.size();i++)
        h1[i]=h1[i-1]+h1[i];
    for(int i=1;i<h2.size();i++)
        h2[i]=h2[i-1]+h2[i];
    for(int i=1;i<h3.size();i++)
        h3[i]=h3[i-1]+h3[i];

    for(int i=1;i<h1.size();i++)
        st1.push(h1[i]);
    for(int i=1;i<h2.size();i++)
        st2.push(h2[i]);
    for(int i=1;i<h3.size();i++)
        st3.push(h3[i]);

    int maxheigth=0;

    while(!st1.empty() && !st2.empty() && !st3.empty()){
        int sh1=st1.top();
        int sh2=st2.top();
        int sh3=st3.top();

        if(sh1==sh2 && sh1==sh3)
            return maxheigth=sh1;

        if(sh1>=sh2 && sh1>=sh3)
            st1.pop();

        else if(sh2>=sh1 && sh2>=sh3)
            st2.pop();

        else
            st3.pop();
    }
    return maxheigth;
}

int main()
{
    int n1,n2,n3;
    cin>>n1>>n2>>n3;
    vector<int>v1(n1),v2(n2),v3(n3);
    for(int i=0;i<n1;i++)
        cin>>v1[i];
    for(int i=0;i<n2;i++)
        cin>>v2[i];
    for(int i=0;i<n3;i++)
        cin>>v3[i];

    cout<<equalStacks(v1,v2,v3)<<endl;
    return 0;
}
/**

5 3 4
3 2 1 1 1
4 3 2
1 1 4 1

*/
