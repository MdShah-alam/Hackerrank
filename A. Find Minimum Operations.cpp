#include <iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int ans=0;
        if(k==1)
            cout<<n<<endl;
        else if(n<k)
            cout<<n<<endl;
        else{
            while(n){
                ans+=n%k;
                n=n/k;
            }
            cout<<ans<<endl;
        }
    }
}
