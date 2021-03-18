//#include <iostream>
//struct edge{
//    int u,v,next,weight;
//    edge(){u=v=next=0;}
//};
//int visit[50005];edge es[200005];int head[50005];int maxH[100005];int c[50005];int loca[50005];int dis[50005];
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
//    maxH[++size]=val;loca[size]=u;
//    int t=size;
//    while(t/2>0&&maxH[t/2]<maxH[t]){
//        maxH[t/2]^=maxH[t];maxH[t]^=maxH[t/2];maxH[t/2]^=maxH[t];
//        loca[t/2]^=loca[t];loca[t]^=loca[t/2];loca[t/2]^=loca[t];
//        t=t/2;
//    }
//}
//int deleteMax(){
//    int tmp=loca[1];
//    loca[1]=loca[size];maxH[1]=maxH[size--];
//    int t=1;
//    while((2*t<=size&&maxH[2*t]>maxH[t])||(2*t<size&&maxH[2*t+1]>maxH[t])){
//        if(2*t<size&&maxH[2*t+1]>maxH[2*t]){
//            maxH[2*t+1]^=maxH[t];maxH[t]^=maxH[2*t+1];maxH[2*t+1]^=maxH[t];
//            loca[2*t+1]^=loca[t];loca[t]^=loca[2*t+1];loca[2*t+1]^=loca[t];
//            t=2*t+1;
//        }
//        else{
//            maxH[2*t]^=maxH[t];maxH[t]^=maxH[2*t];maxH[2*t]^=maxH[t];
//            loca[2*t]^=loca[t];loca[t]^=loca[2*t];loca[2*t]^=loca[t];
//            t=2*t;
//        }
//    }
//    return tmp;
//}
//int main(){
//    int n,m;
//    fastRead(n);fastRead(m);
//    int num=0,max=0,u=0,v=0,tmp=0;
//    for(int i=1;i<=n;i++){
//        for(int j=1;j<=m;j++){
//            fastRead(c[++num]);//tmp:序号
//            if(j>1){
//                tmp=c[num]*c[num-1];
//                if(tmp>max){
//                    u=num;v=num-1;
//                    max=tmp;
//                }
//                add(num,num-1,tmp);
//            }
//            if(i>1){
//                tmp=c[num]*c[num-m];
//                if(tmp>max){
//                    u=num;v=num-m;
//                    max=tmp;
//                }
//                add(num,num-m,tmp);
//            }
//        }
//    }
//    visit[u]=1;visit[v]=1;ans+=max;
//    for(int i=head[u];i!=0;i=es[i].next){
//        if(visit[es[i].v]==0){
//            if(dis[es[i].v]==0||dis[es[i].v]<es[i].weight)dis[es[i].v]=es[i].weight;
//            insert(es[i].v,dis[es[i].v]);
//        }
//    }
//    for(int i=head[v];i!=0;i=es[i].next){
//        if(visit[es[i].v]==0){
//            if(dis[es[i].v]==0||dis[es[i].v]<es[i].weight)dis[es[i].v]=es[i].weight;
//            insert(es[i].v,dis[es[i].v]);
//        }
//    }
//    int dot=0;
//    while(size>0){
//        dot=deleteMax();
//        if(visit[dot]==0){
//            visit[dot]=1;
//            ans+=dis[dot];
//            for(int i=head[dot];i!=0;i=es[i].next){
//                if(visit[es[i].v]==0){
//                    if(dis[es[i].v]==0||dis[es[i].v]<es[i].weight)dis[es[i].v]=es[i].weight;
//                    insert(es[i].v,dis[es[i].v]);
//                }
//            }
//        }
//    }
//    printf("%lld",ans);
//    return 0;
//}