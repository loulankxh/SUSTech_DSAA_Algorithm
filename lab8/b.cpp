//#include <iostream>
//struct node{
//    int x,y,s;
//    node(){x=y=s=0;}
//};
//struct edge{
//    int next,u,v;
//    edge(){next=u=v=0;}
//};
//node dot[1009];int visit[1009];
//edge es[1009000];
//int q1[1009],q2[1009];
//int f1=0,f2=0,r1=0,r2=0;
//int head[1009];//==0表示不存在
//int num=1,flag=1;
//void init(){
//    num=1;flag=1;f1=f2=r1=r2=0;
//    for(int i=0;i<1009;i++){
//        head[i]=visit[i]=0;
//    }
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
//void add(int u, int v){
//    int t1=dot[u].s+dot[v].s,t2=dot[u].x-dot[v].x,t3=dot[u].y-dot[v].y;
//    if((v<=1000&&(long long)t1*t1<(long long)t2*t2+t3*t3)||(v==1001&&t3>t1)||(v==1002&&t2>t1)||(v==1003&&-t3>t1)||(v==1004&&-t2>t1));//相离//long long
//    else{
//        es[num].u=u;es[num].v=v;es[num].next=head[u];head[u]=num++;
//        es[num].u=v;es[num].v=u;es[num].next=head[v];head[v]=num++;
//    }
//}
//void judge1001(){
//    q1[r1++]=1001;visit[1001]=1;
//    while(f1<r1){
//        for(int i=head[q1[f1++]];i!=0;i=es[i].next){//不是++f1!!!
//            if(es[i].v!=1002&&es[i].v!=1003){
//                if(!visit[es[i].v]){
//                    q1[r1++]=es[i].v;//不是i.v!区分点与边
//                    visit[es[i].v]=1;
//                }
//            }
//            else {
//                flag=0;
//                return;
//            }
//        }
//    }
//}
//void judge1004(){
//    q2[r2++]=1004;visit[1004]=1;
//    while(f2<r2){
//        for(int i=head[q2[f2++]];i!=0;i=es[i].next){
//            if(es[i].v!=1002&&es[i].v!=1003){
//                if(!visit[es[i].v]){
//                    q2[r2++]=es[i].v;
//                    visit[es[i].v]=1;
//                }
//            }
//            else {
//                flag=0;
//                return;
//            }
//        }
//    }
//}
//int main(){
//    int t,n,m,k;
//    fastRead(t);
//    while(t--){
//        init();
//        fastRead(n);fastRead(m);fastRead(k);
//        dot[1003].y=m;dot[1004].x=n;
//        for(int i=1;i<=k;i++){
//            fastRead(dot[i].x);fastRead(dot[i].y);fastRead(dot[i].s);
//        }
//        for(int i=1;i<=k;i++){
//            add(i,1001);add(i,1002);add(i,1003);add(i,1004);
//            for(int j=i+1;j<=k;j++){
//                add(i,j);
//            }
//        }
//        judge1001();
//        if(flag)judge1004();
//        if(flag)printf("Yes\n");
//        else printf("No\n");
//    }
//    return 0;
//}