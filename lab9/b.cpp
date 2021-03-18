//#include <iostream>
//struct edge{
//    int u,v,next,weight;
//    edge(){u=v=next=weight=0;}
//};
//edge es[20005];int head[1005];int heap[10005];int loca[10005];int visit[1005];int dis[1005];
//int num=1,size=0;long long ans=0;
//void fastRead(int& in){
//    in=0;
//    char ch=getchar();
//    while(ch<'0'||ch>'9')ch=getchar();
//    while(ch>='0'&&ch<='9')
//    {
//        in*=10;
//        in+=ch-'0';
//        ch=getchar();
//    }
//}
//void add(int u,int v,int w){
//    es[num].u=u;es[num].v=v;es[num].weight=w;es[num].next=head[u];head[u]=num++;
//    es[num].u=v;es[num].v=u;es[num].weight=w;es[num].next=head[v];head[v]=num++;
//}
//void insert(int u,int val){
//    heap[++size]=val;loca[size]=u;
//    int t=size;
//    while(t/2>0&&heap[t/2]>heap[t]){
//        heap[t/2]^=heap[t];heap[t]^=heap[t/2];heap[t/2]^=heap[t];
//        loca[t/2]^=loca[t];loca[t]^=loca[t/2];loca[t/2]^=loca[t];
//        t=t/2;
//    }
//}
//int deleteMin(){
//    int tmp=loca[1];
//    loca[1]=loca[size];heap[1]=heap[size--];
//    int t=1;
//    while((2*t<=size&&heap[2*t]<heap[t])||(2*t<size&&heap[2*t+1]<heap[t])){
//        if(2*t<size&&heap[2*t+1]<heap[2*t]){
//            heap[2*t+1]^=heap[t];heap[t]^=heap[2*t+1];heap[2*t+1]^=heap[t];
//            loca[2*t+1]^=loca[t];loca[t]^=loca[2*t+1];loca[2*t+1]^=loca[t];
//            t=2*t+1;
//        }
//        else{
//            heap[2*t]^=heap[t];heap[t]^=heap[2*t];heap[2*t]^=heap[t];
//            loca[2*t]^=loca[t];loca[t]^=loca[2*t];loca[2*t]^=loca[t];
//            t=2*t;
//        }
//    }
//    return tmp;
//}
//int main(){
//    int n,m,u,v,w,min=1000005,u1,v1;
//    fastRead(n);fastRead(m);
//    for(int i=1;i<=m;i++){
//        fastRead(u);fastRead(v);fastRead(w);
//        add(u,v,w);
//        if(min>w){
//            min=w;
//            u1=u;v1=v;
//        }
//    }
//    visit[u1]=1;visit[v1]=1;ans+=min;
//    for(int i=head[u1];i!=0;i=es[i].next){
//        if(visit[es[i].v]==0){
//            if(dis[es[i].v]==0||dis[es[i].v]>es[i].weight)dis[es[i].v]=es[i].weight;
//            insert(es[i].v,dis[es[i].v]);
//        }
//    }
//    for(int i=head[v1];i!=0;i=es[i].next){
//        if(visit[es[i].v]==0){
//            if(dis[es[i].v]==0||dis[es[i].v]>es[i].weight)dis[es[i].v]=es[i].weight;
//            insert(es[i].v,dis[es[i].v]);
//        }
//    }
//    int tmp=0;
//    while(size>0){
//        tmp=deleteMin();
//        if(visit[tmp]==0){
//            visit[tmp]=1;
//            ans+=dis[tmp];
//            for(int i=head[tmp];i!=0;i=es[i].next){
//                if(visit[es[i].v]==0){
//                    if(dis[es[i].v]==0||dis[es[i].v]>es[i].weight)dis[es[i].v]=es[i].weight;
//                    insert(es[i].v,dis[es[i].v]);
//                }
//            }
//        }
//    }
//    printf("%lld",ans);
//    return 0;
//}