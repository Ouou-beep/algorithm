/*Black Box 是一种原始的数据库。它可以储存一个整数数组，还有一个特别的变量 i。最开始的时候 Black Box 是空的．而 i=0。这个 Black Box 要处理一串命令。

命令只有两种：

ADD(x)：把 x 元素放进 Black Box;

GET：i 加 1，然后输出 Black Box 中第 i 小的数。数据保证此时的第 i 小的数一定存在。

记住：第 i 小的数，就是 Black Box 里的数的按从小到大的顺序排序后的第 i 个元素。*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//定义Get命令函数
int Get(priority_queue<int,vector<int>,greater<int>>& R,priority_queue<int>& L,int& cnt){
    cnt++;                              //i+1
    while(true){
        if((int)L.size()<cnt){          //保证左侧大根堆的数量
            L.push(R.top());
            R.pop();
        }
        else if((int)L.size()>cnt){     //保证左侧大根堆的数量
            R.push(L.top());
            L.pop();
        }
        else return L.top();
    }
}
int main(){
    priority_queue<int,vector<int>,greater<int>> R;     //右侧小根堆
    priority_queue<int> L;                              //左侧大根堆
    queue<int> q;                                       //存储命令位置
    vector<int> nums;                                   //存储数据

    int m,n,cnt=0;
    cin>>m>>n;                                          //m个数据 n个命令
    for(int i=0;i<m;i++){
        int a;
        cin>>a;
        nums.push_back(a);
    }
    for(int i=0;i<n;i++){
        int b;
        cin>>b;
        q.push(b);
    }
    for(int i=0;i<m;i++){
        int num=nums[i];
        if(L.empty()||num<=L.top()) L.push(num);
        else R.push(num);
        while(i==q.front()-1){
            cout<<Get(R,L,cnt)<<"\n";
            q.pop();
        }
    }
    return 0;
}