#include<iostream>
using namespace std;

int peak_ele(int *arr,int n){
    int ans=0;
    for(int i=0;i<n;i++){
    if((i==0||arr[i-1]<arr[i])&& (i==n-1||arr[i]>arr[i+1])){
        return i;
    }
  }
return -1;
}

int peak_ele(int *arr,int n){
    int low=0;
    int high=n-2;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid-1]<arr[mid]  && arr[mid]>arr[mid+1])
          return mid;
        if(arr[mid]>arr[mid-1])low=mid+1;
        else high=mid-1;
    }
    return -1;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    cout<<peak_ele(arr,n);
}