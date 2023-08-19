#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<cmath>

using namespace std;

int func(vector<int>&v,int mid)
{   int totalH=0;
    for(int i=0;i<v.size();i++){
        totalH+=ceil((double(v[i])/double(mid)));
    }
    return totalH;
}

int min_hr(vector<int>&v,int hr){
    int low=1;
    int high=*max_element(v.begin(),v.end());
    int ans=INT_MAX;
    while(low<=high){
        int mid=(low+high)/2;
        int totalH=func(v,mid);
        if(totalH<=hr){
            ans=totalH;
            high=mid-1;

        }
        else low=mid+1;
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    int hr;
    cin>>hr;
    vector<int>v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    cout<<min_hr(v,n);
}