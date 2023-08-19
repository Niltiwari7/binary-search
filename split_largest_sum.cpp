#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>

using namespace std;

//brute force
int countPartition(vector<int>&arr,int maxsum){
    int n=arr.size();
    int partition=1;
    long long subarraySum=0;
    for(int i=0;i<n;i++){
        if(subarraySum+arr[i]<=maxsum){
            subarraySum+=arr[i];
        }
        else{
            partition++;
            subarraySum=arr[i];
        }
    }
    return partition;
}
int split_largest_sum(vector<int>&arr,int n,int k)
{
    int low=*max_element(arr.begin(),arr.end());
    int high=accumulate(arr.begin(),arr.end(),0);
    for(int i=low;i<=high;i++)
    {
        if(countPartition(arr,i)==k)
        {
            return i;
        }
        
    }
    return low;
}

//optimal solution
int split_largest_sum(vector<int>&arr,int n,int k){
    int low=*max_element(arr.begin(),arr.end());
    int high=accumulate(arr.begin(),arr.end(),0);
    while(low<=high){
        int mid=(low+high)/2;
        int partition= countPartition(arr,mid);
        if(partition>k){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return low;
}
int main(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<split_largest_sum(arr,n,k);
}