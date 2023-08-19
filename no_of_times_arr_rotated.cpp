#include<iostream>
#include<climits>
using namespace std;

int cnt_rot(int *arr,int n){
    int low=0;
    int high=n-1;
    int index=-1;
    int ans=INT_MAX;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[low]<=arr[high]){
            if(arr[low]<ans){
                index=low;
                ans=arr[low];
            }
            break;
        }
        if(arr[low]<=arr[mid]){
            if(arr[low]<ans){
                index=low;
                ans=arr[low];
            }
            low=mid+1;
        }
        else{
            if(arr[mid]<ans){
                index=mid;
                ans=arr[mid];
            }
            high=mid-1;
        }
    }
    return index;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<cnt_rot(arr,n);
}