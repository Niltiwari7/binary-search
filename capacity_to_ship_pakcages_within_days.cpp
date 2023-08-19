#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<climits>
#include<queue>
#include<unordered_map>
#include<numeric>

using namespace std;

int give_days(vector<int>&v,int cap){
    int days=1;
    int load=0;
    for(int i=0;i<v.size();i++){
        if(load+v[i]>cap){
            days+=1;
            load=v[i];
        }
        else{
            load+=v[i];
        }
    }
    return days;
}

int mini_capacity(vector<int>&v,int n,int days){
    int low=*max_element(v.begin(),v.end());
    int high=accumulate(v.begin(),v.end(),0);
    while(low<=high){
          int mid=(low+high)/2;
         int numOfDays=give_days(v,mid);
         if(numOfDays<=days){
            high=mid-1;
         }
         else{
            low=mid+1;
         }
    }
    return low;
}
int main(){
    int n;
    cin>>n;
    int days;
    cin>>days;
    vector<int>v(n);
    for(auto &i:v)cin>>i;
    cout<<mini_capacity(v,n,days);
}