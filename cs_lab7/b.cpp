#include <iostream>
#include <queue>
typedef std::pair<int,long long> p;
struct com{
    bool operator() (p a,p b){
        return b.second<a.second;
    }
};
std::priority_queue<p,std::vector<p>,com> min;
struct edge{
    int u,v,next;
    long long w;
    edge(){
        u=v=v=next=0;
        w=0;
    }
};
edge es[4000005];
int head[2005],visit[2005];
long long dis[2005];
int cnt=1,n=0;
long long ans=0;
void add(int u,int v,long long w){
    es[cnt].u=u,es[cnt].v=v;es[cnt].w=w;es[cnt].next=head[u];head[u]=cnt++;
    es[cnt].u=v,es[cnt].v=u;es[cnt].w=w;es[cnt].next=head[v];head[v]=cnt++;
}
p node;int u;long long w;
void search(){
    while(!min.empty()){
        node=min.top();u=node.first;w=node.second;
        min.pop();
        if(visit[u]==0){
            visit[u]=1;
            ans+=w;  // dis[u]
            for(int i=head[u];i!=0;i=es[i].next){
                if(visit[es[i].v]==0){
                    if(dis[es[i].v]==-1||dis[es[i].v]>es[i].w){
                        dis[es[i].v]=es[i].w;
                        min.push(p(es[i].v,es[i].w));
                    }
                }
            }
        }
    }
}
int main(){
    scanf("%d",&n);
    long long w=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i+1;j++){
            scanf("%lld",&w);
            add(i,j+i,w);//j+i-1+1
        }
    }
    for(int i=1;i<=n+1;i++)dis[i]=-1;
    min.push(p(1,0));
    dis[1]=0;
    search();
    printf("%lld",ans);
    return 0;
}