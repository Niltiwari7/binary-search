#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;
//brute force approach
int countStudent(vector<int>&arr,int pages)
{
    int student=1;
    int n=arr.size();
    long long pagesStudent=0;
    for(int i=0;i<n;i++)
    {
        if(pagesStudent+arr[i]<=pages)
        {
            pagesStudent+=arr[i];
        }
        else{
            student++;
            pagesStudent=arr[i];
        }
    }
    return student;
}
int find_pages(vector<int>&arr,int n,int m)
{
   if(m>n)return -1;
   int low=*max_element(arr.begin(),arr.end());
   int high=accumulate(arr.begin(),arr.end(),0);
   for(int pages=low;pages<=high;pages++)
   {
    if(countStudent(arr,pages)==m)
    {
        return pages;
    }
   }
   return low;
}

//binary search approach

int  find_pages(vector<int>&arr,int n,int m)
{
    if(m>n)return -1;
    int low=*max_element(arr.begin(),arr.end());
    int high=accumulate(arr.begin(),arr.end(),0);
    while(low<=high){
        int mid=(low+high)/2;
        int student=countStudent(arr,mid)
        if(student>m){
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
    int m;
    cin>>m;
    vector<int>v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    cout<<find_pages( v,n,m);
}