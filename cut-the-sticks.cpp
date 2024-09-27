#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];

    vector<int>v1;
    int mx=*max_element(v.begin(),v.end());
    while(mx>0){
        int cont=0;
        int mn=mx;
        for(int i=0;i<n;i++){
            if(v[i]>0)
                mn=min(mn,v[i]);
        }
        for(int i=0;i<n;i++){
            if(v[i]>0){
                cont++;
                v[i]-=mn;
            }
        }
        v1.push_back(cont);
        mx=*max_element(v.begin(),v.end());
    }
    cout<<v1<<endl;
    return 0;
}


//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//    int N;
//    cin >> N;
//    vector <int> height(N);
//
//    for(int i = 0; i < N; ++i) {
//        cin >> height[i];
//    }
//
//    int mx = *max_element(height.begin(), height.end());
//    while(mx > 0) {
//        int mn = mx;
//        int cuts = 0;
//
//        for(int i = 0; i < (int)N; ++i) {
//            if(height[i] > 0)
//                mn = min(mn, height[i]);
//        }
//        for(int i = 0; i < (int)N; ++i) {
//            if(height[i] > 0) {
//                cuts++;
//                height[i] -= mn;
//            }
//        }
//
//        cout << cuts << "\n";
//        mx = *max_element(height.begin(), height.end());
//    }
//
//    return 0;
//}
