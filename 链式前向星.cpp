#include<iostream>
#include<stdio.h>
#define max_len 5000
using namespace std;
struct edge{
    int to;//��¼��ǰ�ߵ��յ�
    int next;// ��¼�뵱ǰ��ӵ����ͬ������һ����
}edge[max_len];//��ʽǰ���ǽṹ��
int cnt = 1;//��������
int head[max_len];//head[i]��ʾ���һ���������iΪ���ı���edge�����е��±�
int add(int from,int to){//�����Ϊfrom �յ�Ϊto�ı߼��뵽edge����
    edge[cnt].to = to;
    edge[cnt].next = head[from];
    head[from] = cnt++;
}
bool vis[max_len];//��������
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
