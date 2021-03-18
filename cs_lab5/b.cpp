#include <iostream>
#include <algorithm>
using namespace std;
struct node{
    int start,end,val;
    node(){start=end=val=0;}
};
node ns[5005], minHeap[5005];
int ans=0,endTime=0,n=0,current=1,size=0;
void insert(int t, node val){
    minHeap[t]=val;node tmp;
    while(t/2>0&&minHeap[t/2].end>val.end){
        tmp=minHeap[t];
        minHeap[t]=minHeap[t/2];
        minHeap[t/2]=tmp;
        t=t/2;
    }
}
node deleteMin(int num){
    node a=minHeap[1],tmp;
    minHeap[1]=minHeap[num];
    int t=1;
    while((2*t<num&&minHeap[t].end>minHeap[2*t].end)||(2*t+1<num&&minHeap[t].end>minHeap[2*t+1].end)){
        if((2*t+1<num&&minHeap[2*t].end>minHeap[2*t+1].end)){//2*t+1<num（两者都成立）关系不能省
            tmp=minHeap[2*t+1];
            minHeap[2*t+1]=minHeap[t];
            minHeap[t]=tmp;
            t=2*t+1;
        }
        else{
            tmp=minHeap[2*t];
            minHeap[2*t]=minHeap[t];
            minHeap[t]=tmp;
            t=2*t;
        }
    }
    return a;
}
int com(node a, node b){
    return a.start<b.start;
}
int check(int num){
    size=0,current=1;//重载
    for(int i=1;i<=endTime;i++){//当前时刻进行到i
        if(size>0&&minHeap[1].end<i)return 0; // 已经到了截止时间！！！不可能成立了
        while(current<=n&&ns[current].start<=i){ // == 也可
            ns[current].val=0;//清零
            insert(++size,ns[current++]);  //size!=current  !!! 会有删除操作
        }
        if(size>0){ //有可能出现！！！
            minHeap[1].val++;//最早结束的那个任务可以分配到当前时刻
            if(minHeap[1].val==num)deleteMin(size--);
        }
    }
    if(size>0)return 0;
    else return 1;
}
void find(int l,int r){
    if(l>r) return;
    int mid=(l+r)>>1; //不会爆
    if(check(mid)){
        ans=ans>mid?ans:mid;
        find(mid+1,r);
    }
    else find(l,mid-1);
}
int main(){
    scanf("%d",&n);
    int max=10005,tmp=0;
    for(int i=1;i<=n;i++){
        scanf("%d %d",&ns[i].start,&ns[i].end);
        endTime=endTime>ns[i].end?endTime:ns[i].end;// 最后的结束时间
        tmp=ns[i].end-ns[i].start+1;
        max=max<tmp?max:tmp;//每个节目可能分到的最长时间上限制
    }
    sort(ns+1,ns+n+1,com); //从小往大的start
    find(1,max);
    printf("%d\n",ans);
    return 0;
}