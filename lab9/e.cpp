//#include <iostream>
//struct edge{
//    int u,v,next,weight;
//    edge(){u=v=next=weight=0;}
//};
//edge es[100005];int head[50005];long long dis[11][50005];int loca[50005];long long minH[50005];int visit[50005];
//int num=1,size=0;
//void add(int u,int v,int w){
//    es[num].u=u;es[num].v=v;es[num].weight=w;es[num].next=head[u];head[u]=num++;
//}
//void insert(int u,long long val){
//    minH[++size]=val;loca[size]=u;
//    int t=size;
//    while(t/2>0&&minH[t/2]>minH[t]){
//        minH[t/2]^=minH[t];minH[t]^=minH[t/2];minH[t/2]^=minH[t];
//        loca[t/2]^=loca[t];loca[t]^=loca[t/2];loca[t/2]^=loca[t];
//        t=t/2;
//    }
//}
//int deleteMin(){
//    int tmp=loca[1];
//    loca[1]=loca[size];minH[1]=minH[size--];
//    int t=1;
//    while(((long long)2*t<=size&&minH[2*t]<minH[t])||((long long)2*t<size&&minH[2*t+1]<minH[t])){
//        if((long long)2*t<size&&minH[2*t+1]<minH[2*t]){
//            minH[2*t+1]^=minH[t];minH[t]^=minH[2*t+1];minH[2*t+1]^=minH[t];
//            loca[2*t+1]^=loca[t];loca[t]^=loca[2*t+1];loca[2*t+1]^=loca[t];
//            t=2*t+1;
//        }
//        else{
//            minH[2*t]^=minH[t];minH[t]^=minH[2*t];minH[2*t]^=minH[t];
//            loca[2*t]^=loca[t];loca[t]^=loca[2*t];loca[2*t]^=loca[t];
//            t=2*t;
//        }
//    }
//    return tmp;
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
//void init(int n){
//    for(int i=1;i<=n;i++){
//        visit[i]=0;
//    }
//}
//void find(int k){
//    int tmp=0;long long tt=0;
//    while(size>0){
//        tmp=deleteMin();
//        if(visit[tmp]==0){
//            visit[tmp]=1;
//            for(int i=head[tmp];i!=0;i=es[i].next){
//                if(visit[es[i].v]==0){//未出过堆
//                    if(k==0&&es[i].weight==0)continue;//k==0&&es[i].weight==0要讨论出来
//                    else if(k>0&&es[i].weight==0)tt=dis[k-1][tmp];
//                    else tt=dis[k][tmp]+es[i].weight;
//                    if(dis[k][es[i].v]==-1||tt<dis[k][es[i].v])dis[k][es[i].v]=tt;//不能用==0！！！
//                    insert(es[i].v,dis[k][es[i].v]);
//                }
//            }
//        }
//    }
//}
//int main(){
//    int n,m,p,k,u,v,w,s,t;
//    fastRead(n);fastRead(m);fastRead(p);fastRead(k);
//    for(int i=1;i<=m;i++){
//        fastRead(u);fastRead(v);fastRead(w);
//        add(u,v,w);
//    }
//    for(int i=1;i<=p;i++){
//        fastRead(u);fastRead(v);
//        add(u,v,0);
//    }
//    fastRead(s);fastRead(t);
//    for(int i=0;i<=k;i++){
//        for(int j=1;j<=n;j++)dis[i][j]=-1;
//        init(n);
//        insert(s,0);dis[i][s]=0;
//        find(i);
//    }
//    long long min=-1;
//    for (int i=0;i<=k;i++){
//        if(min==-1||(dis[k][t]>-1&&min>dis[k][t]))min=dis[k][t];
//    }
//    printf("%lld",min);
//    return 0;
//}