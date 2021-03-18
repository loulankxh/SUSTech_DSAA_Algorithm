//#include <iostream>
//int q1[200005],q2[200005];
//int f1=0,f2=0,r1=0,r2=0,count1=0,count2=0;
//struct edge{
//    int u,v,next;
//    edge(){u=v=next=0;}
//};
//edge e[400005];//不是200005！建的双向边，而题目说的是边的个数
//int num=1;
//int head[200005];
//int visit[200005];
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
//void init(int n){//没有n 超时
//    r1=f1=r2=f2=count1=count2=0;num=1;
//    for(int i=0;i<=n;i++)head[i]=visit[i]=0;
//}
//void add(int u,int v){
//    e[num].u=u;e[num].v=v;e[num].next=head[u];head[u]=num++;
//    e[num].u=v;e[num].v=u;e[num].next=head[v];head[v]=num++;
//}
//int main(){
//    int t,n,m,u,v;
//    fastRead(t);
//    while(t--){
//        fastRead(n);fastRead(m);
//        init(n);
//        for(int i=1;i<=m;i++){
//            fastRead(u);fastRead(v);
//            add(u,v);
//        }
//        q1[r1++]=1;count1++;visit[1]=1;
//        while(f1<r1||f2<r2){
//            if(f1<r1){
//                while(f1<r1){
//                    for(int i=head[q1[f1++]];i!=0;i=e[i].next){
//                        if(!visit[e[i].v]){
//                            visit[e[i].v]=1;
//                            q2[r2++]=e[i].v;
//                            count2++;
//                        }
//                    }
//                }
//            }
//            else{//f2<r2
//                while(f2<r2){
//                    for(int i=head[q2[f2++]];i!=0;i=e[i].next){
//                        if(!visit[e[i].v]){
//                            visit[e[i].v]=1;
//                            q1[r1++]=e[i].v;
//                            count1++;
//                        }
//                    }
//                }
//            }
//        }
//        if(count1<=count2){
//            printf("%d\n",count1);
//            for(int i=0;i<r1;i++)printf("%d ",q1[i]);
//            printf("\n");
//        }
//        else{
//            printf("%d\n",count2);
//            for(int i=0;i<r2;i++)printf("%d ",q2[i]);
//            printf("\n");
//        }
//    }
//    return 0;
//}