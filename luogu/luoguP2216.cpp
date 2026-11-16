/*有一个 a×b 的整数组成的矩阵，
现请你从中找出一个 n×n 的正方形
区域，使得该区域所有数中的最大值
和最小值的差最小。*/

#include<iostream>
#include<vector>
#include<deque>
using namespace std;

vector<vector<int>> Max2D(const vector<vector<int>>& nums,int a,int b,int k){
    vector<vector<int>> max_rows(a,vector<int> (b-k+1,0)),
                        max_nums(a-k+1,vector<int> (b-k+1,0));

    //移动窗口求行最大值
    for(int i=0;i<a;i++){
        deque<int> dq;
        for(int j=0;j<b;j++){
            while(!dq.empty()&&nums[i][dq.back()]<=nums[i][j]) dq.pop_back();
            dq.push_back(j);
            if(dq.front()<=j-k) dq.pop_front();
            if(j>=k-1) max_rows[i][j-k+1]=nums[i][dq.front()];
        }
    }

    //移动窗口求列最大值
    for(int j=0;j<b-k+1;j++){
        deque<int> dq;
        for(int i=0;i<a;i++){
            while(!dq.empty()&&max_rows[dq.back()][j]<=max_rows[i][j]) dq.pop_back();
            dq.push_back(i);
            if(dq.front()<=i-k) dq.pop_front();
            if(i>=k-1) max_nums[i-k+1][j]=max_rows[dq.front()][j];
        }
    }
    return max_nums;
}

vector<vector<int>> Min2D(const vector<vector<int>>& nums,int a,int b,int k){
    vector<vector<int>> min_rows(a,vector<int> (b-k+1,0)),
                        min_nums(a-k+1,vector<int> (b-k+1,0));
    
    //移动窗口求行最小值
    for(int i=0;i<a;i++){
        deque<int> dq;
        for(int j=0;j<b;j++){
            while(!dq.empty()&&nums[i][dq.back()]>=nums[i][j]) dq.pop_back();
            dq.push_back(j);
            if(dq.front()<=j-k) dq.pop_front();
            if(j>=k-1) min_rows[i][j-k+1]=nums[i][dq.front()];
        }
    }

    //移动窗口求列最小值
    for(int j=0;j<b-k+1;j++){
        deque<int> dq;
        for(int i=0;i<a;i++){
            while(!dq.empty()&&min_rows[dq.back()][j]>=min_rows[i][j]) dq.pop_back();
            dq.push_back(i);
            if(dq.front()<=i-k) dq.pop_front();
            if(i>=k-1) min_nums[i-k+1][j]=min_rows[dq.front()][j];
        }
    }
    return min_nums;
}

int main(){
    int a,b,n,min=1e9;
    cin>>a>>b>>n;
    vector<vector<int>> nums(a,vector<int> (b,0)),
                        max_nums(a-n+1,vector<int> (b-n+1,0)),
                        min_nums(a-n+1,vector<int> (b-n+1,0));
    for(int i=0;i<a;i++) for(int j=0;j<b;j++) cin>>nums[i][j];

    max_nums=Max2D(nums,a,b,n);
    min_nums=Min2D(nums,a,b,n);

    //求最大最小值差值的最小值
    for(int i=0;i<a-n+1;i++){
        for(int j=0;j<b-n+1;j++){
            if(max_nums[i][j]-min_nums[i][j]<min)
                min=max_nums[i][j]-min_nums[i][j];
        }
    }

    cout<<min;
    return 0;
}