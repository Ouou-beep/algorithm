/*一个学校里老师要将班上 N 个同学排成一列，同学被编号为 1∼N，他采取如下的方法：

先将 1 号同学安排进队列，这时队列中只有他一个人；

2∼N 号同学依次入列，编号为 i 的同学入列方式为：老师指定编号为 i 的同学站在编号为 1∼(i−1) 中某位同学（即之前已经入列的同学）的左边或右边；

从队列中去掉 M 个同学，其他同学位置顺序不变。

在所有同学按照上述方法队列排列完毕后，老师想知道从左到右所有同学的编号。*/
#include <vector>
#include<iostream>

using namespace std;

int main(){
    int N;
    cin>>N;
    vector<int> L(N+1,0),R(N+1,0),gone(N+1,0);//L表示i左边数，R表示i右边数
    int head=1;

    for(int i=2;i<=N;i++){
        int k,p;
        cin>>k>>p;
        if(p==0){
            int l=L[k];
            L[i]=l;L[k]=i;
            if(l) R[l]=i;else head=i;
            R[i]=k;
        }
        else{
            int r=R[k];
            R[i]=r;R[k]=i;
            if(r) L[r]=i;
            L[i]=k;
        }
    }

    int M;
    cin>>M;
    for(int i=0;i<M;i++){
        int x;
        cin>>x;
        if(x<1||x>N||gone[x]) continue;
        gone[x]=1;
        int l=L[x],r=R[x];
        if(l) R[l]=r; else head=r;
        if(r) L[r]=l;
    }

    bool first=1;
    for(int cur=head;cur;cur=R[cur]){
        if(!first) cout<<" ";
        first=false;
        cout<<cur;
    }
    cout<<"\n";
    return 0;
}