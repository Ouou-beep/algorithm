//淘汰赛，有2^n个国家参赛(n<=7)，输入n的值以及每个国家的实力值，输出亚军的编号
#include<iostream>
using namespace std;

int n;
int value[1<<8];
int winner[1<<8];

void dfs(int x){
    if(x>=(1<<n)) return;
    dfs(2*x);
    dfs(2*x+1);
    if(value[2*x]>value[2*x+1]){
        value[x]=value[2*x];
        winner[x]=winner[2*x];
    }else{
        value[x]=value[2*x+1];
        winner[x]=winner[2*x+1];
    }
}

int main(){
    cin>>n;
    for(int i=0;i<(1<<n);i++){
        cin>>value[(1<<n)+i];
        winner[(1<<n)+i]=i+1;
    }
    dfs(1);
    int num=(value[2]>value[3]?winner[3]:winner[2]);
    cout<<num;
    return 0;
}