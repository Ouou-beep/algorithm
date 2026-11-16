#include<iostream>
#include<vector>
using namespace std;
vector<int> tt(10001);

//归并排序
void merge_sort(vector<int>& nums,int l,int r){
    if(r-l<=1) return;
    int mid=l+((r-l)>>1);
    merge_sort(nums,l,mid);
    merge_sort(nums,mid,r);

    int p=l,q=mid,s=l;
    while(p<mid||q<r){
        if(p>=mid||(q<r&&nums[p]>nums[q]))  //p>=mid时，说明现在左侧选完，右侧可直接放进数组tt
            tt[s++]=nums[q++];
        else                                //q>=r或nums[p]<=nums[q]时，将nums[p]放入数组tt
            tt[s++]=nums[p++];
    }

    for(int i=l;i<r;i++) nums[i]=tt[i];
}

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];
    merge_sort(nums,0,n);
    for(int i=0;i<n;i++) cout<<nums[i]<<" \n"[i==n-1];
    return 0;
}