//#include <iostream>
//struct edge{
//    int u,v,w,next;
//    edge(){u=v=w=next=0;}
//};
//edge es[100005];
//int head[10005],loca[100005],visit[10005],a[10005],b[10005];
//long long dis[10005],min[100005];
//int cnt=1,size=0;long long ans=0;
//void insert(int u,long long val){
//    min[++size]=val;loca[size]=u;
//    int t=size;
//    while(t/2>0&&min[t/2]>min[t]){
//        min[t/2]^=min[t];min[t]^=min[t/2];min[t/2]^=min[t];
//        loca[t/2]^=loca[t];loca[t]^=loca[t/2];loca[t/2]^=loca[t];
//        t=t/2;
//    }
//}
//void deleteMin(){
//    loca[1]=loca[size];min[1]=min[size--];
//    int t=1;
//    while((2*t<=size&&min[2*t]<min[t])||(2*t<size&&min[2*t+1]<min[t])){
//        if(2*t<size&&min[2*t+1]<min[2*t]){
//            min[2*t+1]^=min[t];min[t]^=min[2*t+1];min[2*t+1]^=min[t];
//            loca[2*t+1]^=loca[t];loca[t]^=loca[2*t+1];loca[2*t+1]^=loca[t];
//            t=2*t+1;
//        }
//        else{
//            min[2*t]^=min[t];min[t]^=min[2*t];min[2*t]^=min[t];
//            loca[2*t]^=loca[t];loca[t]^=loca[2*t];loca[2*t]^=loca[t];
//            t=2*t;
//        }
//    }
//}
//int tmp=0,ai=0,bi=0;
//long long ti=0,me=0;
//void dijkstra(){
//    while(size>0){
//        tmp=loca[1];//点
//        deleteMin();
//        if(visit[tmp]==0){//未出过堆
//            visit[tmp]=1;
//            for(int i=head[tmp];i!=0;i=es[i].next){
//                if(visit[es[i].v]==0){//未出过堆
//                    me=dis[tmp]+es[i].w;ai=a[es[i].v];bi=b[es[i].v];
//                    ti=(me)%(ai+bi);
//                    if(ti<(long long)ai)ti=(ai-ti)+me;
//                    else ti=me;
//                    if(dis[es[i].v]==-1||ti<dis[es[i].v]){
//                        dis[es[i].v]=ti;
//                        insert(es[i].v,dis[es[i].v]);
//                    }
//                }
//            }
//        }
//    }
//}
//void add(int u,int v,int w){
//    es[cnt].u=u;es[cnt].v=v;es[cnt].w=w;es[cnt].next=head[u];head[u]=cnt++;
//}
//int main(){
//    int n,m,u,v,w;
//    scanf("%d%d",&n,&m);
//    for(int i=0;i<m;i++){
//        scanf("%d%d%d",&u,&v,&w);
//        add(u,v,w);
//    }
//    for(int i=1;i<=n;i++)scanf("%d%d",&a[i],&b[i]);
//    for(int i=0;i<=n;i++)dis[i]=-1;
//    insert(1,0);dis[1]=0;
//    dijkstra();
//    ans=dis[n];
//    printf("%lld",ans);
//    return 0;
//}