#include<iostream>
using namespace std;

int single_ele(int *arr,int n){
    int ans=0;
    for(int i=0;i<n;i++){
        ans^=arr[i];
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    cout<<single_ele(arr,n);
}