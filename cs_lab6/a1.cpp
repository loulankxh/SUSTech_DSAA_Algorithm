#include <iostream>
#include <cmath>
struct edge{
    int u,v,w,next;
    double logW;
    edge(){
        u=v=w=next=0;
        logW=0;
    }
};
edge es[1000005];
int head[10005],visit[10005],loca[1000015],pre[1000015];double dis[10005],min[1000015];
long long newDis[10005];
int cnt=1,size=0;long long ans=0;
int me;
void insert(int i,int u,double val){
    min[++size]=val;loca[size]=u;pre[size]=i;
    int t=size;
    while(t/2>0&&min[t/2]>min[t]){
        me=min[t];min[t]=min[t/2];min[t/2]=me;
        loca[t/2]^=loca[t];loca[t]^=loca[t/2];loca[t/2]^=loca[t];
        pre[t/2]^=pre[t];pre[t]^=pre[t/2];pre[t/2]^=pre[t];
        t=t/2;
    }
}
void deleteMin(){
    loca[1]=loca[size];pre[1]=pre[size];min[1]=min[size--];
    int t=1;
    while((2*t<=size&&min[2*t]<min[t])||(2*t<size&&min[2*t+1]<min[t])){
        if(2*t<size&&min[2*t+1]<min[2*t]){
            me=min[t];min[t]=min[2*t+1];min[2*t+1]=me;
            loca[2*t+1]^=loca[t];loca[t]^=loca[2*t+1];loca[2*t+1]^=loca[t];
            pre[2*t+1]^=pre[t];pre[t]^=pre[2*t+1];pre[2*t+1]^=pre[t];
            t=2*t+1;
        }
        else{
            me=min[t];min[t]=min[2*t];min[2*t]=me;
            loca[2*t]^=loca[t];loca[t]^=loca[2*t];loca[2*t]^=loca[t];
            pre[2*t]^=pre[t];pre[t]^=pre[2*t];pre[2*t]^=pre[t];
            t=2*t;
        }
    }
}
int tmp=0,tt=0;
void dijkstra(){
    while(size>0){
        tmp=loca[1],tt=pre[1];//点  边
        deleteMin();
        if(visit[tmp]==0){
            visit[tmp]=1;
            if(tt>0){//不是第一个点
                newDis[tmp]=newDis[es[tt].u]*es[tt].w%19260817;
            }
            for(int i=head[tmp];i!=0;i=es[i].next){
                if(visit[es[i].v]==0){//未出过堆
                    if(dis[es[i].v]==-1||dis[tmp]+es[i].logW<dis[es[i].v]){
                        dis[es[i].v]=dis[tmp]+es[i].logW;
                        insert(i,es[i].v,dis[es[i].v]);
                    }
//                    insert(i,es[i].v,dis[es[i].v]);
//出错：！！！i并不对应dis[es[i].v]的当前值
                }
            }
        }
    }
}
void add(int u,int v,int w){
    es[cnt].u=u;es[cnt].v=v;es[cnt].next=head[u];es[cnt].w=w;es[cnt].logW=log((double)w);head[u]=cnt++;
}
int main(){
    int n,m,u,v,w,max=0;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d %d %d",&u,&v,&w);
        max=max>u?max:u;
        max=max>v?max:v;
        add(u,v,w);
    }
    for(int i=0;i<=max;i++)dis[i]=-1;
    insert(0,1,0);dis[1]=0;newDis[1]=1;
    dijkstra();
    ans=newDis[n]%19260817;
    printf("%lld",ans);
    return 0;
}
