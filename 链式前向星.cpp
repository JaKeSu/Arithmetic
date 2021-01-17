#include<iostream>
#include<stdio.h>
#define max_len 5000
using namespace std;
struct edge{
    int to;//记录当前边的终点
    int next;// 记录与当前边拥有相同起点的上一条边
}edge[max_len];//链式前向星结构表
int cnt = 1;//计数索引
int head[max_len];//head[i]表示最近一次输入的以i为起点的边在edge数组中的下标
int add(int from,int to){//将起点为from 终点为to的边加入到edge表中
    edge[cnt].to = to;
    edge[cnt].next = head[from];
    head[from] = cnt++;
}
bool vis[max_len];//访问数组
int dfs(int x){
    vis[x] = true;
    printf("%d->",x);
    for(int i=head[x];i!=0;i=edge[i].next){
        if(!vis[edge[i].to]){
            dfs(edge[i].to);
        }
    }
}
int main(){
    for(int i=0;i<max_len;i++){
        head[i] = 0;
    }
    int n,a,b;
    cin>>n;
    while(n--){
        cin>>a>>b;
        add(a,b);
    }
    for(int i=0;i<10;i++){
        printf("head[%d] = %d\t",i,head[i]);
        printf("edge[%d].to = %d\t",i,edge[i].to);
        printf("edge[%d].next = %d\t\n",i,edge[i].next);
    }
    dfs(1);
}
