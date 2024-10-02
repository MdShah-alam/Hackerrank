#include<bits/stdc++.h>
using namespace std;

int left_arr[1025];
int right_arr[1025];

void swaping(int root , int k)
{
    queue<int>q;
    q.push(root);
    int level=0;

    while(!q.empty()){
        level++;
        int s=q.size();

        while(s--){
            int i=q.front();
            q.pop();
            if(level%k==0)
                swap(left_arr[i],right_arr[i]);

            if(left_arr[i]!=-1)
                q.push(left_arr[i]);
            if(right_arr[i]!=-1)
                q.push(right_arr[i]);
        }
    }
}

void inorder(int root)
{
    if(root==-1) return ;
    inorder(left_arr[root]);
    cout<<root<<" ";
    inorder(right_arr[root]);
}

int main()
{
    int n,a,b,t,k;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>b;
        left_arr[i]=a;
        right_arr[i]=b;
    }

    cin>>t;
    while(t--){
        cin>>k;
        swaping(1,k);
        //print
        inorder(1);
        cout<<endl;
    }

}
