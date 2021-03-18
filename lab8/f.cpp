//#include <iostream>
//struct node{
//    int a,b,c,val;
//    node(){a=b=c=val=0;}
//};
//struct edge{
//    int u,v,next;
//    edge(){u=v=next=0;}
//};
//node ns[2005];int head[2005];edge es[4000005];int queue[2005];int deg[2005];
//int num=1,f=0,r=0;
//void init(int n){
//    num=1,f=r=0;
//    for(int i=0;i<=n;i++)deg[i]=head[i]=0;
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
//void add(int u,int v){
//    es[num].v=v;es[num].u=u;es[num].next=head[u];head[u]=num++;
//}
//int main(){
//    int t,n,a,b,c;
//    fastRead(t);
//    while(t--){
//        fastRead(n);
//        init(n);
//        for(int i=1;i<=n;i++){
//            fastRead(a);fastRead(b);fastRead(c);
//            ns[i].a=a;ns[i].b=b;ns[i].c=c;ns[i].val=c;
//        }
//        for(int i=1;i<=n;i++){
//            for(int j=1;j<=n;j++){//j=i+1
//                if((ns[i].a<ns[j].a&&ns[i].b<ns[j].b)||(ns[i].a<ns[j].b&&ns[i].b<ns[j].a)) {
//                    add(i,j);
//                    deg[j]++;
//                }
//            }
//        }
//        for(int i=1;i<=n;i++){
//            if(deg[i]==0)queue[r++]=i;//doesn't have fa
//        }
//        int u=0,tmp=0;
//        while(f<r){
//            u=queue[f++];
//            for(int i=head[u];i!=0;i=es[i].next){
//                deg[es[i].v]--;
//                tmp=ns[es[i].v].c+ns[u].val;// not val + val
//                if(ns[es[i].v].val<tmp)ns[es[i].v].val=tmp;
//                if(deg[es[i].v]==0)queue[r++]=es[i].v;//has child
//            }
//        }
//        int ans=0;
//        for(int i=1;i<=n;i++){
//            if(ns[i].val>ans)ans=ns[i].val;
//        }
//        printf("%d\n",ans);
//    }
//    return 0;
//}