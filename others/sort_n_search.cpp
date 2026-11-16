#include<iostream>
#include<vector>
using namespace std;

//快速排序
void quick_sort(vector<int>& nums,int l,int r){
    if(l>=r) return;
    int i=l,j=r,temp=nums[l];
    while(i<j){
        while(i<j&&nums[j]>temp) j--;
        nums[i]=nums[j];
        while(i<j&&nums[i]<temp) i++;
        nums[j]=nums[i];
    }
    nums[i]=temp;

    quick_sort(nums,l,i-1);
    quick_sort(nums,i+1,r);
}

//二分查找
int binary_search(const vector<int>& nums,int target){
    int l=0,r=nums.size()-1;
    while(l<=r){
        int mid=l+((r-l)>>1);
        if(nums[mid]==target) return mid;
        else if(nums[mid]<target) l=mid+1;
        else if(nums[mid]>target) r=mid-1;
    }
    return -1;
}

int main(){
    int n;                              //数组长度
    cin>>n;
    vector<int> nums(n,0);
    for(int i=0;i<n;i++) cin>>nums[i];
    quick_sort(nums,0,nums.size()-1);   //排序

    int target,pos;
    cin>>target;
    pos=binary_search(nums,target);
    if(pos==-1) cout<<"Not find!"<<"\n";
    else cout<<"The position of "<<target<<" is "<<pos+1<<"\n";
    return 0;
}