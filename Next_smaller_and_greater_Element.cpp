#include<bits/stdc++.h>
using namespace std;

vector<int>Next_smaller(vector<int>&v,int n)
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

vector<int>Next_greater(vector<int>&v,int n)
{
    vector<int>v1;
    stack<int>st;
    for(int i=n-1;i>=0;i--){
        if(st.empty()){
            st.push(v[i]);
            v1.push_back(-1);
        }
        else{
            bool found=false;
            while(!st.empty()){
                if(st.top()<v[i]){
                    v1.push_back(st.top());
                    st.push(v[i]);
                    found=true;
                    break;
                }
                else
                    st.pop();
            }
            if(!found){
                st.push(v[i]);
                v1.push_back(-1);
            }
        }
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

    vector<int>smaller=Next_smaller(v,n);
    for(int i=0;i<n;i++)
        cout<<smaller[i]<<" ";
    cout<<endl<<endl;

    vector<int>grater=Next_greater(v,n);
    for(int i=0;i<n;i++)
        cout<<grater[i]<<" ";
    cout<<endl<<endl;

    return 0;
}
