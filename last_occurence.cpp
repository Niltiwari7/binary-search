#include<iostream>
using namespace std;

int last_occurence(int *arr,int n,int x){
    int start=0;
    int end=n-1;
    int res=-1;
    while(start<=end){
        int mid=(start+end)/2;
        if(arr[mid]==x){
            res=mid;
            //look for larger index
            start=mid+1;
        }
        else if(x<arr[mid]){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    return res;
}

int first_index(int *arr,int n,int x){
    int start=0;
    int end=n-1;
    int res=-1;
    while(start<=end){
        int mid=(start+end)/2;
        if(arr[mid]==x){
            res=mid;
            //look for smaller index
            high=mid-1;
        }
        else if(arr[mid]<x){
            start=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return res;
}
int main(){
    int n;
    cin>>n;
    int x;
    cin>>x;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    cout<<last_occurence(arr,n,x);
}