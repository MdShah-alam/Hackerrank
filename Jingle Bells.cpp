#include <iostream>
using namespace std;

void printTree(int n)
{
    int m=5;
    for(int i=1;i<=n;i+=2)
        m++;
    int t=10+n;
    t=t/2;
    int k=1;
    for(int i=0;i<m;i++){
        for(int j=0;j<t;j++)
            cout<<" ";
        for(int j=0;j<k;j++)
            cout<<"*";
        cout<<endl;
        k+=2;
        t--;
    }
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++)
            cout<<" ";
        for(int j=0;j<n;j++)
            cout<<"*";
        cout<<endl;
    }
}

int main() {
    int N;
    cin >> N;
    printTree(N);
    return 0;
}

