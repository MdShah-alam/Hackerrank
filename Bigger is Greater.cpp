#include<bits/stdc++.h>
using namespace std;

string convertToString(char* a, int size)
{
    int i;
    string s = "";
    for (i = 0; i < size; i++) {
        s = s + a[i];
    }
    return s;
}
string biggerIsGreater(string w)
{
    const int n=w.length();
    char *ar = new char[n+1];
    // copying the contents of the
    // string to char array
    strcpy(ar,w.c_str());

    //1
    bool found=false;
    int pivotIndex=-1;

    for(int i=n;i>0;i--){
        if(ar[i]<=ar[i-1]){
            continue;
        }
        found=true;
        pivotIndex=i-1;

        break;
    }

    if(!found) return "no answer";

    //2
    int rightMostIndex=-1;
    for(int i=n;i>pivotIndex;i--){
        if(ar[i]>ar[pivotIndex]){
            rightMostIndex=i;
            break;
        }
    }

    char c=ar[pivotIndex];
    ar[pivotIndex]=ar[rightMostIndex];
    ar[rightMostIndex]=c;

    //3
    int left=pivotIndex+1,right=n-1;
    while(left<right){
        c=ar[left];
        ar[left]=ar[right];
        ar[left]=c;
        left++;
        right--;
    }
    string s = convertToString(ar, n);
    return s;
}

int main()
{
    int n;
    cin>>n;
    while(n--){
        string s;
        cin>>s;
        cout<<biggerIsGreater(s)<<endl;
    }
    return 0;
}
