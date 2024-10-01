#include<bits/stdc++.h>
using namespace std;

vector<int>pre_smaller(vector<int>v,int n)
{
    vector<int>v1;
    stack<int>st;
    for(int i=0;i<n;i++){
        while(!st.empty() && v[st.top()]>=v[i]){
            st.pop();
        }
        if(st.empty()){
            v1.push_back(-1);
        }
        else
            v1.push_back(st.top());
        st.push(i);
    }
    return v1;
}
vector<int>next_smaller(vector<int>&v,int n)
{
    vector<int>v1;
    stack<int>st;
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && v[st.top()]>=v[i]){
            st.pop();
        }
        if(st.empty()){
            v1.push_back(n);
        }
        else
            v1.push_back(st.top());
        st.push(i);
    }
    reverse(v1.begin(),v1.end());
    return v1;
}
long largestRectangle(vector<int>& h)
{
    int n=h.size();
    vector<int>ps=pre_smaller(h,n);
    vector<int>ns=next_smaller(h,n);
    long max_area=0;
    for(int i=0;i<n;i++){
        long area=(ns[i]-ps[i]-1)*h[i];
        max_area=max(max_area,area);
    }
    return max_area;
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);

    for(int i=0;i<n;i++)
        cin>>v[i];

    cout<<largestRectangle(v)<<endl;
}

