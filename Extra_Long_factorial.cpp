#include <iostream>
#include <vector>
using namespace std;

void multiply(vector<int>&v, int x) {
    int c=0;
    for(int i=0;i<v.size();i++){
        int prod=v[i]*x+c;
        v[i]=prod%10;
        c=prod/10;
    }

    while(c){
        v.push_back(c%10);
        c=c/10;
    }
}

void extraLongFactorials(int n) {
    vector<int>v(1,1);

    for(int i=2;i<=n;i++)
        multiply(v,i);

    for(int i=v.size()-1;i>=0;i--)
        cout<<v[i];
    cout<<endl;
}

int main() {
    int n;
    cin >> n;
    extraLongFactorials(n);
    return 0;
}

