#include<bits/stdc++.h>
using namespace std;

int ladderLength(string start,string endword,vector<string>&wordlist)
{
    queue<pair<string,int>>q;
    q.push({start,1});
    unordered_set<string>st(wordlist.begin(),wordlist.end());
    st.erase(start);
    while(!q.empty()){
        auto it = q.front();
        string word=it.first;
        int steps=it.second;
        q.pop();
        if(word==endword) return steps;
        for(int i=0;i<word.size();i++){
            char original=word[i];
            for(char ch='a';ch<='z';ch++){
                word[i]=ch;
                if(st.find(word)!=st.end()){
                    st.erase(word);
                    q.push({word,steps+1});
                }
            }
            word[i]=original;
        }
    }
    return 0;
}

int main()
{
    string s,e;
    cin>>s>>e;
    int n;
    cin>>n;
    vector<string>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];

    cout<<ladderLength(s,e,v)<<endl;
    return 0;
}
/**

cat sag
5
bat bag sag dag dot

cat sag
5
bat bag sat dag dot

*/
