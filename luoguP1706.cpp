/*按照字典序输出自然数 1 到 n 所有不重复的排列，
即 n 的全排列，要求所产生的任一数字序列中不允许
出现重复的数字。*/
#include<iostream>
#include<queue>
#include<vector>
#include<iomanip>
using namespace std;

//递归将全排列写入queue中
void all_pl(vector<int> nums, queue<int> q){
    //输出
    if(nums.empty()){
        queue<int> tmp=q;
        while(!tmp.empty()){ cout<<setw(5)<<tmp.front(); tmp.pop(); }
        cout<<endl;
        return;
    }

    //递归部分
    for(auto it=nums.begin(); it!=nums.end(); ++it){
        //vector与queue都需拷贝后使用，不能改动原数据，
        //因为需要参加下一轮循环
        vector<int> t=nums;
        queue<int> q2=q;
        q2.push(*it);
        t.erase(find(t.begin(),t.end(),*it));
        all_pl(t,q2);
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> nums(n,0);
    queue<int> q;
    for(int i=1;i<=n;i++) nums[i-1]=i;
    all_pl(nums,q);
    return 0;
}