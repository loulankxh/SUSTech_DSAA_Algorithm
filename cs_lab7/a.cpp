//#include <iostream>
//#include <queue>
//typedef std::pair<int,long long> p;
//struct com{
//    bool operator() (p a,p b){
//        return b.second<a.second;
//    }
//};
//std::priority_queue<p,std::vector<p>,com> min;
//struct edge{
//    int u,v,w,next;
//    edge(){u=v=w=next=0;}
//};
//edge es[4000005];
//int cnt=1;
//int head[1000005];
//int val[1005][1005];
//int visit[1000005];
//long long dis[1000005];
//long long ans=0;
//void add(int u, int v, int w){
//    es[cnt].u=u;es[cnt].v=v;es[cnt].w=w;es[cnt].next=head[u];head[u]=cnt++;
//    es[cnt].u=v;es[cnt].v=u;es[cnt].w=w;es[cnt].next=head[v];head[v]=cnt++;
//}
//p node;int u;long long w;
//void search(){
//    while(!min.empty()){
//        node=min.top();u=node.first;w=node.second;
//        min.pop();
//        if(visit[u]==0){
//            visit[u]=1;
//            ans+=w;  // dis[u]
//            for(int i=head[u];i!=0;i=es[i].next){
//                if(visit[es[i].v]==0){
//                    if(dis[es[i].v]==-1||dis[es[i].v]>es[i].w){
//                        dis[es[i].v]=es[i].w;
//                        min.push(p(es[i].v,es[i].w));
//                    }
//                }
//            }
//        }
//    }
//}
// int main(){
//    int n,m;
//    scanf("%d%d",&n,&m);
//    for(int i=1;i<=n;i++) {
//        for (int j = 1; j <= m; j++)
//            scanf("%d", &val[i][j]);
//    }
//    int x=0,y=0;
//    for(int i=0;i<n*m;i++){
//        x=i/m+1;
//        y=i%m+1;
//        if(x<n) add(i+1,i+1+m,val[x][y]^val[x+1][y]);
//        if(y<m) add(i+1,i+2,val[x][y]^val[x][y+1]);
//    }
//    for(int i=0;i<=n*m;i++) dis[i]=-1;
//    min.push(p(1,0));
//    dis[1]=0;
//    search();
//    printf("%lld",ans);
//    return 0;
//}