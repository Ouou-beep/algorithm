/*输入一组数（假设构成数组a,下标从1开始），对于数a[i],
输出在其之后第一个大于它的数的下标*/
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> nums(n+1,0),ans(n+1,0);//初始数组与答案数组
    stack<int> s;//栈存储下标

    for(int i=1;i<=n;i++) cin>>nums[i];

    for(int i=1;i<=n;i++){
        //当这个数大于栈顶时，说明这个数就是栈顶对应数的第一个大于数
        while(!s.empty()&&nums[i]>nums[s.top()]){
            ans[s.top()]=i;//答案数组存储下标
            s.pop();
        }
        s.push(i);//否则存入栈
    }
    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
    return 0;
}