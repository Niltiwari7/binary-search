#include<iostream>
using namespace std;

int lower_bound(int *arr,int n,int x){
    int l=0;
    int hi=n-1;
    while(l<=hi){
        int mid=(l+hi)/2;
        if(arr[mid]<x) l=mid+1;
        else hi=mid-1;
    }
    return l;
}

int main(){
    int n;
    cin>>n;
    int x;
    cin>>x;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    cout<<lower_bound(arr,n,x);
}