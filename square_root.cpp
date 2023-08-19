#include<iostream>
using namespace std;

int square_root(int n){
    int low=1;
    int high=n;
    while(low<=high){
        int mid=(low+high)/2;
        if((mid*mid)<=n)low=mid+1;
        else high=mid-1;
    }
    return high;
}
int main(){
    int n;
    cin>>n;
    cout<<square_root(n);
}