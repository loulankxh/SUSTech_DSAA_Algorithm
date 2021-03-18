//#include <iostream>
//#include <cmath>
//#include <queue>
//typedef std:: pair<int,double> ele;
//struct edge{
//    int u,v,next;
//    double w;
//    edge(){
//        u=v=next=0;
//        w=0;
//    }
//};
//edge es[1000005];
//int head[10005],visit[10005];double distance[10005];
//int cnt=1;long long ans=0;
//struct com{
//    bool operator()(const ele p1,const ele p2){
//        return p1.second>p2.second;//小值优先
//    }
//};
//std::priority_queue <ele,std::vector<ele>,com> dis;
//void dijkstra(int u){
//    visit[u]=1;
//    int v;ele tmp;
//    for(int i=head[u];i!=0;i=es[i].next){
//        v=es[i].v;
//        if(visit[v]==0){
//            if(distance[v]==0||distance[v]>distance[u]+es[cnt].w)
//                distance[v]=distance[u]+es[cnt].w;
//            dis.push(ele(v,distance[v]));
//        }
//    }
//    if(dis.size()>0){
//        tmp=dis.top();
//        dis.pop();
//        if(visit[tmp.first])return;
//        else dijkstra(tmp.first);
//    }
//}
//void add(int u,int v,int w){
//    es[cnt].u=u;es[cnt].v=v;es[cnt].next=head[u];es[cnt].w=log((double)w);head[u]=cnt++;
//}
//void init(int n){
//    for(int i=0;i<=n;i++){
//        distance[i]=head[i]=visit[i]=0;
//    }
//}
//int main(){
//    int n,m,u,v,w;
//    scanf("%d %d",&n,&m);
//    init(n);
//    for(int i=0;i<m;i++){
//        scanf("%d %d %d",&u,&v,&w);
//        add(u,v,w);
//    }
//    dis.push(ele(1,0));
//    distance[1]=0;
//    printf("%d %d %lf",head[10],visit[10],distance[10]);
//    dijkstra(1);
//    ans=(long long)exp(distance[n]);
//    ans%=19260817;
//    printf("%lld",ans);
//    return 0;
//}
//////  ？？？ 为什么debug没用？？？