#include<iostream>
using namespace std;

int floor(int *arr,int n,int x){
    int l=0;
    int hi=n-1;
    int ans=0;
    while(l<hi){
        int mid=(l+hi)/2;
        if(arr[l]<x)
        {
            ans=arr[mid];
            l=mid+1;
        }
        else hi=mid-1;
    }
    return ans;
}

int ceil(int *arr,int n,int x){
    int l=0;
    int hi=n-1;
    int ans=0;
    while(l<=hi){
        int mid=(l+hi)/2;
        if(arr[mid]>=x)
         {
            ans=arr[mid];
            hi=mid-1;
         }
        else l=mid+1;
    }
    return ans;

}
int main(){
    int n;
    cin>>n;
    int x;
    cin>>x;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    cout<<floor(arr,n,x)<<endl;
    cout<<ceil(arr,n,x)<<endl;
}