#include<stdio.h>
#define max_len 10010
int tree[max_len];
int build_tree(int arr[],int tree[],int node,int start,int end){
    if(start == end){
        tree[node] = arr[start];
    }else{
        int mid = (start + end)/2;
        int left_node =  node * 2 + 1;
        int right_node = node * 2 + 2;
        build_tree(arr,tree,left_node,start,mid);
        build_tree(arr,tree,right_node,mid+1,end);
        tree[node] = tree [left_node] + tree [right_node];
    }

}
int update_tree(int arr[], int tree[], int node, int start, int end, int idx, int val){
    if(start == end){
        arr[idx] = val;
        tree[node] = val;
    }else{
        int mid = (start + end)/2;
        int left_node = node * 2 + 1;
        int right_node = node * 2 + 2;
        if(idx < mid){
            update_tree(arr,tree,left_node, start, mid, idx, val);
        }else{
            update_tree(arr,tree,right_node, mid+1, end, idx, val);
        }
        tree[node] = tree[left_node] + tree[right_node];
    }
}

int query(int arr[], int tree[], int node, int start, int end, int L, int R){
    if(R<start||L>end) return 0;
    else if(L<= start && end<= R) return tree[node];
    else{
        int mid = (start + end)/2;
        int left_node = node * 2 + 1;
        int right_node = node * 2 + 2;
        int left_sum = query(arr, tree, left_node, start, mid, L, R);
        int right_sum = query(arr, tree, right_node, mid+1, end, L, R);
        return left_sum+right_sum;
    }

}
int main(){
    int arr[] = { 1, 3, 5, 7, 9, 11 };
    int size = 6;
    build_tree (arr,tree,0,0,size-1);
    printf("\n");
    for(int i = 0;i<15; i++){
        printf("%d ",tree[i]);
    }
    printf("\n");
    update_tree(arr,tree,0,0,size-1,0,2);
    for(int i = 0;i<15; i++){
        printf("tree[%d] = %d\n",i,tree[i]);
    }
    printf("sum of 2 - 5 is %d",query(arr, tree, 0, 0, size-1, 2 ,5));

}
