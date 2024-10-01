#include<bits/stdc++.h>
using namespace std;

multiset<int>max1,min1;
void print()
{
    if(max1.size()>min1.size()+1){
        min1.insert(*max1.rbegin());
        max1.erase(max1.find(*max1.rbegin()));
    }
    else if(min1.size()>max1.size()+1){
        max1.insert(*min1.begin());
        min1.erase(min1.begin());
    }
    if(max1.empty() && min1.empty())
        cout<<"Wrong!"<<endl;
    else if(min1.size()>max1.size()){
        cout<<*min1.begin()<<endl;
    }
    else if(max1.size()>min1.size()){
        cout<<*max1.rbegin()<<endl;
    }
    else{
        int a=*max1.rbegin();
        int b=*min1.begin();
        double p;
        p = (a*1.0+b*1.0)/2.0;
        string s=to_string(p);

        size_t found = s.find('.');
        if(s[found+1]=='5')
            s.erase(s.begin()+found+2,s.end());
        else s.erase(s.begin()+found,s.end());
        cout<<s<<endl;
    }
}
void median(vector<char>&s,vector<int>&x , int n)
{
    for(int i=0;i<n;i++){
        if(s[i]=='a'){
            if(max1.empty() || *max1.rbegin()>x[i])
                max1.insert(x[i]);
            else
                min1.insert(x[i]);
            if(max1.size()>min1.size()+1){
                min1.insert(*max1.rbegin());
                max1.erase(max1.find(*max1.rbegin()));
            }
            else if(min1.size()>max1.size()+1){
                max1.insert(*min1.begin());
                min1.erase(min1.begin());
            }
            print();
        }
        else{
            multiset<int>::iterator t1=max1.find(x[i]) , t2=min1.find(x[i]);
            if(t1==max1.end() && t2==min1.end())
                cout<<"Wrong!"<<endl;
            else{
                if(t1!=max1.end())
                    max1.erase(t1);
                else
                    min1.erase(t2);
                print();
            }
        }
    }
}

int main()
{
    int t;
    cin>>t;
    vector<int>x(t);
    vector<char>s(t);

    for(int i=0;i<t;i++)
        cin>>s[i]>>x[i];

    median(s,x,t);

    return 0;
}
