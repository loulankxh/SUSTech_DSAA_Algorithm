//#include <iostream>
//int head[600005];int visit[600005];
//struct edge{
//    int u,v,next;
//    edge(){u=v=next=0;}
//};
//int num=1,count=1,ans=-1;
//edge e[800005];
//void add(int u,int v){
//    e[num].u=u;e[num].v=v;e[num].next=head[u];head[u]=num++;
//}
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
////void find(int d,int x,int n){//相当于把图都便利了一遍  DFS
////    visit[x]=1;
////    for(int i=head[x];i!=0;i=e[i].next){
////        if(e[i].v==n){
////            ans=ans>d?d:ans;
////            break;
////        }
////        if(!visit[e[i].v])find(d+1,e[i].v,n);
////    }
////    visit[x]=0;//对于另一条路径而言这是可以访问到的
////}
//int queue[600005],deep[600005];int front=0,rear=0;
//void find(int n){//BFS,不要递归
//    queue[rear++]=1;visit[1]=1;deep[1]=0;int d=0;
//    while(front<rear){
//        d=deep[queue[front]];
//        for(int i=head[queue[front++]];i!=0;i=e[i].next){
//            if(e[i].v==n){
//                ans=d+1;
//                return;
//            }
//            else if(visit[e[i].v]==0){
//                queue[rear++]=e[i].v;visit[e[i].v]=1;deep[e[i].v]=d+1;
//            }
//        }
//    }
//    return;
//}
//int main(){
//    int n,m,u,v,w;
//    fastRead(n);fastRead(m);
//    for(int i=1;i<=m;i++){
//        fastRead(u);fastRead(v);fastRead(w);
//        if(w==2){
//            add(u,(n+count));
//            add((n+count++),v);
//        }
//        else add(u,v);
//    }
//    find(n);
//    printf("%d",ans);
//    return 0;
//}