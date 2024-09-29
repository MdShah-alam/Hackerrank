#include<bits/stdc++.h>
using namespace std;

void kaprekarNumbers(int p,int q)
{
    vector<int>v;

    for(int n=p; n<=q;n++){
        int square = n * n;
        int digits = (int)log10(square) + 1; // Calculate the number of digits in the square

        int leftPart = square / pow(10, digits / 2);
        int rightPart = square % (int)pow(10, digits / 2);

        if(leftPart+rightPart==n)
            v.push_back(n);
    }

    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
    if(v.empty())
        cout<<"INVALID RANGE.";
}

int main()
{
    int p,q;
    cin>>p>>q;
    kaprekarNumbers(p,q);
    return 0;
}
