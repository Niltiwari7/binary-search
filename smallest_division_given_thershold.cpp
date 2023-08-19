#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

bool possible(vector<int>&v,int mid,int n, int thresh){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=ceil((double)v[i]/(double)mid);
    }
    return sum<=thresh;
}
int smallest_div(vector<int>&v,int n,int thresh){
    int low=1;
    int high=*max_element(v.begin(),v.end());
    int ans=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(possible(v,mid,n,thresh)){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    int thresh;
    cin>>thresh;
    vector<int>v(n);
    for(auto &i:v)cin>>i;
    cout<<smallest_div(v,n,thresh);
}