/*题目描述
有两个长度为 N 的单调不降序列 A,B，在 A,B 中各取一个数相加可以得到 N 
  个和，求这 N 个和中最小的 N 个。

输入格式
第一行一个正整数 N；
第二行 N 个整数
第三行 N 个整数

输出格式
一行 N 个整数，从小到大表示这 N 个最小的和。*/
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main(){
    int N;
    cin>>N;
    vector<int> A(N,0),B(N,0);
    for(int i=0;i<N;i++) cin>>A[i];
    for(int i=0;i<N;i++) cin>>B[i];

    priority_queue<tuple<long long,int,int>,
                   vector<tuple<long long,int,int>>,
                   greater<tuple<long long,int,int>>> pq;

    for(int i=0;i<N;i++) pq.push({A[i]+B[0],i,0});

    vector<long long> ans(N,0);

    for(int cnt=0;cnt<N;cnt++){
        auto [sum,i,j]=pq.top();pq.pop();
        ans[cnt]=sum;
        if(j<N-1){
            pq.push({A[i]+B[j+1],i,j+1});
        }
    }
    for(int i=0;i<N;i++) cout<<ans[i]<<" \n"[i==N-1];   //" /n"字符串
    return 0;
}