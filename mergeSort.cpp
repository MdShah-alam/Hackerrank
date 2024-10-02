#include<bits/stdc++.h>
using namespace std;

int temp[100000];
void Merge(int v[],int l , int mid , int r)
{
    int i=l , j=mid+1,k=l;
    while(i<=mid && j<=r){
        if(v[i]<v[j]){
            temp[k]=v[i];
            i++;
        }
        else{
            temp[k]=v[j];
            j++;
        }
        k++;
    }
    if(i>mid){
        while(j<=r){
            temp[k]=v[j];
            k++;
            j++;
        }
    }
    else{
        while(i<=mid){
            temp[k]=v[i];
            i++;
            k++;
        }
    }
    for(k=l;k<=r;k++)
        v[k]=temp[k];
}
void mergeSort(int v[],int l,int r)
{
    if(l<r){
        int mid = (l+r)/2;
        mergeSort(v,l,mid);
        mergeSort(v,mid+1,r);
        Merge(v,l,mid , r);
    }
}

int main()
{
    int n;
    cin>>n;
    int v[n];
    for(int i=0;i<n;i++)
        cin>>v[i];
    mergeSort(v,0,n-1);
    for(int i=0;i<n;i++)
        cout<<v[i]<<" ";
    cout<<endl;
    return 0;
}
