#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int search(vector<int>&v,int n,int k)
{
    for(int i=0;i<n;i++)
    {
        if(v[i]<=k)k++;
        else break;
    }
    return k;
}
//optimal
int search(vector<int>&v,int n,int k)
{
    int ans=-1;
    int low=1;
    int high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        int missing=v[mid]-(mid+1);
        if(missing<k)
        {
           low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    return k+high+1;
}
int main(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int>v(n);
    for(auto &i:v)cin>>i;
    cout<<search(v,n,k);


}