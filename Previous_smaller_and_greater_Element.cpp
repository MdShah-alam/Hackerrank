#include<bits/stdc++.h>
using namespace std;

vector<int>Previous_smaller(vector<int>&v,int n)
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

vector<int>Previous_greater(vector<int>&v,int n)
{
    vector<int>v1;
    stack<int>st;
    for(int i=0;i<n;i++){
        while(!st.empty() && v[st.top()]<=v[i]){
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

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];

    vector<int>smaller=Previous_smaller(v,n);
    vector<int>greater_=Previous_greater(v,n);

    for(int i=0;i<n;i++)
        cout<<smaller[i]<<" ";
    cout<<endl<<endl;

    for(int i=0;i<n;i++)
        cout<<greater_[i]<<" ";
    cout<<endl<<endl;

    return 0;
}
