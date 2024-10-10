//#include<bits/stdc++.h>
//using namespace std;
//
//long long dp[21];
//long long fun(int t1 , int t2 , int n){
//    if(n==1) return t1;
//    if(n==2) return t2;
//    if(dp[n]!=-1) return dp[n];
//
//    long long ans1=fun(t1,t2,n-1);
//    long long ans2=fun(t1,t2,n-2);
//    long long ans=ans1*ans1 + ans2;
//    return dp[n]=ans;
//}
//long long fibonacciModified(int t1, int t2, int n) {
//    for(int i=0;i<=n;i++)
//        dp[i]=-1;
//    return fun(t1,t2,n);
//}
//
//int main()
//{
//    int t1,t2,n;
//    cin>>t1>>t2>>n;
//    cout<<fibonacciModified(t1,t2,n)<<endl;
//    return 0;
//}

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
// Memoization array to store the computed values
std::vector<long long> memo;

// Recursive function with memoization
long long fibonacciModified(int t1, int t2, int n) {
    // Base cases
    long long t3=0;
    for(int i=2;i<n;i++){
        t3=t1+t2*t2;
        cout<<t1<<" "<<t2<<" "<<t3<<endl;
        t1=t2;
        t2=t3;
    }
    return t3;
}

int main() {
    int t1, t2, n;

    // Input the initial terms t1, t2 and the term n to calculate
    std::cin >> t1 >> t2 >> n;

    // Resize memoization array to hold the required number of terms and initialize to -1
    memo.resize(n + 1, -1);

    // Compute and output the nth term in the modified Fibonacci sequence
    std::cout << fibonacciModified(t1, t2, n) << std::endl;

    return 0;
}

