#include<bits/stdc++.h>
using namespace std;


vector<int>prime(int q)
{
    int num=2;
    vector<int>pr;
    while(pr.size()<q){
        bool is_prime=true;
        for(int i=2;i*i<=num;i++){
            if(num%i == 0){
                is_prime=false;
                break;
            }
        }
        if(is_prime)
            pr.push_back(num);
        num++;
    }

    return pr;
}

vector<int>waiter(vector<int> number, int q) {
    stack<int>a,b;
    vector<int>v;
    for(int i=number.size()-1; i>=0 ;i--){
        if(number[i]%2==0)
            b.push(number[i]);
        else
            a.push(number[i]);
    }
    vector<int>pr = prime(q);
    for(int i=1;i<pr.size();i++){
        stack<int>c;
        while (!b.empty()) {
            v.push_back(b.top());
            b.pop();
        }
        while (!a.empty()) {
            if(a.top()%pr[i]==0)
                b.push(a.top());
            else
                c.push(a.top());
            a.pop();
        }
        a=c;
    }
    while(!b.empty()){
        v.push_back(b.top());
        b.pop();
    }

    while(!a.empty()){
        v.push_back(a.top());
        a.pop();
    }
    return v;
}

int main()
{
    int n,q;
    cin>>n>>q;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];

    vector<int>v1=waiter(v,q);
    for(int i=0;i<v1.size();i++)
        cout<<v1[i]<<" ";
    cout<<endl;
    return 0;
}


